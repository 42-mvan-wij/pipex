# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mvan-wij <mvan-wij@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/06/17 20:42:03 by mvan-wij      #+#    #+#                  #
#    Updated: 2021/06/21 16:13:29 by mvan-wij      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = pipex
LIBFT = libft/libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
ifdef DEBUG
CFLAGS += -g
endif

LIBS = -L$(dir $(LIBFT)) -lft
SOURCES = src/pipex.c src/utils.c src/cmd.c src/cmd_args.c src/cmd_args2.c

ifdef BONUS
SOURCES +=
CFLAGS  +=
LIBS    +=
endif

SRCDIR = src
OBJDIR = obj

OBJECTS = $(patsubst $(SRCDIR)/%,$(OBJDIR)/%,$(SOURCES:c=o))

.PHONY = all clean fclean re debug bonus $(LIBFT)
.PHONY: $(PHONY)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBS) -o $(NAME)

	@#cp $(LIBFT) $(NAME)
	@#ar -crs $(NAME) $(OBJECTS)

bonus:
	$(MAKE) BONUS=1

debug:
	$(MAKE) DEBUG=1

$(LIBFT):
ifdef DEBUG
	$(MAKE) -C $(dir $(LIBFT)) debug bonus
else
	$(MAKE) -C $(dir $(LIBFT)) bonus
endif

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(dir $(LIBFT)) clean
	rm -f $(OBJECTS)

fclean: clean
	$(MAKE) -C $(dir $(LIBFT)) fclean
	rm -rf $(OBJDIR)
	rm -f $(NAME) $(TEST_NAME)

re: fclean all





test_pipex_cmd: all
	@./$(NAME) Makefile "lsq -l" cat outfile \
	&& echo ------------- \
	&& cat outfile \
	&& rm outfile

test_zsh_cmd:
	@zsh -c "< Makefile lsq -l | cat > outfile" \
	&& echo ------------- \
	&& cat outfile \
	&& rm outfile

test_pipex_cmd_fake: all
	@./$(NAME) non_existent_file "lsq -l" cat outfile \
	&& echo ------------- \
	&& cat outfile \
	&& rm outfile

test_zsh_cmd_fake:
	@zsh -c "< non_existent_file lsq -l | cat > outfile" \
	&& echo ------------- \
	&& cat outfile \
	&& rm outfile

test_pipex_fake: all
	@./$(NAME) non_existent_file "ls -l" cat outfile \
	&& echo ------------- \
	&& cat outfile \
	&& rm outfile

test_zsh_fake:
	@zsh -c "< non_existent_file ls -l | cat > outfile" \
	&& echo ------------- \
	&& cat outfile \
	&& rm outfile

test_pipex_real: all
	@./$(NAME) Makefile "ls -l" cat outfile \
	&& echo ------------- \
	&& cat outfile \
	&& rm outfile

test_zsh_real:
	@zsh -c "< Makefile ls -l | cat > outfile" \
	&& echo ------------- \
	&& cat outfile \
	&& rm outfile

test_pipex_fake_w_outfile: all
	@echo "content" > outfile
	@./$(NAME) non_existent_file "ls -l" cat outfile \
	&& echo ------------- \
	&& cat outfile \
	&& rm outfile

test_zsh_fake_w_outfile:
	@echo "content" > outfile
	@zsh -c "< non_existent_file ls -l | cat > outfile" \
	&& echo ------------- \
	&& cat outfile \
	&& rm outfile

test_pipex_real_w_outfile: all
	@echo "content" > outfile
	@./$(NAME) Makefile "ls -l" cat outfile \
	&& echo ------------- \
	&& cat outfile \
	&& rm outfile

test_zsh_real_w_outfile:
	@echo "content" > outfile
	@zsh -c "< Makefile ls -l | cat > outfile" \
	&& echo ------------- \
	&& cat outfile \
	&& rm outfile

# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mvan-wij <mvan-wij@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/06/17 20:42:03 by mvan-wij      #+#    #+#                  #
#    Updated: 2021/06/22 16:46:02 by mvan-wij      ########   odam.nl          #
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
HEADERS = src/pipex.h libft/libft.h
INCLUDES = $(addprefix -I,$(dir $(HEADERS)))
SOURCES = src/pipex.c src/utils.c src/cmd.c src/cmd_args.c src/cmd_args2.c

ifdef BONUS
SOURCES +=
CFLAGS  +=
LIBS    +=
endif

SRCDIR = src
OBJDIR = obj

OBJECTS = $(patsubst $(SRCDIR)/%,$(OBJDIR)/%,$(SOURCES:c=o))

.PHONY: all clean fclean re debug bonus

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBS) -o $(NAME)

	@#cp $(LIBFT) $(NAME)
	@#ar -crs $(NAME) $(OBJECTS)

bonus:
	$(MAKE) BONUS=1

debug: fclean
	$(MAKE) DEBUG=1

$(LIBFT): $(addprefix $(dir $(LIBFT)),$(shell $(MAKE) -s -C $(dir $(LIBFT)) sources))
ifdef DEBUG
	$(MAKE) -C $(dir $(LIBFT)) debug
else
	$(MAKE) -C $(dir $(LIBFT))
endif

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADERS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) -C $(dir $(LIBFT)) clean
	rm -f $(OBJECTS)

fclean: clean
	$(MAKE) -C $(dir $(LIBFT)) fclean
	rm -rf $(OBJDIR)
	rm -f $(NAME) $(TEST_NAME)

re: fclean all

# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mvan-wij <mvan-wij@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/10/27 13:16:39 by mvan-wij      #+#    #+#                  #
#    Updated: 2021/11/30 15:42:09 by mvan-wij      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

PROJECT			= libft
NAME			= libft.a

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
ifndef NO_SANITIZE
CFLAGS			+= -fsanitize=address
endif
ifdef DEBUG
CFLAGS 			+= -g
endif
LIBS			=
HEADERS			= libft.h
INCLUDES		= $(addprefix -I,$(dir $(HEADERS)))

include			sources.mk
include			colours.mk
RULE_SPACING = 6
PROJECT_SPACING = 11

ifdef BONUS
	SOURCES		+=
	CFLAGS		+=
	LIBS		+=
endif

SRCDIR			= src
OBJDIR			= obj

OBJECTS			= $(patsubst $(SRCDIR)/%,$(OBJDIR)/%,$(SOURCES:c=o))

.PHONY: all clean fclean re debug sources

all: $(NAME)

$(NAME): $(OBJECTS)
ifndef SILENT
	@printf "$(CYAN_FG)%-$(PROJECT_SPACING)s$(RESET_COLOR) $(GREEN_FG)%-$(RULE_SPACING)s$(RESET_COLOR) : $(CLEAR_REST_OF_LINE)" "[$(PROJECT)]" "make"
	ar -cr $(NAME) $(OBJECTS)
else
	@ar -cr $(NAME) $(OBJECTS)
	@printf "$(CYAN_FG)%-$(PROJECT_SPACING)s$(RESET_COLOR) $(GREEN_FG)%-$(RULE_SPACING)s$(RESET_COLOR) : $(BLUE_FG)$(NAME)$(RESET_COLOR) created$(CLEAR_REST_OF_LINE)\n" "[$(PROJECT)]" "make"
endif

debug:
	$(MAKE) DEBUG=1

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADERS)
	@mkdir -p $(@D)
	@printf "$(CYAN_FG)%-$(PROJECT_SPACING)s$(RESET_COLOR) $(GREEN_FG)%-$(RULE_SPACING)s$(RESET_COLOR) : " "[$(PROJECT)]" "make"
	@printf "$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@$(CLEAR_REST_OF_LINE)\r"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@printf "$(CYAN_FG)%-$(PROJECT_SPACING)s$(RESET_COLOR) $(GREEN_FG)%-$(RULE_SPACING)s$(RESET_COLOR) : " "[$(PROJECT)]" "$@"
	rm -rf $(OBJDIR)

fclean: clean
	@printf "$(CYAN_FG)%-$(PROJECT_SPACING)s$(RESET_COLOR) $(GREEN_FG)%-$(RULE_SPACING)s$(RESET_COLOR) : " "[$(PROJECT)]" "$@"
	rm -f $(NAME)

re: fclean all

# Can be used as follows:
# $(LIBFT): $(addprefix $(dir $(LIBFT)), $(shell $(MAKE) -s -C $(dir $(LIBFT)) sources))
sources:
	@echo $(SOURCES)


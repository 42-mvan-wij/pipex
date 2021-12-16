CHAR_SRCS =	src/char/ft_isalnum.c	\
			src/char/ft_isalpha.c	\
			src/char/ft_isascii.c	\
			src/char/ft_iscntrl.c	\
			src/char/ft_isdigit.c	\
			src/char/ft_isgraph.c	\
			src/char/ft_islower.c	\
			src/char/ft_isprint.c	\
			src/char/ft_ispunct.c	\
			src/char/ft_isspace.c	\
			src/char/ft_isupper.c	\
			src/char/ft_isxdigit.c	\
			src/char/ft_tolower.c	\
			src/char/ft_toupper.c

GNL_SRCS =	src/gnl/get_next_line.c			\
			src/gnl/get_next_line_utils.c

IO_SRCS =	src/io/ft_putchar_fd.c		\
			src/io/ft_putendl_fd.c		\
			src/io/ft_putnbr_base_fd.c	\
			src/io/ft_putnbr_fd.c		\
			src/io/ft_putstr_fd.c

LST_SRCS =	src/lst/ft_lstadd_back.c	\
			src/lst/ft_lstadd_front.c	\
			src/lst/ft_lstclear.c		\
			src/lst/ft_lstdelone.c		\
			src/lst/ft_lstinsert.c		\
			src/lst/ft_lstiter.c		\
			src/lst/ft_lstlast.c		\
			src/lst/ft_lstmap.c			\
			src/lst/ft_lstnew.c			\
			src/lst/ft_lstsize.c		\
			src/lst/ft_lstitem.c

MEM_SRCS =	src/mem/ft_bzero.c				\
			src/mem/ft_calloc.c				\
			src/mem/ft_malloc.c				\
			src/mem/ft_memccpy.c			\
			src/mem/ft_memchr.c				\
			src/mem/ft_memcmp.c				\
			src/mem/ft_memcpy.c				\
			src/mem/ft_memdup.c				\
			src/mem/ft_memmove.c			\
			src/mem/ft_memrchr.c			\
			src/mem/ft_memset.c				\
			src/mem/ft_free_and_nullify.c	\
			src/mem/ft_free_arr.c			\
			src/mem/ft_free_arr_n.c

NBR_SRCS =	src/nbr/ft_atod.c		\
			src/nbr/ft_atoi.c		\
			src/nbr/ft_itoa_base.c	\
			src/nbr/ft_itoa_basei.c	\
			src/nbr/ft_itoa.c		\
			src/nbr/ft_nbrlen_u.c	\
			src/nbr/ft_nbrlen.c		\
			src/nbr/ft_utoa_base.c	\
			src/nbr/ft_utoa_basei.c	\
			src/nbr/ft_utoa.c		\
			src/nbr/ft_get_digit.c	\
			src/nbr/ft_set_digit.c

STR_SRCS =	src/str/ft_split.c		\
			src/str/ft_str_filter.c	\
			src/str/ft_strchr.c		\
			src/str/ft_strdup.c		\
			src/str/ft_strjoin.c	\
			src/str/ft_strlcat.c	\
			src/str/ft_strlcpy.c	\
			src/str/ft_strlen.c		\
			src/str/ft_strmapi.c	\
			src/str/ft_strncmp.c	\
			src/str/ft_strnstr.c	\
			src/str/ft_strrchr.c	\
			src/str/ft_strtolower.c	\
			src/str/ft_strtoupper.c	\
			src/str/ft_strtrim.c	\
			src/str/ft_substr.c

TREE_SRCS =	src/tree/ft_treenew.c

SOURCES = $(CHAR_SRCS) $(GNL_SRCS) $(IO_SRCS) $(LST_SRCS) $(MEM_SRCS) $(NBR_SRCS) $(STR_SRCS) $(TREE_SRCS)

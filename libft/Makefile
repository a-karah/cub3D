NAME = libft.a
INCL_FOLDER = includes
SRCS_NAMES = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
		ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
		ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
		ft_atoi.c ft_calloc.c ft_strdup.c \
		ft_isupper.c ft_islower.c ft_isspace.c \
		ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
		ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
		ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \
		get_next_line.c \
		ft_printf.c print_nbr.c print_text.c print_nbr_utils.c \
		ft_max.c ft_min.c ft_abs.c ft_arriteri.c ft_atol.c ft_swap.c \
		ft_printarr.c ft_qsort.c \
		vector.c ft_degree.c
SRCS_DIR = srcs/
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_NAMES))
OBJS_NAMES = $(SRCS_NAMES:.c=.o)
OBJS_DIR = objs/
OBJS = $(addprefix $(OBJS_DIR), $(OBJS_NAMES))

CC = gcc
AR = ar
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror
ARFLAGS = -rcs

all: $(NAME)

debug: CFLAGS += -g
debug: $(NAME)

address: CFLAGS += -fsanitize=address -g
address: re

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(NAME): $(OBJS_DIR) $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCL_FOLDER)

test: debug
	$(CC) $(CFLAGS) ./test/main.c -L. -lft
	@mv ./a.out ./test
	@./test/a.out

clean:
	$(RM) $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)
	$(RM) ./test/a.out

re: fclean all

.PHONY: all, clean, fclean, re, test, debug, address

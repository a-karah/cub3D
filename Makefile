CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
UNAME = $(shell uname)
MLX_NAME = libmlx.a

ifeq ($(UNAME), Linux)
	MLX_DIR = minilibx_linux
	MLX_FLAGS = -L/usr/bin/lib/ -lXext -lX11 -lm
endif

ifeq ($(UNAME), Darwin)
	MLX_DIR = minilibx_opengl
	MLX_FLAGS = -framework OpenGL -framework AppKit
endif

NAME = cub3D
INCLUDES = -I./includes

LIBFT_DIR = libft
LIBFT_NAME = libft.a
LIBFT_OPT = all

SRC_DIR = srcs
OBJ_DIR = objs
SRC_FILES = main.c \
			parse_map.c \
			handle_errors.c \
			color_utils.c \
			parse_utils.c \
			free_all.c \
			check_map.c \
			utils.c \
			init.c \
			draw_win.c \
			mlx_utils.c \
			mlx_hooks.c \
			player.c \
			draw_utils.c \
			raycasting.c \
			texture_utils.c \
			key_utils.c

OBJ_FILES = $(SRC_FILES:.c=.o)
SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS = $(addprefix $(OBJ_DIR)/, $(OBJ_FILES))

all: $(NAME)

debug: CFLAGS += -g
debug: LIBFT_OPT = debug
debug: $(NAME)

address: CFLAGS += -fsanitize=address -g
address: LIBFT_OPT = address
address: re

$(NAME): $(LIBFT_DIR)/$(LIBFT_NAME) $(MLX_DIR)/$(MLX_NAME) $(OBJ_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L$(LIBFT_DIR) -lft -L./$(MLX_DIR) -lmlx $(MLX_FLAGS) $(INCLUDES)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(LIBFT_DIR)/$(LIBFT_NAME):
	$(MAKE) -sC $(LIBFT_DIR) $(LIBFT_OPT)

$(MLX_DIR)/$(MLX_NAME):
	$(MAKE) -sC $(MLX_DIR)

clean:
	$(MAKE) -sC $(MLX_DIR) clean
	$(MAKE) -sC $(LIBFT_DIR) clean
	$(RM) $(OBJ_DIR)

fclean: clean
	$(MAKE) -sC $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

dre: fclean debug

norm:
	norminette $(SRCS) includes/cub3D.h

.PHONY: all clean fclean re debug dre address

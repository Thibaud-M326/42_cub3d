NAME = cub3D

LIBFT_DIR = libft/
LIBFT_NAME = $(LIBFT_DIR)libft.a
HEADER = $(LIBFT_DIR)libft.h

CC = cc
FLAGS = -Wall -Werror -Wextra

MLX_DIR = minilibx-linux/
MLX_NAME = $(MLX_DIR)libmlx.a
MLX_FLAGS = -L $(MLX_DIR) -lXext -lX11 -lmlx_Linux $(MLX_NAME)
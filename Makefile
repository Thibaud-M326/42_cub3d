#------------------------------------------------#
#					LIBFT						 #
#------------------------------------------------#
LIBFT_DIR = lib/libft/
LIBFT = $(LIBFT_DIR)libft.a

#------------------------------------------------#
#					MLX							 #
#------------------------------------------------#
MLX_DIR = lib/minilibx-linux/
MLX_NAME = $(MLX_DIR)libmlx.a
MLX_FLAGS = -L $(MLX_DIR) -lXext -lX11 -lmlx_Linux $(MLX_NAME)

#------------------------------------------------#
#					FILES						 #
#------------------------------------------------#
NAME = cub3D
SRC_FILES = main						\
			exit/free_exit				\
			exit/utils					\
			hook/hook					\
			minimap/draw				\
			minimap/update				\
			minimap/utils				\
			parsing/check_map			\
			parsing/color				\
			parsing/file_utils			\
			parsing/file				\
			parsing/identifiers_utils	\
			parsing/identifiers			\
			parsing/init_player_dir		\
			parsing/input				\
			parsing/map					\
			parsing/textures			\
			parsing/utils				\
			player/player_collision		\
			player/player_move			\
			player/player_turn			\
			render/draw_pixel			\
			render/init_render			\
			render/raycasting_dda		\
			render/raycasting_init		\
			render/raycasting			\
			render/render				\
			structures/s_check			\
			structures/s_data			\
			structures/s_file			\
			structures/s_fps			\
			structures/s_minimap		\
			structures/s_map			\
			structures/s_mlx			\
			structures/s_player			\
			structures/s_textures		\
			structures/s_key			\
			texture/draw_textures		\
			texture/get_texture_color	\
			texture/get_texture_x		\
			texture/load_textures		\
			texture/ray_hit_point		\
			time/fps_count				\
			time/get_current_time_ms	\

#------------------------------------------------#
#					DIRECTORY					 #
#------------------------------------------------#
OBJ_DIR = .build/
SRC_DIR = src/

#------------------------------------------------#
#					PATHS						 #
#------------------------------------------------#
SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
DEP = $(OBJ:.o=.d)

#------------------------------------------------#
#					FLAGS						 #
#------------------------------------------------#
CC = cc
CFLAGS = -g3 -Wall -Werror -Wextra
CPPFLAGS = -MMD -MP -Iinclude -I$(LIBFT_DIR) -I$(MLX_DIR)
MAKEFLAGS += --no-print-directory

#------------------------------------------------#
#			FUNCTION TO CREATE DIRS 			 #
#------------------------------------------------#
define create_dir
	$(shell mkdir -p $(dir $(1)))
endef

#------------------------------------------------#
#					RULES						 #
#------------------------------------------------#
all: makelibft $(NAME)

$(NAME): $(LIBFT) $(MLX_NAME) $(OBJ)
	@make -C $(MLX_DIR)
	@echo "\n$(MAGENTA)$(BOLD)💻 Compiling executable...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJ) -L $(LIBFT_DIR) $(LIBFT) $(MLX_FLAGS) -o $(NAME) -lm
	@echo "$(GREEN)$(BOLD)\n✅ Compilation successfull!$(RESET)"
	@echo "$(CYAN) └─ Ready to run: ./$(NAME)\n$(RESET)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c Makefile
	$(call create_dir,$@)
	@echo " → Compiling $(YELLOW)$<$(RESET)"
	@$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

makelibft:
	@$(MAKE) -C lib/libft

-include $(DEP)

clean:
	@$(MAKE) -C lib/libft clean
	@rm -rf $(OBJ_DIR)
	@echo "$(MAGENTA)$(BOLD)🧹 Cleaning up project files...$(RESET)"
	@echo "$(CYAN) ├─ Removed object files, and dependencies$(RESET)"
	@echo "$(CYAN) └─ Cleaned build directory: $(OBJ_DIR)$(RESET)"

fclean: clean
	@$(MAKE) -C lib/libft fclean
	@rm -f $(NAME)
	@echo "$(GREEN)$(BOLD)\n🗑️ Full clean-up completed:$(RESET)"
	@echo "$(CYAN) └─ Executable removed: ./$(NAME)\n$(RESET)"

re : fclean all

.PHONY : clean fclean re name makelibft

#------------------------------------------------#
#					COLORS						 #
#------------------------------------------------#
GREEN			= \033[0;32m
YELLOW			= \033[1;33m
CYAN			= \033[0;36m
MAGENTA			= \033[0;35m
BOLD    		= \033[1m
RESET   		= \033[0m

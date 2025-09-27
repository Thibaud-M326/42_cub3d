#------------------------------------------------#
#					LIBFT						 #
#------------------------------------------------#
LIBFT_DIR 		= lib/libft/
LIBFT 			= $(LIBFT_DIR)libft.a

#------------------------------------------------#
#					MLX							 #
#------------------------------------------------#
MLX_DIR 		= lib/minilibx-linux/
MLX_NAME 		= $(MLX_DIR)libmlx.a
MLX_FLAGS 		= -L $(MLX_DIR) -lXext -lX11 -lmlx_Linux $(MLX_NAME)

#------------------------------------------------#
#					FILES						 #
#------------------------------------------------#
NAME 			= cub3D
SRC_FILES 		= main init

vpath %.c src src/parsing src/render

#------------------------------------------------#
#					DIRECTORY					 #z
#------------------------------------------------#
OBJ_DIR 		= .build/

#------------------------------------------------#
#					PATHS						 #
#------------------------------------------------#
SRC				= $(addsuffix .c, $(SRC_FILES))
OBJ 			= $(OBJ_DIR)$(SRC:.c=.o)
DEP 			= $(OBJ:.o=.d)

#------------------------------------------------#
#					FLAGS						 #
#------------------------------------------------#
CC 				= cc
CFLAGS 			= -Wall -Werror -Wextra
CPPFLAGS 		= -MMD -MP -Iinclude -I$(LIBFT_DIR) -I$(MLX_DIR)
MAKEFLAGS		+= --no-print-directory

#------------------------------------------------#
#					RULES						 #
#------------------------------------------------#
all: makelibft $(NAME)

$(NAME): $(OBJ) | $(OBJ_DIR)
	@make -C $(MLX_DIR)
	@echo "\n$(MAGENTA)$(BOLD)💻 Compiling executable...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJ) \
	    -L $(LIBFT_DIR) $(LIBFT) \
	    -L $(MLX_DIR) -lmlx -lX11 -lXext -lm -lrt -ldl \
	    -o $(NAME)
	@echo "$(GREEN)$(BOLD)\n✅ Compilation successfull!$(RESET)"
	@echo "$(CYAN)    └─ Ready to run: ./$(NAME)\n$(RESET)"


$(OBJ_DIR)%.o: %.c Makefile | $(OBJ_DIR)
	@echo "  → Compiling $(YELLOW)$<$(RESET)"
	@$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $@

makelibft:
	@$(MAKE) -C lib/libft

-include $(DEP)

clean:
	@$(MAKE) -C lib/libft clean
	@rm -rf $(OBJ_DIR)
	@echo "$(MAGENTA)$(BOLD)🧹 Cleaning up project files...$(RESET)"
	@echo "$(CYAN)    ├─ Removed object files, and dependencies$(RESET)"
	@echo "$(CYAN)    └─ Cleaned build directory: $(OBJ_DIR)$(RESET)"

fclean: clean
	@$(MAKE) -C lib/libft fclean
	@rm -f $(NAME)
	@echo "$(GREEN)$(BOLD)\n🗑️  Full clean-up completed:$(RESET)"
	@echo "$(CYAN)    └─ Executable removed: ./$(NAME)\n$(RESET)"

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

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmerchan <jmerchan@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/03 17:06:55 by jmerchan          #+#    #+#              #
#    Updated: 2023/04/12 16:06:38 by jmerchan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long
NAME_BONUS	= so_long_bonus

LIBFT_D		= libft/
INC_LIBFT	= -I$(LIBFT_D)
LIBFT		= $(LIBFT_D)libft.a

MLX_DIR		= MLX42/
INC_MLX		= -I$(MLX_DIR)include/MLX42 -Iinclude -lglfw -L"/Users/$$USER/.brew/opt/glfw/lib/"
MLX_LIB		= $(MLX_DIR)libmlx42.a -ldl -lglfw -pthread -lm
LIBMLX		= libmlx42.a

INC			= -Iinclude $(INC_LIBFT) $(INC_MLX)

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra

SRC			= src/main.c \
			src/game.c \
			src/map_checker.c \
			src/error.c \
			src/map.c \
			src/play.c

SRC_BONUS	= src_bonus/main_bonus.c \
			src_bonus/game_bonus.c \
			src_bonus/map_checker_bonus.c \
			src_bonus/error_bonus.c \
			src_bonus/map_bonus.c \
			src_bonus/play_bonus.c \
			src_bonus/graphics_bonus.c \
			src_bonus/enemy_bonus.c

OBJ_SRC		= $(SRC:.c=.o)

OBJ_BONUS	= $(SRC_BONUS:.c=.o)

%.o: %.c
	@$(CC)$(FLAGS) -c $< -o $@

#COLORS
GREEN = \033[1;32m
VIOLET = \033[35m
YELLOW = \033[1;33m
RED = \033[1;31m
DEFAULT = \033[0m

all:	$(LIBFT) $(LIBMLX) $(NAME)

$(NAME)		: $(OBJ_SRC)
	@echo "$(YELLOW) Norminette... $(DEFAULT)"
	@norminette src
	@$(CC) $(CFLAGS) $(INC) $(MLX_LIB) $(LIBFT) $(OBJ_SRC) -o $(NAME)
	@echo "$(GREEN)$(NAME) -> program created! $(DEFAULT) "

$(LIBMLX):
	@make -C $(MLX_DIR)
	

$(LIBFT):
	@make -C $(LIBFT_D)
	@echo "$(GREEN)$(LIBMLX) -> created! $(DEFAULT) "

$(NAME_BONUS): $(OBJ_BONUS)
	@echo "$(YELLOW) Norminette... $(DEFAULT)"
	@norminette src_bonus
	@$(CC) $(CFLAGS) $(INC) $(MLX_LIB) $(LIBFT) $(OBJ_BONUS) -o $(NAME_BONUS)
	@echo "$(GREEN) $(NAME_BONUS) -> program created! $(DEFAULT) "
	
clean		:
	@rm -f $(OBJ_SRC) $(OBJ_BONUS)
	@make -C $(LIBFT_D) clean --silent
	@make -C $(MLX_DIR) clean --silent
	@echo "$(YELLOW)$(NAME) -> Object files deleted. "

fclean		: clean
	@rm -f $(NAME) $(NAME_BONUS)
	@make -C $(LIBFT_D) fclean --silent
	@make -C $(MLX_DIR) fclean --silent
	@echo "$(RED)$(NAME) program -> Program deleted. "

re			: fclean all
	@echo "$(RED)Cleaned$(DEFAULT) and $(GREEN)rebuilt$(DEFAULT) $(NAME) project"

bonus		: $(LIBFT) $(LIBMLX) $(NAME_BONUS)

.PHONY		:
	all clean fclean re bonus

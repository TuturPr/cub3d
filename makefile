# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aperceva <aperceva@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/04 17:23:35 by arthur            #+#    #+#              #
#    Updated: 2025/05/16 16:53:54 by aperceva         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables

NAME = cub3d

INCLUDE = includes

LIBFT = libs/libft
MLX = libs/MLX42
LIBS = -L $(LIBFT) -lft -Iinclude $(MLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

CC = cc

CFLAGS = -Wall -Wextra -Werror -I $(INCLUDE) -g

GREEN = \033[32m
RED = \033[31m
DEF_COLOR = \033[0m

# Sources

SRC_DIR = ./src

SRC = $(shell find ./src -iname "*.c")

OBJS = $(SRC:.c=.o)

# Fonctions

all: libmlx $(NAME)
	@echo "$(GREEN)Compilation successful !$(DEF_COLOR)"

libmlx:
	@cmake $(MLX) -B $(MLX)/build && make -C $(MLX)/build -j4 || \
		(echo "$(RED)Error in libmlx compilation!$(DEF_COLOR)" && exit 1)

$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBFT) -s all || (echo "$(RED)Error in libft compilation!$(DEF_COLOR)" && exit 1)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME) || \
		(echo "$(RED)Error during linking!$(DEF_COLOR)" && exit 1)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ || (echo "$(RED)Error compiling $<!$(DEF_COLOR)" && exit 1)

clean:
	@rm -f $(OBJS)
	@echo "$(GREEN)Clean successful !$(DEF_COLOR)"

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(MLX)/build
	@$(MAKE) -C $(LIBFT) -s fclean || (echo "$(RED)Error in libft cleaning!$(DEF_COLOR)" && exit 1)
	@echo "$(GREEN)Full clean successful !$(DEF_COLOR)"

re: fclean all

norminette:
	@norminette $(SRC_DIR) $(INCLUDE) | grep -Ev '^Notice|OK!$$'	\
	&& bash -c 'echo -e "\033[1;31mNorminette KO!"'						\
	|| bash -c 'echo -e "\033[1;32mNorminette OK!"'

.PHONY: all clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arthur <arthur@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/04 17:23:35 by arthur            #+#    #+#              #
#    Updated: 2026/09/24 13:48:25 by arthur           ###   ########.fr        #
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

GREEN = \033[1;38;2;0;255;0m
RED = \033[1;38;2;255;0;0m
DEF_COLOR = \033[0m

# Sources

include Sources.mk

SRC_DIR = ./src

SRC = $(SRC_FILES)

OBJS = $(SRC:.c=.o)

# Fonctions

all: libmlx $(NAME)
	@printf "$(GREEN)Compilation successful !$(DEF_COLOR)\n"

libmlx:
	@cmake $(MLX) -B $(MLX)/build && make -C $(MLX)/build -j4 || \
        (printf "$(RED)Error in libmlx compilation!$(DEF_COLOR)\n" && exit 1)

$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBFT) -s all || (printf "$(RED)Error in libft compilation!$(DEF_COLOR)\n" && exit 1)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME) || \
        (printf "$(RED)Error during linking!$(DEF_COLOR)\n" && exit 1)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ || (printf "$(RED)Error compiling $<!$(DEF_COLOR)\n" && exit 1)

clean:
	@rm -f $(OBJS)
	@printf "$(GREEN)Clean successful !$(DEF_COLOR)\n"

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(MLX)/build
	@$(MAKE) -C $(LIBFT) -s fclean || (printf "$(RED)Error in libft cleaning!$(DEF_COLOR)\n" && exit 1)
	@printf "$(GREEN)Full clean successful !$(DEF_COLOR)\n"

re: fclean all

norminette:
	@norminette $(SRC_DIR)| grep -Ev '^Notice|OK!$$'    \
    && bash -c 'printf "\033[1;31mNorminette KO!\n"'                     \
    || bash -c 'printf "\033[1;32mNorminette OK!\n"'

.PHONY: all clean fclean re

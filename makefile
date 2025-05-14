# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arthur <arthur@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/04 17:23:35 by arthur            #+#    #+#              #
#    Updated: 2025/03/10 16:20:18 by arthur           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables

NAME = cub3d

INCLUDE = includes

LIBFT = libs/libft

CC = cc

CFLAGS = -Wall -Wextra -Werror -I $(INCLUDE) -g

GREEN = \033[32m
RED = \033[31m
DEF_COLOR = \033[0m

# Sources

include Sources.mk

SRC_DIR = ./src

SRC = $(SRC_FILES)

OBJS = $(SRC:.c=.o)

# Fonctions

all: $(NAME)
	@echo "$(GREEN)Compilation successful !$(DEF_COLOR)"

$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBFT) -s all || (echo "$(RED)Error in libft compilation!$(DEF_COLOR)" && exit 1)
	@$(CC) $(CFLAGS) $(OBJS) -L $(LIBFT) -lft -o $(NAME) || \
		(echo "$(RED)Error during linking!$(DEF_COLOR)" && exit 1)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ || (echo "$(RED)Error compiling $<!$(DEF_COLOR)" && exit 1)

clean:
	@rm -f $(OBJS)
	@echo "$(GREEN)Clean successful !$(DEF_COLOR)"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT) -s fclean || (echo "$(RED)Error in libft cleaning!$(DEF_COLOR)" && exit 1)
	@echo "$(GREEN)Full clean successful !$(DEF_COLOR)"

re: fclean all

norminette:
	@norminette $(SRC_DIR) $(INCLUDE) | grep -Ev '^Notice|OK!$$'	\
	&& bash -c 'echo -e "\033[1;31mNorminette KO!"'						\
	|| bash -c 'echo -e "\033[1;32mNorminette OK!"'

.PHONY: all clean fclean re

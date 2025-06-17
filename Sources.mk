# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Sources.mk                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arthur <arthur@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/10 15:57:52 by arthur            #+#    #+#              #
#    Updated: 2025/03/10 16:20:34 by arthur           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_MAIN := ./src/main.c ./src/raycasting/ray_calcs.c ./src/raycasting/ray_render.c ./src/raycasting/ray_utils.c ./src/hook/hook.c ./src/hook/movement.c ./src/hook/camera.c ./src/parsing/parsing.c ./src/parsing/player.c ./src/parsing/colors.c ./src/parsing/checks.c ./src/parsing/utils.c ./src/parsing/map.c ./src/error.c 

SRC_FILES := $(SRC_MAIN)

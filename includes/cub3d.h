/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperceva <aperceva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:55:14 by aperceva          #+#    #+#             */
/*   Updated: 2025/05/19 16:43:32 by aperceva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "libft.h"
#include <stdio.h>
#include "MLX42.h"
#include <math.h>

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} ColorRGB;

const ColorRGB RGB_Red    = {255, 0, 0};
const ColorRGB RGB_Green  = {0, 255, 0};
const ColorRGB RGB_Blue   = {0, 0, 255};
const ColorRGB RGB_White  = {255, 255, 255};
const ColorRGB RGB_Yellow = {255, 255, 0};

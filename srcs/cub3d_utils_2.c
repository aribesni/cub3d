/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <aribesni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:12:46 by aribesni          #+#    #+#             */
/*   Updated: 2021/03/24 17:08:32 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		ft_texture(t_calcul *calcul)
{
	double	wallx;

	wallx = 0.0;
	if (calcul->side == 0)
		wallx = calcul->rayPosY + calcul->perpWall * calcul->rayDirY;
	else
		wallx = calcul->rayPosX + calcul->perpWall * calcul->rayDirX;
	wallx -= (int)wallx;
	calcul->texX = (int)(wallx * 64);
	if (calcul->side == 0 && calcul->rayDirX > 0)
		calcul->texX = 64 - calcul->texX - 1;
	else if (calcul->side == 1 && calcul->rayDirX < 0)
		calcul->texX = 64 - calcul->texX - 1;
	calcul->step_tex = 1.0 * 64 / calcul->lineH;
	calcul->texPos = (calcul->drawStart - calcul->h / 2 + calcul->lineH / 2) *
	calcul->step_tex;
}

void		ft_spawn(t_calcul *calcul, char c, double x, double y)
{
	calcul->posX = y + 0.5;
	calcul->posY = x + 0.5;
	if (c == 'N')
	{
		calcul->dirY = -1.0;
		calcul->planeX = -0.80;
	}
	if (c == 'S')
	{
		calcul->dirY = 1.0;
		calcul->planeX = 0.80;
	}
	if (c == 'E')
	{
		calcul->dirX = 1.0;
		calcul->planeY = -0.80;
	}
	if (c == 'W')
	{
		calcul->dirX = -1.0;
		calcul->planeY = 0.80;
	}
}

void		ft_init(t_calcul *calcul)
{
	calcul->movSpeed = 0.15;
	calcul->rotSpeed = 0.5;
	calcul->up = 0;
	calcul->down = 0;
	calcul->left = 0;
	calcul->right = 0;
	calcul->rt_left = 0;
	calcul->rt_right = 0;
	calcul->color = 0;
	calcul->color_c = 0;
	calcul->color_f = 0;
	calcul->bit_1 = 0;
	calcul->bit_2 = 0;
	calcul->bit_3 = 0;
}

void		ft_convert_endian(t_calcul *calcul, char c)
{
	int		temp;

	temp = calcul->bit_1 << 16;
	temp = temp | calcul->bit_2 << 8;
	temp = temp | calcul->bit_3;
	if (c == 'C')
		calcul->color_c = temp;
	if (c == 'F')
		calcul->color_f = temp;
}

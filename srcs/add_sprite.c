/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_sprite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <aribesni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 18:50:20 by aribesni          #+#    #+#             */
/*   Updated: 2021/02/27 18:50:26 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_calc_end_start(t_calcul *calcul)
{
	if (calcul->drawStartY < 0)
		calcul->drawStartY = 0;
	calcul->drawEndY = calcul->spH / 2 + calcul->h / 2;
	if (calcul->drawEndY >= calcul->h)
		calcul->drawEndY = calcul->h - 1;
	calcul->spW = abs((int)(calcul->h / (calcul->transY)));
	calcul->drawStartX = -calcul->spW / 2 + calcul->spScreenX;
	if (calcul->drawStartX < 0)
		calcul->drawStartX = 0;
	calcul->drawEndX = calcul->spW / 2 + calcul->spScreenX;
	if (calcul->drawEndX >= calcul->w)
		calcul->drawEndX = calcul->w - 1;
}

static void	ft_add_sprite_2(t_calcul *calcul)
{
	int		d;
	int		y;
	int		color_sp;

	color_sp = 0;
	y = calcul->drawStartY;
	if (calcul->transY > 0 && calcul->stripe > 0 && calcul->stripe <
	calcul->w && calcul->transY < calcul->ZBuffer[calcul->stripe])
	{
		while (y < calcul->drawEndY)
		{
			d = y * 256 - calcul->h * 128 + calcul->spH * 128;
			calcul->sp_y = ((d * calcul->tex_sp->height) / calcul->spH) / 256;
			color_sp = calcul->tex_sp->tex_data[calcul->tex_sp->width *
			calcul->sp_y + calcul->sp_x];
			if (color_sp != 9961608)
				ft_set_color(calcul->image, color_sp, calcul->stripe, y);
			y++;
		}
	}
}

static void	ft_sprite_calc(t_calcul *calcul, int i)
{
	double	inv;

	calcul->spriteX = calcul->sprite[calcul->order[i]].x - calcul->posX;
	calcul->spriteY = calcul->sprite[calcul->order[i]].y - calcul->posY;
	inv = 1.0 / (calcul->planeX * calcul->dirY - calcul->dirX *
	calcul->planeY);
	calcul->transX = inv * (calcul->dirY * calcul->spriteX - calcul->dirX *
	calcul->spriteY);
	calcul->transY = inv * (-calcul->planeY * calcul->spriteX +
	calcul->planeX * calcul->spriteY);
	calcul->spScreenX = (int)((calcul->w / 2) * (1 + calcul->transX /
	calcul->transY));
	calcul->spH = abs((int)(calcul->h / (calcul->transY)));
	calcul->drawStartY = -calcul->spH / 2 + calcul->h / 2;
	ft_calc_end_start(calcul);
}

void		ft_add_sprite(t_calcul *calcul)
{
	int		i;

	i = 0;
	while (i < calcul->sp_count)
	{
		ft_sprite_calc(calcul, i);
		calcul->stripe = calcul->drawStartX;
		while (calcul->stripe < calcul->drawEndX)
		{
			calcul->sp_x = (int)(256 * (calcul->stripe - (-calcul->spW / 2 +
			calcul->spScreenX)) * calcul->tex_sp->width / calcul->spW / 256);
			ft_add_sprite_2(calcul);
			calcul->stripe++;
		}
		i++;
	}
}

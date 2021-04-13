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

#include "cub.h"

static void			ft_calc_end_start(t_calcul *calcul)
{
	if (calcul->drawstart_y < 0)
		calcul->drawstart_y = 0;
	calcul->drawend_y = calcul->sp_h / 2 + calcul->h / 2;
	if (calcul->drawend_y >= calcul->h)
		calcul->drawend_y = calcul->h - 1;
	calcul->sp_w = abs((int)(calcul->h / (calcul->trans_y)));
	calcul->drawstart_x = -calcul->sp_w / 2 + calcul->sp_screenx;
	if (calcul->drawstart_x < 0)
		calcul->drawstart_x = 0;
	calcul->drawend_x = calcul->sp_w / 2 + calcul->sp_screenx;
	if (calcul->drawend_x >= calcul->w)
		calcul->drawend_x = calcul->w - 1;
}

static void			ft_add_sprite_2(t_calcul *calcul)
{
	int				d;
	int				y;
	unsigned int	color_sp;

	d = 0;
	color_sp = 0;
	y = calcul->drawstart_y;
	if (calcul->trans_y > 0 && calcul->stripe > 0 && calcul->stripe <
	calcul->w && calcul->trans_y < calcul->zbuffer[calcul->stripe])
	{
		while (y < calcul->drawend_y)
		{
			d = y * 256 - calcul->h * 128 + calcul->sp_h * 128;
			calcul->sp_y = ((d * calcul->tex_sp->height) / calcul->sp_h) / 256;
			color_sp = calcul->tex_sp->tex_data[calcul->tex_sp->width *
			calcul->sp_y + calcul->sp_x];
			if (color_sp != 9961608)
				ft_set_color(calcul->image, color_sp, calcul->stripe, y);
			y++;
		}
	}
}

static void			ft_sprite_calc(t_calcul *calcul, int i)
{
	double			inv;

	calcul->sprite_x = calcul->sprite[calcul->order[i]].x - calcul->pos_x;
	calcul->sprite_y = calcul->sprite[calcul->order[i]].y - calcul->pos_y;
	inv = 1.0 / (calcul->plane_x * calcul->dir_y - calcul->dir_x *
	calcul->plane_y);
	calcul->trans_x = inv * (calcul->dir_y * calcul->sprite_x - calcul->dir_x *
	calcul->sprite_y);
	calcul->trans_y = inv * (-calcul->plane_y * calcul->sprite_x +
	calcul->plane_x * calcul->sprite_y);
	calcul->sp_screenx = (int)((calcul->w / 2) * (1 + calcul->trans_x /
	calcul->trans_y));
	calcul->sp_h = abs((int)(calcul->h / (calcul->trans_y)));
	calcul->drawstart_y = -calcul->sp_h / 2 + calcul->h / 2;
	ft_calc_end_start(calcul);
}

void				ft_add_sprite(t_calcul *calcul)
{
	int				i;

	i = 0;
	while (i < calcul->sp_count)
	{
		ft_sprite_calc(calcul, i);
		calcul->stripe = calcul->drawstart_x;
		while (calcul->stripe < calcul->drawend_x)
		{
			calcul->sp_x = (int)(256 * (calcul->stripe - (-calcul->sp_w / 2 +
			calcul->sp_screenx)) * calcul->tex_sp->width / calcul->sp_w / 256);
			ft_add_sprite_2(calcul);
			calcul->stripe++;
		}
		i++;
	}
}

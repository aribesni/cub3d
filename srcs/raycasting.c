/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <aribesni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 18:56:24 by aribesni          #+#    #+#             */
/*   Updated: 2021/02/27 18:56:36 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	ft_ray_size(t_calcul *calcul)
{
	if (calcul->side == 0)
		calcul->perpwall = fabs((calcul->mapy - calcul->raypos_x +
		(1 - calcul->stepx) / 2) / calcul->raydir_x);
	else
		calcul->perpwall = fabs((calcul->mapx - calcul->raypos_y +
		(1 - calcul->stepy) / 2) / calcul->raydir_y);
	calcul->line_h = fabs((calcul->h / calcul->perpwall));
	calcul->drawstart = (-1 * (calcul->line_h)) / 2 + calcul->h / 2;
	if (calcul->drawstart < 0)
		calcul->drawstart = 0;
	calcul->drawend = calcul->line_h / 2 + calcul->h / 2;
	if (calcul->drawend >= calcul->h)
		calcul->drawend = calcul->h - 1;
}

static void	ft_hit(t_calcul *calcul)
{
	while (calcul->hit == 0)
	{
		if (calcul->sidedist_x < calcul->sidedist_y)
		{
			calcul->sidedist_x += calcul->deltadist_x;
			calcul->mapy += calcul->stepx;
			calcul->side = 0;
		}
		else
		{
			calcul->sidedist_y += calcul->deltadist_y;
			calcul->mapx += calcul->stepy;
			calcul->side = 1;
		}
		if (calcul->map[calcul->mapx][calcul->mapy] != '0' &&
			calcul->map[calcul->mapx][calcul->mapy] != '2' &&
			calcul->map[calcul->mapx][calcul->mapy] != 'E' &&
			calcul->map[calcul->mapx][calcul->mapy] != 'N' &&
			calcul->map[calcul->mapx][calcul->mapy] != 'S' &&
			calcul->map[calcul->mapx][calcul->mapy] != 'W')
			calcul->hit = 1;
	}
}

static void	ft_ray_direction(t_calcul *calcul)
{
	if (calcul->raydir_x < 0)
	{
		calcul->stepx = -1;
		calcul->sidedist_x = (calcul->raypos_x - calcul->mapy) *
		calcul->deltadist_x;
	}
	else
	{
		calcul->stepx = 1;
		calcul->sidedist_x = (calcul->mapy + 1.0 - calcul->raypos_x) *
		calcul->deltadist_x;
	}
	if (calcul->raydir_y < 0)
	{
		calcul->stepy = -1;
		calcul->sidedist_y = (calcul->raypos_y - calcul->mapx) *
		calcul->deltadist_y;
	}
	else
	{
		calcul->stepy = 1;
		calcul->sidedist_y = (calcul->mapx + 1.0 - calcul->raypos_y) *
		calcul->deltadist_y;
	}
}

static void	ft_init_ray(t_calcul *calcul, int x)
{
	calcul->camera_x = 2 * x / (double)calcul->w - 1;
	calcul->raypos_x = calcul->pos_x;
	calcul->raypos_y = calcul->pos_y;
	calcul->raydir_x = calcul->dir_x + calcul->plane_x * calcul->camera_x;
	calcul->raydir_y = calcul->dir_y + calcul->plane_y * calcul->camera_x;
	calcul->mapy = (int)calcul->raypos_x;
	calcul->mapx = (int)calcul->raypos_y;
	calcul->deltadist_x = sqrt(1 + (calcul->raydir_y * calcul->raydir_y) /
	(calcul->raydir_x * calcul->raydir_x));
	calcul->deltadist_y = sqrt(1 + (calcul->raydir_x * calcul->raydir_x) /
	(calcul->raydir_y * calcul->raydir_y));
	calcul->hit = 0;
}

int			ft_calculate(t_calcul *calcul)
{
	int		x;

	x = 0;
	while (x < calcul->w)
	{
		ft_init_ray(calcul, x);
		ft_ray_direction(calcul);
		ft_hit(calcul);
		ft_ray_size(calcul);
		ft_texture(calcul);
		ft_disp_col(calcul, x);
		calcul->zbuffer[x] = calcul->perpwall;
		x++;
	}
	ft_init_sprite(calcul);
	if (calcul->save == 1)
		return (1);
	return (1);
}

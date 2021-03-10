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
		calcul->perpWall = fabs((calcul->mapY - calcul->rayPosX +
		(1 - calcul->stepX) / 2) / calcul->rayDirX);
	else
		calcul->perpWall = fabs((calcul->mapX - calcul->rayPosY +
		(1 - calcul->stepY) / 2) / calcul->rayDirY);
	calcul->lineH = fabs((calcul->h / calcul->perpWall));
	calcul->drawStart = (-1 * (calcul->lineH)) / 2 + calcul->h / 2;
	if (calcul->drawStart < 0)
		calcul->drawStart = 0;
	calcul->drawEnd = calcul->lineH / 2 + calcul->h / 2;
	if (calcul->drawEnd >= calcul->h)
		calcul->drawEnd = calcul->h - 1;
}

static void	ft_hit(t_calcul *calcul)
{
	while (calcul->hit == 0)
	{
		if (calcul->sideDistX < calcul->sideDistY)
		{
			calcul->sideDistX += calcul->deltaDistX;
			calcul->mapY += calcul->stepX;
			calcul->side = 0;
		}
		else
		{
			calcul->sideDistY += calcul->deltaDistY;
			calcul->mapX += calcul->stepY;
			calcul->side = 1;
		}
		if (calcul->map[calcul->mapX][calcul->mapY] != '0' &&
			calcul->map[calcul->mapX][calcul->mapY] != '2' &&
			calcul->map[calcul->mapX][calcul->mapY] != 'E' &&
			calcul->map[calcul->mapX][calcul->mapY] != 'N' &&
			calcul->map[calcul->mapX][calcul->mapY] != 'S' &&
			calcul->map[calcul->mapX][calcul->mapY] != 'W')
			calcul->hit = 1;
	}
}

static void	ft_ray_direction(t_calcul *calcul)
{
	if (calcul->rayDirX < 0)
	{
		calcul->stepX = -1;
		calcul->sideDistX = (calcul->rayPosX - calcul->mapY) *
		calcul->deltaDistX;
	}
	else
	{
		calcul->stepX = 1;
		calcul->sideDistX = (calcul->mapY + 1.0 - calcul->rayPosX) *
		calcul->deltaDistX;
	}
	if (calcul->rayDirY < 0)
	{
		calcul->stepY = -1;
		calcul->sideDistY = (calcul->rayPosY - calcul->mapX) *
		calcul->deltaDistY;
	}
	else
	{
		calcul->stepY = 1;
		calcul->sideDistY = (calcul->mapX + 1.0 - calcul->rayPosY) *
		calcul->deltaDistY;
	}
}

static void	ft_init_ray(t_calcul *calcul, int x)
{
	calcul->cameraX = 2 * x / (double)calcul->w - 1;
	calcul->rayPosX = calcul->posX;
	calcul->rayPosY = calcul->posY;
	calcul->rayDirX = calcul->dirX + calcul->planeX * calcul->cameraX;
	calcul->rayDirY = calcul->dirY + calcul->planeY * calcul->cameraX;
	calcul->mapY = (int)calcul->rayPosX;
	calcul->mapX = (int)calcul->rayPosY;
	calcul->deltaDistX = sqrt(1 + (calcul->rayDirY * calcul->rayDirY) /
	(calcul->rayDirX * calcul->rayDirX));
	calcul->deltaDistY = sqrt(1 + (calcul->rayDirX * calcul->rayDirX) /
	(calcul->rayDirY * calcul->rayDirY));
	calcul->hit = 0;
}

void		ft_calculate(t_calcul *calcul)
{
	int		x;

	x = 0;
	while (x <= calcul->w)
	{
		ft_init_ray(calcul, x);
		ft_ray_direction(calcul);
		ft_hit(calcul);
		ft_ray_size(calcul);
		ft_texture(calcul);
		ft_disp_col(calcul, x);
		calcul->ZBuffer[x] = calcul->perpWall;
		x++;
	}
	ft_init_sprite(calcul);
}

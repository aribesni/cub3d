#include "cub3d.h"

static void		ft_ray_size(t_calcul *calcul)
{
	if (calcul->side == 0)
		calcul->perpWallDist = fabs((calcul->mapX - calcul->rayPosX + (1 - calcul->stepX)/2)/calcul->rayDirX);
	else
		calcul->perpWallDist = fabs((calcul->mapY - calcul->rayPosY + (1 - calcul->stepY)/2)/calcul->rayDirY);
	calcul->hauteurLigne = fabs((calcul->h / calcul->perpWallDist));
	calcul->drawStart = (-1 * (calcul->hauteurLigne))/2 + calcul->h/2;
	calcul->drawEnd = calcul->hauteurLigne/2 + calcul->h/2;
	if (calcul->drawStart < 0)
		calcul->drawStart = 0;
	if (calcul->drawEnd >= calcul->h)
		calcul->drawEnd = calcul->h - 1;
}

static void		ft_hit(t_calcul *calcul)
{
	while (calcul->hit == 0)
	{
		if (calcul->sideDistX < calcul->sideDistY)
		{
			calcul->sideDistX += calcul->deltaDistX;
			calcul->mapX += calcul->stepX;
			calcul->side = 0;
		}
		else
		{
			calcul->sideDistY += calcul->deltaDistY;
			calcul->mapY += calcul->stepY;
			calcul->side = 1;
		}
		if (calcul->map[calcul->mapX][calcul->mapY] > 0)
			calcul->hit = 1;
	}
}

static void		ft_ray_direction(t_calcul *calcul)
{
	if (calcul->rayDirX < 0)
	{
		calcul->stepX = -1;
		calcul->sideDistX = (calcul->rayPosX - calcul->mapX) * calcul->deltaDistX;
	}
	else
	{
		calcul->stepX = 1;
		calcul->sideDistX = (calcul->mapX + 1.0 - calcul->rayPosX) * calcul->deltaDistX;
	}
	if (calcul->rayDirY < 0)
	{
		calcul->stepY = -1;
		calcul->sideDistY = (calcul->rayPosY - calcul->mapY) * calcul->deltaDistY;
	}
	else
	{
		calcul->stepY = 1;
		calcul->sideDistY = (calcul->mapY + 1.0 - calcul->rayPosY) * calcul->deltaDistY;
	}
}

static void		ft_init_ray(t_calcul *calcul, int x)
{
	calcul->cameraX = 2 * x/(double)calcul->w - 1;
	calcul->rayPosX = calcul->posX;
	calcul->rayPosY = calcul->posY;
	calcul->rayDirX = calcul->dirX + calcul->planeX * calcul->cameraX;
	calcul->rayDirY = calcul->dirY + calcul->planeY * calcul->cameraX;
	calcul->mapX = (int)calcul->rayPosX;
	calcul->mapY = (int)calcul->rayPosY;
	calcul->deltaDistX = sqrt(1 + (calcul->rayDirY * calcul->rayDirY)/(calcul->rayDirX * calcul->rayDirX));
	calcul->deltaDistY = sqrt(1 + (calcul->rayDirX * calcul->rayDirX)/(calcul->rayDirY * calcul->rayDirY));
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
		ft_store_color(calcul, calcul->image, x);
		x++;
	}
}
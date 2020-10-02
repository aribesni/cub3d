#include "cub3d.h"

static void	        ft_rotate(t_calcul *calcul, int advance)
{
	double	        dir;
	double	        plane;

	dir = calcul->dirX;
	plane = calcul->planeX;
	calcul->dirX = calcul->dirX * cos(advance * 0.1)
		- calcul->dirY * sin(advance * 0.1);
	calcul->dirY = dir * sin(advance * 0.1)
		+ calcul->dirY * cos(advance * 0.1);
	calcul->planeX = calcul->planeX * cos(advance * 0.1)
		- calcul->planeY * sin(advance * 0.1);
	calcul->planeY = plane * sin(advance * 0.1)
		+ calcul->planeY * cos(advance * 0.1);
}

static void	        ft_left_right(t_calcul *calcul)
{
	if (calcul->right == true)
	{
		if (calcul->map[(int)(calcul->posX + calcul->planeX * calcul->vitMarche)][(int)calcul->posY] == 0)
			calcul->posX += calcul->planeX * calcul->vitMarche;
		if (calcul->map[(int)calcul->posX][(int)(calcul->posY + calcul->planeY * calcul->vitMarche)] == 0)
			calcul->posY += calcul->planeY * calcul->vitMarche;
	}
	if (calcul->left == true)
	{
		if (calcul->map[(int)(calcul->posX + calcul->planeX * calcul->vitMarche)][(int)calcul->posY] == 0)
			calcul->posX -= calcul->planeX * calcul->vitMarche;
		if (calcul->map[(int)calcul->posX][(int)(calcul->posY + calcul->planeY * calcul->vitMarche)] == 0)
			calcul->posY -= calcul->planeY * calcul->vitMarche;
	}
}

static void	        ft_up_down(t_calcul *calcul)
{
	if (calcul->up == true)
	{
		if (calcul->map[(int)(calcul->posX + calcul->dirX * calcul->vitMarche)][(int)calcul->posY] == 0)
			calcul->posX += calcul->dirX * calcul->vitMarche;
		if (calcul->map[(int)calcul->posX][(int)(calcul->posY + calcul->dirY * calcul->vitMarche)] == 0)
			calcul->posY += calcul->dirY * calcul->vitMarche;
	}
	if (calcul->down == true)
	{
		if (calcul->map[(int)(calcul->posX - calcul->dirX * calcul->vitMarche)][(int)calcul->posY] == 0)
			calcul->posX -= calcul->dirX * calcul->vitMarche;
		if (calcul->map[(int)calcul->posX][(int)(calcul->posY - calcul->dirY * calcul->vitMarche)] == 0)
			calcul->posY -= calcul->dirY * calcul->vitMarche;
	}
}

void	        ft_move(t_calcul *calcul)
{
	if (calcul->up == true || calcul->down == true)
		ft_up_down(calcul);
	if (calcul->right == true || calcul->left == true)
		ft_left_right(calcul);
	if (calcul->rt_left == true)
		ft_rotate(calcul, 1);
	if (calcul->rt_right == true)
		ft_rotate(calcul, -1);
}
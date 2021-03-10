/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <aribesni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 18:56:09 by aribesni          #+#    #+#             */
/*   Updated: 2021/02/27 18:56:19 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void		ft_rotate(t_calcul *calcul, double rotate)
{
	double		dir;
	double		plane;

	dir = calcul->dirX;
	plane = calcul->planeX;
	calcul->dirX = calcul->dirX * cos(rotate * 0.1)
		- calcul->dirY * sin(rotate * 0.1);
	calcul->dirY = dir * sin(rotate * 0.1)
		+ calcul->dirY * cos(rotate * 0.1);
	calcul->planeX = calcul->planeX * cos(rotate * 0.1)
		- calcul->planeY * sin(rotate * 0.1);
	calcul->planeY = plane * sin(rotate * 0.1)
		+ calcul->planeY * cos(rotate * 0.1);
}

static void		ft_left_right(t_calcul *calcul)
{
	if (calcul->right == true)
	{
		if (calcul->map[(int)(calcul->posY - calcul->dirX *
			calcul->movSpeed)][(int)calcul->posX] == '0')
			calcul->posY += -calcul->dirX * calcul->movSpeed;
		if (calcul->map[(int)calcul->posY][(int)(calcul->posX +
			calcul->dirY * calcul->movSpeed)] == '0')
			calcul->posX += calcul->dirY * calcul->movSpeed;
	}
	if (calcul->left == true)
	{
		if (calcul->map[(int)(calcul->posY + calcul->dirX *
			calcul->movSpeed)][(int)calcul->posX] == '0')
			calcul->posY -= -calcul->dirX * calcul->movSpeed;
		if (calcul->map[(int)calcul->posY][(int)(calcul->posX -
			calcul->dirY * calcul->movSpeed)] == '0')
			calcul->posX -= calcul->dirY * calcul->movSpeed;
	}
}

static void		ft_up_down(t_calcul *calcul)
{
	if (calcul->up == true)
	{
		if (calcul->map[(int)calcul->posY][(int)(calcul->posX +
			calcul->dirX * calcul->movSpeed)] == '0')
			calcul->posX += calcul->dirX * calcul->movSpeed;
		if (calcul->map[(int)(calcul->posY + calcul->dirY *
			calcul->movSpeed)][(int)calcul->posX] == '0')
			calcul->posY += calcul->dirY * calcul->movSpeed;
	}
	if (calcul->down == true)
	{
		if (calcul->map[(int)calcul->posY][(int)(calcul->posX -
			calcul->dirX * calcul->movSpeed)] == '0')
			calcul->posX -= calcul->dirX * calcul->movSpeed;
		if (calcul->map[(int)(calcul->posY - calcul->dirY *
			calcul->movSpeed)][(int)calcul->posX] == '0')
			calcul->posY -= calcul->dirY * calcul->movSpeed;
	}
}

void			ft_move(t_calcul *calcul)
{
	if (calcul->up == true || calcul->down == true)
		ft_up_down(calcul);
	if (calcul->right == true || calcul->left == true)
		ft_left_right(calcul);
	if (calcul->rt_left == true)
		ft_rotate(calcul, calcul->rotSpeed);
	if (calcul->rt_right == true)
		ft_rotate(calcul, -calcul->rotSpeed);
}

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

	dir = calcul->dir_x;
	plane = calcul->plane_x;
	calcul->dir_x = calcul->dir_x * cos(rotate * 0.1)
		- calcul->dir_y * sin(rotate * 0.1);
	calcul->dir_y = dir * sin(rotate * 0.1)
		+ calcul->dir_y * cos(rotate * 0.1);
	calcul->plane_x = calcul->plane_x * cos(rotate * 0.1)
		- calcul->plane_y * sin(rotate * 0.1);
	calcul->plane_y = plane * sin(rotate * 0.1)
		+ calcul->plane_y * cos(rotate * 0.1);
}

static void		ft_left_right(t_calcul *calcul)
{
	if (calcul->right == TRUE)
	{
		if (calcul->map[(int)(calcul->pos_y - calcul->dir_x *
			calcul->movspeed)][(int)calcul->pos_x] == '0')
			calcul->pos_y += -calcul->dir_x * calcul->movspeed;
		if (calcul->map[(int)calcul->pos_y][(int)(calcul->pos_x +
			calcul->dir_y * calcul->movspeed)] == '0')
			calcul->pos_x += calcul->dir_y * calcul->movspeed;
	}
	if (calcul->left == TRUE)
	{
		if (calcul->map[(int)(calcul->pos_y + calcul->dir_x *
			calcul->movspeed)][(int)calcul->pos_x] == '0')
			calcul->pos_y -= -calcul->dir_x * calcul->movspeed;
		if (calcul->map[(int)calcul->pos_y][(int)(calcul->pos_x -
			calcul->dir_y * calcul->movspeed)] == '0')
			calcul->pos_x -= calcul->dir_y * calcul->movspeed;
	}
}

static void		ft_up_down(t_calcul *calcul)
{
	if (calcul->up == TRUE)
	{
		if (calcul->map[(int)calcul->pos_y][(int)(calcul->pos_x +
			calcul->dir_x * calcul->movspeed)] == '0')
			calcul->pos_x += calcul->dir_x * calcul->movspeed;
		if (calcul->map[(int)(calcul->pos_y + calcul->dir_y *
			calcul->movspeed)][(int)calcul->pos_x] == '0')
			calcul->pos_y += calcul->dir_y * calcul->movspeed;
	}
	if (calcul->down == TRUE)
	{
		if (calcul->map[(int)calcul->pos_y][(int)(calcul->pos_x -
			calcul->dir_x * calcul->movspeed)] == '0')
			calcul->pos_x -= calcul->dir_x * calcul->movspeed;
		if (calcul->map[(int)(calcul->pos_y - calcul->dir_y *
			calcul->movspeed)][(int)calcul->pos_x] == '0')
			calcul->pos_y -= calcul->dir_y * calcul->movspeed;
	}
}

void			ft_move(t_calcul *calcul)
{
	if (calcul->up == TRUE || calcul->down == TRUE)
		ft_up_down(calcul);
	if (calcul->right == TRUE || calcul->left == TRUE)
		ft_left_right(calcul);
	if (calcul->rt_left == TRUE)
		ft_rotate(calcul, calcul->rotspeed);
	if (calcul->rt_right == TRUE)
		ft_rotate(calcul, -calcul->rotspeed);
}

int				ft_run(t_calcul *calcul)
{
	ft_move(calcul);
	ft_calculate(calcul);
	mlx_put_image_to_window(calcul->mlx, calcul->win, calcul->image->img_ptr,
	0, 0);
	return (1);
}

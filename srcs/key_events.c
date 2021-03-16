/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <aribesni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 18:55:27 by aribesni          #+#    #+#             */
/*   Updated: 2021/02/27 18:55:29 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	ft_run(t_calcul *calcul)
{
	calcul->image = ft_new_image(calcul);
	calcul->tex_no = ft_new_texture(calcul, calcul->path_tex_no);
	calcul->tex_so = ft_new_texture(calcul, calcul->path_tex_so);
	calcul->tex_ea = ft_new_texture(calcul, calcul->path_tex_ea);
	calcul->tex_we = ft_new_texture(calcul, calcul->path_tex_we);
	calcul->tex_sp = ft_new_texture(calcul, calcul->path_sprite);
	ft_move(calcul);
	ft_calculate(calcul);
	if (calcul->save == 1)
	{
		ft_screenshot(calcul);
		ft_escape(calcul);
	}
	mlx_put_image_to_window(calcul->mlx, calcul->win, calcul->image->img_ptr,
	0, 0);
	return (1);
}

static int	ft_key_press(int keycode, t_calcul *calcul)
{
	if (keycode == UP)
		calcul->up = true;
	if (keycode == DOWN)
		calcul->down = true;
	if (keycode == RIGHT)
		calcul->right = true;
	if (keycode == LEFT)
		calcul->left = true;
	if (keycode == RTL)
		calcul->rt_left = true;
	if (keycode == RTR)
		calcul->rt_right = true;
	if (keycode == ESC)
		ft_escape(calcul);
	return (1);
}

static int	ft_key_release(int keycode, t_calcul *calcul)
{
	if (keycode == UP)
		calcul->up = false;
	if (keycode == DOWN)
		calcul->down = false;
	if (keycode == RIGHT)
		calcul->right = false;
	if (keycode == LEFT)
		calcul->left = false;
	if (keycode == RTL)
		calcul->rt_left = false;
	if (keycode == RTR)
		calcul->rt_right = false;
	return (1);
}

void		ft_key_events(t_calcul *calcul)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	if (!(calcul->mlx = mlx_init()))
		return ;
	if (calcul->save == 0)
	{
		mlx_get_screen_size(calcul->mlx, &x, &y);
		calcul->w = (calcul->w > x) ? x : calcul->w;
		calcul->h = (calcul->h > y) ? y : calcul->h;
		if (!(calcul->win = mlx_new_window(calcul->mlx, calcul->w,
		calcul->h, "Cub3D")))
			return ;
		mlx_hook(calcul->win, KEYPRESS, KEYPRESSMASK, ft_key_press, calcul);
		mlx_hook(calcul->win, KEYRELEASE, KEYRELEASEMASK, ft_key_release,
		calcul);
		mlx_hook(calcul->win, EXITPRESS, EXITMASK, ft_escape, calcul);
	}
	mlx_loop_hook(calcul->mlx, ft_run, calcul);
	mlx_loop(calcul->mlx);
}

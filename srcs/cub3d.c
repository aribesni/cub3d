/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <aribesni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 18:51:34 by aribesni          #+#    #+#             */
/*   Updated: 2021/02/27 18:51:39 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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

static void	ft_init_img(t_calcul *calcul)
{
	calcul->image = ft_new_image(calcul);
	calcul->tex_no = ft_new_texture(calcul, calcul->path_tex_no);
	calcul->tex_so = ft_new_texture(calcul, calcul->path_tex_so);
	calcul->tex_ea = ft_new_texture(calcul, calcul->path_tex_ea);
	calcul->tex_we = ft_new_texture(calcul, calcul->path_tex_we);
	calcul->tex_sp = ft_new_texture(calcul, calcul->path_sprite);
	if (calcul->save == 1)
	{
		ft_screenshot(calcul);
		ft_escape(calcul);
	}
	mlx_loop_hook(calcul->mlx, ft_run, calcul);
	mlx_loop(calcul->mlx);
}

static void	ft_key_events(t_calcul *calcul)
{
//	int		x;
//	int		y;

//	x = 0;
//	y = 0;
	if (!(calcul->mlx = mlx_init()))
		return ;
//	mlx_get_screen_size(calcul->mlx, &x, &y); // linux
//	calcul->w = (calcul->w > x) ? x : calcul->w; //
//	calcul->h = (calcul->h > y) ? y : calcul->h; //
	if (!(calcul->ZBuffer = malloc(sizeof(double) * calcul->w)))
		return ;
	if (calcul->save == 0)
	{
		if (!(calcul->win = mlx_new_window(calcul->mlx, calcul->w,
		calcul->h, "Cub3D")))
			return ;
		mlx_hook(calcul->win, KEYPRESS, KEYPRESSMASK, ft_key_press, calcul);
		mlx_hook(calcul->win, KEYRELEASE, KEYRELEASEMASK, ft_key_release,
		calcul);
		mlx_hook(calcul->win, EXITPRESS, EXITMASK, ft_escape, calcul);
	}
	ft_init_img(calcul);
}

void		ft_cub3d(t_calcul *calcul)
{
	int		first_display;

	first_display = true;
	calcul->w = ft_atoi(calcul->res_x);
	calcul->h = ft_atoi(calcul->res_y);
	free(calcul->res_x);
	free(calcul->res_y);
	if (calcul->up == true || calcul->down == true || calcul->left == true ||
		calcul->right == true || first_display == true)
	{
		first_display = false;
		ft_key_events(calcul);
	}
}

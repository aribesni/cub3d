/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <aribesni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 18:51:34 by aribesni          #+#    #+#             */
/*   Updated: 2021/04/13 10:54:39 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	ft_key_press(int keycode, t_calcul *calcul)
{
	if (keycode == UP)
		calcul->up = TRUE;
	if (keycode == DOWN)
		calcul->down = TRUE;
	if (keycode == RIGHT)
		calcul->right = TRUE;
	if (keycode == LEFT)
		calcul->left = TRUE;
	if (keycode == RTL)
		calcul->rt_left = TRUE;
	if (keycode == RTR)
		calcul->rt_right = TRUE;
	if (keycode == ESC)
		ft_escape(calcul);
	return (1);
}

static int	ft_key_release(int keycode, t_calcul *calcul)
{
	if (keycode == UP)
		calcul->up = FALSE;
	if (keycode == DOWN)
		calcul->down = FALSE;
	if (keycode == RIGHT)
		calcul->right = FALSE;
	if (keycode == LEFT)
		calcul->left = FALSE;
	if (keycode == RTL)
		calcul->rt_left = FALSE;
	if (keycode == RTR)
		calcul->rt_right = FALSE;
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
/*	int		x;
	int		y;

	x = 0;
	y = 0;
*/	if (!(calcul->mlx = mlx_init()))
		return ;
/*	mlx_get_screen_size(calcul->mlx, &x, &y);
	calcul->w = (calcul->w > x) ? x : calcul->w;
	calcul->h = (calcul->h > y) ? y : calcul->h;
*/	if (!(calcul->zbuffer = malloc(sizeof(double) * calcul->w)))
		return ;
	if (calcul->save == 0)
	{
		if (!(calcul->win = mlx_new_window(calcul->mlx, calcul->w,
		calcul->h, "Cub3D")))
			return ;
		mlx_hook(calcul->win, 2, (1L << 0), ft_key_press, calcul);
		mlx_hook(calcul->win, 3, (1L << 1), ft_key_release,
		calcul);
		mlx_hook(calcul->win, 33, (1L << 17), ft_escape, calcul);
	}
	ft_init_img(calcul);
}

void		ft_cub3d(t_calcul *calcul)
{
	int		first_display;

	first_display = TRUE;
	calcul->w = ft_atoi(calcul->res_x);
	calcul->h = ft_atoi(calcul->res_y);
	if (calcul->up == TRUE || calcul->down == TRUE || calcul->left == TRUE ||
		calcul->right == TRUE || first_display == TRUE)
	{
		first_display = FALSE;
		ft_key_events(calcul);
	}
}

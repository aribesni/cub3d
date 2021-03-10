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
	if (keycode == 13)
		calcul->up = true;
	if (keycode == 1)
		calcul->down = true;
	if (keycode == 2)
		calcul->right = true;
	if (keycode == 0)
		calcul->left = true;
	if (keycode == 123)
		calcul->rt_left = true;
	if (keycode == 124)
		calcul->rt_right = true;
	if (keycode == 53)
		ft_escape(calcul);
	return (1);
}

static int	ft_key_release(int keycode, t_calcul *calcul)
{
	if (keycode == 13)
		calcul->up = false;
	if (keycode == 1)
		calcul->down = false;
	if (keycode == 2)
		calcul->right = false;
	if (keycode == 0)
		calcul->left = false;
	if (keycode == 123)
		calcul->rt_left = false;
	if (keycode == 124)
		calcul->rt_right = false;
	return (1);
}

void		ft_key_events(t_calcul *calcul)
{
	if (!(calcul->mlx = mlx_init()))
		return ;
	if (calcul->save == 0)
	{
		if (!(calcul->win = mlx_new_window(calcul->mlx, calcul->w,
		calcul->h, "Cub3D")))
			return ;
		mlx_hook(calcul->win, KEYPRESS, KEYPRESSMASK, ft_key_press, calcul);
		mlx_hook(calcul->win, KEYRELEASE, KEYRELEASEMASK, ft_key_release,
		calcul);
		mlx_hook(calcul->win, 17, EXITMASK, ft_escape, calcul);
	}
	mlx_loop_hook(calcul->mlx, ft_run, calcul);
	mlx_loop(calcul->mlx);
}

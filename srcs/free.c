/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <aribesni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 18:51:56 by aribesni          #+#    #+#             */
/*   Updated: 2021/02/27 18:54:09 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	ft_free_mlx(t_calcul *calcul)
{
	if (calcul->save == 0)
	{
		mlx_clear_window(calcul->mlx, calcul->win);
		if (calcul->win)
			mlx_destroy_window(calcul->mlx, calcul->win);
	}
	mlx_destroy_display(calcul->mlx);
	if (calcul->mlx)
	{
		free(calcul->mlx);
		calcul->mlx = NULL;
	}
}

void		ft_free_path(t_calcul *calcul)
{
	if (calcul->path_tex_no)
	{
		free(calcul->path_tex_no);
		calcul->path_tex_no = NULL;
	}
	if (calcul->path_tex_so)
	{
		free(calcul->path_tex_so);
		calcul->path_tex_so = NULL;
	}
	if (calcul->path_tex_ea)
	{
		free(calcul->path_tex_ea);
		calcul->path_tex_ea = NULL;
	}
	if (calcul->path_tex_we)
	{
		free(calcul->path_tex_we);
		calcul->path_tex_we = NULL;
	}
	if (calcul->path_sprite)
	{
		free(calcul->path_sprite);
		calcul->sprite = NULL;
	}
}

void		ft_free_res(t_calcul *calcul)
{
	free(calcul->res_x);
	free(calcul->res_y);
}

void		ft_free(t_calcul *calcul)
{
	if (calcul->map)
	{
		ft_free_tab(calcul->map, calcul->mapH + 1);
		calcul->map = NULL;
	}
	if (calcul->ZBuffer)
	{
		free(calcul->ZBuffer);
		calcul->ZBuffer = NULL;
	}
	ft_free_path(calcul);
	ft_free_res(calcul);
	ft_free_img(calcul);
	ft_free_tex(calcul);
	ft_free_sprite(calcul);
}

int			ft_escape(t_calcul *calcul)
{
	ft_free(calcul);
	ft_free_mlx(calcul);
	exit(1);
	return (1);
}

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

void		ft_free_tab(char **tab, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static void	ft_free_3(t_calcul *calcul)
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

static void	ft_free_2(t_calcul *calcul)
{
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
	ft_free_img(calcul);
	ft_free_tex(calcul);
	ft_free_sprite(calcul);
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
	ft_free_2(calcul);
}

int			ft_escape(t_calcul *calcul)
{
	ft_free(calcul);
	ft_free_3(calcul);
	exit(1);
	return (1);
}

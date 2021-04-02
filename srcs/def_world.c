/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_world.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <aribesni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 18:40:19 by aribesni          #+#    #+#             */
/*   Updated: 2021/03/07 09:43:38 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	ft_s(t_calcul *calcul, int i, int j)
{
	if (calcul->read[i][j] == 'S' && calcul->read[i][j + 1] != 'O' &&
		calcul->read[i][j + 1] != ' ')
		ft_free_info(calcul, "File Error : Invalid Character");
	else if (calcul->read[i][j] == 'S' && calcul->read[i][j + 1] == 'O' &&
			calcul->count_tex_so == 0 && calcul->read[i][j + 2] == ' ')
	{
		calcul->path_tex_so = ft_get_path(calcul, i, j + 1);
		calcul->count_tex_so++;
	}
	else if (calcul->read[i][j] == 'S' && calcul->read[i][j + 1] != 'O' &&
			calcul->count_sprite == 0)
	{
		calcul->path_sprite = ft_get_path(calcul, i, j + 1);
		calcul->count_sprite++;
	}
	else
		ft_free_info(calcul, "File Error");
}

static void	ft_n_e_w(t_calcul *calcul, int i, int j, char c)
{
	if (c == 'N' && calcul->read[i][j + 2] == ' ')
	{
		calcul->path_tex_no = ft_get_path(calcul, i, j + 1);
		calcul->count_tex_no++;
	}
	else if (c == 'E' && calcul->read[i][j + 2] == ' ')
	{
		calcul->path_tex_ea = ft_get_path(calcul, i, j + 1);
		calcul->count_tex_ea++;
	}
	else if (c == 'W' && calcul->read[i][j + 2] == ' ')
	{
		calcul->path_tex_we = ft_get_path(calcul, i, j + 1);
		calcul->count_tex_we++;
	}
	else
		ft_free_info(calcul, "File Error : Invalid Character");
}

static void	ft_res(t_calcul *calcul, int i, int j)
{
	calcul->res_x = ft_get_res(calcul, i, &j);
	calcul->res_y = ft_get_res(calcul, i, &j);
	ft_file_error(calcul, i, j);
	calcul->count_res++;
}

static void	ft_browse_info(t_calcul *calcul, int i, int j)
{
	while (calcul->read[i][j] == ' ' && calcul->read[i][j])
		j++;
	if (calcul->read[i][j] == 'R' && calcul->count_res == 0 &&
		calcul->read[i][j + 1] == ' ')
		ft_res(calcul, i, j);
	else if ((calcul->read[i][j] == 'N' &&
	calcul->read[i][j + 1] == 'O' && calcul->count_tex_no == 0) ||
	(calcul->read[i][j] == 'E' && calcul->read[i][j + 1] == 'A' &&
	calcul->count_tex_ea == 0) || (calcul->read[i][j] == 'W' &&
	calcul->read[i][j + 1] == 'E' && calcul->count_tex_we == 0))
		ft_n_e_w(calcul, i, j, calcul->read[i][j]);
	else if (calcul->read[i][j] == 'S')
		ft_s(calcul, i, j);
	else if (((calcul->read[i][j] == 'C' && calcul->count_c == 0) ||
			(calcul->read[i][j] == 'F' && calcul->count_f == 0)) &&
			calcul->read[i][j + 1] == ' ')
		ft_floor_ceiling(calcul, i, j, calcul->read[i][j]);
	else if (calcul->read[i][j] == ' ' || calcul->read[i][j] == '\0')
		j = 0;
	else
		ft_free_info(calcul, "File Error : Invalid Character");
}

void		ft_def_world(t_calcul *calcul)
{
	int		i;

	i = -1;
	while (++i < calcul->start)
		ft_browse_info(calcul, i, 0);
}

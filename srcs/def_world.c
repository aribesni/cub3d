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
	int		size;

	size = ft_strlen(calcul->read[i] + j);
	if (calcul->read[i][j] == 'S' && calcul->read[i][j + 1] != 'O' &&
			calcul->read[i][j + 1] != ' ' && calcul->read[i][j + 1] != '.')
		ft_exit(calcul, "File Error");
	else if (calcul->read[i][j] == 'S' && calcul->read[i][j + 1] == 'O' &&
			calcul->count_tex_so == 0)
	{
		if (!(calcul->path_tex_so = (char*)malloc(sizeof(char) * size)))
			return ;
		ft_get_path(calcul, i, j, calcul->path_tex_so);
		calcul->count_tex_so++;
	}
	else if (calcul->read[i][j] == 'S' && calcul->read[i][j + 1] != 'O' &&
			calcul->count_sprite == 0)
	{
		if (!(calcul->path_sprite = (char*)malloc(sizeof(char) * size)))
			return ;
		ft_get_path(calcul, i, j, calcul->path_sprite);
		calcul->count_sprite++;
	}
	else
		ft_exit(calcul, "File Error");
}

static void	ft_n_e_w(t_calcul *calcul, int i, int j, char c)
{
	int		size;

	size = ft_strlen(calcul->read[i] + j);
	if (c == 'N')
	{
		if (!(calcul->path_tex_no = (char*)malloc(sizeof(char) * size)))
			return ;
		ft_get_path(calcul, i, j, calcul->path_tex_no);
		calcul->count_tex_no++;
	}
	if (c == 'E')
	{
		if (!(calcul->path_tex_ea = (char*)malloc(sizeof(char) * size)))
			return ;
		ft_get_path(calcul, i, j, calcul->path_tex_ea);
		calcul->count_tex_ea++;
	}
	if (c == 'W')
	{
		if (!(calcul->path_tex_we = (char*)malloc(sizeof(char) * size)))
			return ;
		ft_get_path(calcul, i, j, calcul->path_tex_we);
		calcul->count_tex_we++;
	}
}

static void	ft_res(t_calcul *calcul, int i, int j)
{
	int		size;

	size = ft_strlen(calcul->read[i] + j);
	if (!(calcul->res_x = (char*)malloc(sizeof(char) * size)))
		return ;
	ft_get_res(calcul, i, &j, calcul->res_x);
	if (!(calcul->res_y = (char*)malloc(sizeof(char) * size)))
		return ;
	ft_get_res(calcul, i, &j, calcul->res_y);
	ft_file_error(calcul, i, j);
	calcul->count_res++;
}

static void	ft_browse_info(t_calcul *calcul, int i, int j)
{
	while (calcul->read[i][j] == ' ' && calcul->read[i][j])
		j++;
	if (calcul->read[i][j] == 'R' && calcul->count_res == 0)
		ft_res(calcul, i, j);
	else if ((calcul->read[i][j] == 'N' &&
	calcul->read[i][j + 1] == 'O' && calcul->count_tex_no == 0) ||
	(calcul->read[i][j] == 'E' && calcul->read[i][j + 1] == 'A' &&
	calcul->count_tex_ea == 0) || (calcul->read[i][j] == 'W' &&
	calcul->read[i][j + 1] == 'E' && calcul->count_tex_we == 0))
		ft_n_e_w(calcul, i, j, calcul->read[i][j]);
	else if (calcul->read[i][j] == 'S')
		ft_s(calcul, i, j);
	else if ((calcul->read[i][j] == 'C' && calcul->count_c == 0) ||
			(calcul->read[i][j] == 'F' && calcul->count_f == 0))
		ft_floor_ceiling(calcul, i, j, calcul->read[i][j]);
	else if (calcul->read[i][j] == ' ' || calcul->read[i][j] == '\0')
		j = 0;
	else
		ft_exit(calcul, "File Error!!");
}

void		ft_def_world(t_calcul *calcul)
{
	int		i;
	int		j;

	i = -1;
	while (++i < calcul->start)
	{
		j = 0;
		ft_browse_info(calcul, i, j);
	}
}

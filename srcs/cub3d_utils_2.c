/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <aribesni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:12:46 by aribesni          #+#    #+#             */
/*   Updated: 2021/03/24 17:08:32 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		ft_free_data(t_calcul *calcul, char *res, char *str)
{
	ft_free_tab(calcul->read, calcul->read_h);
	free(res);
	ft_free(calcul);
	ft_exit(str);
}

char		*ft_extract_info(t_calcul *calcul, int i, int *j, char *res)
{
	int		k;

	k = 0;
	while (calcul->read[i][*j] >= '0' && calcul->read[i][*j] <= '9')
	{
		res[k] = calcul->read[i][*j];
		*j = *j + 1;
		k++;
	}
	res[k] = '\0';
	return (res);
}

void		ft_texture(t_calcul *calcul)
{
	double	wallx;

	wallx = 0.0;
	if (calcul->side == 0)
		wallx = calcul->raypos_y + calcul->perpwall * calcul->raydir_y;
	else
		wallx = calcul->raypos_x + calcul->perpwall * calcul->raydir_x;
	wallx -= (int)wallx;
	calcul->tex_x = (int)(wallx * 64);
	if (calcul->side == 0 && calcul->raydir_x > 0)
		calcul->tex_x = 64 - calcul->tex_x - 1;
	else if (calcul->side == 1 && calcul->raydir_x < 0)
		calcul->tex_x = 64 - calcul->tex_x - 1;
	calcul->step_tex = 1.0 * 64 / calcul->line_h;
	calcul->texpos = (calcul->drawstart - calcul->h / 2 + calcul->line_h / 2) *
	calcul->step_tex;
}

void		ft_spawn(t_calcul *calcul, char c, double x, double y)
{
	calcul->pos_x = y + 0.5;
	calcul->pos_y = x + 0.5;
	if (c == 'N')
	{
		calcul->dir_y = -1.0;
		calcul->plane_x = -0.80;
	}
	if (c == 'S')
	{
		calcul->dir_y = 1.0;
		calcul->plane_x = 0.80;
	}
	if (c == 'E')
	{
		calcul->dir_x = 1.0;
		calcul->plane_y = -0.80;
	}
	if (c == 'W')
	{
		calcul->dir_x = -1.0;
		calcul->plane_y = 0.80;
	}
}

void		ft_convert_endian(t_calcul *calcul, char c)
{
	int		temp;

	temp = calcul->bit_1 << 16;
	temp = temp | calcul->bit_2 << 8;
	temp = temp | calcul->bit_3;
	if (c == 'C')
		calcul->color_c = temp;
	if (c == 'F')
		calcul->color_f = temp;
}

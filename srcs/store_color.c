/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <aribesni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 19:04:07 by aribesni          #+#    #+#             */
/*   Updated: 2021/02/27 19:04:08 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	pixel_tex(t_texture *tex, t_calcul *calcul)
{
	calcul->color = tex->tex_data[tex->width * calcul->tex_y + calcul->tex_x];
}

static void	pix_color(t_calcul *calcul)
{
	if (calcul->side == 0)
	{
		if (calcul->stepx < 0)
			pixel_tex(calcul->tex_we, calcul);
		else
			pixel_tex(calcul->tex_ea, calcul);
	}
	else
	{
		if (calcul->stepy > 0)
			pixel_tex(calcul->tex_so, calcul);
		else
			pixel_tex(calcul->tex_no, calcul);
	}
}

void		ft_set_color(t_image *image, unsigned int color, int p_x, int p_y)
{
	if (p_y >= image->height || p_x >= image->width || p_x < 0 || p_y < 0)
		return ;
	image->img_data[p_y * image->width + p_x] = color;
}

int			ft_disp_col(t_calcul *calcul, int x)
{
	int		y;

	y = 0;
	while (y < calcul->drawstart)
		ft_set_color(calcul->image, calcul->color_c, x, y++);
	while (y >= calcul->drawstart && y <= calcul->drawend)
	{
		calcul->tex_y = (int)calcul->texpos & (64 - 1);
		calcul->texpos += calcul->step_tex;
		pix_color(calcul);
		ft_set_color(calcul->image, calcul->color, x, y);
		y++;
	}
	while (y < calcul->h)
		ft_set_color(calcul->image, calcul->color_f, x, y++);
	return (1);
}

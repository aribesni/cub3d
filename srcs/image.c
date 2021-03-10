/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <aribesni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 18:54:46 by aribesni          #+#    #+#             */
/*   Updated: 2021/02/27 21:30:20 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_texture		*ft_new_texture(t_calcul *calcul, char *path)
{
	t_texture	*tex;

	if (!(tex = malloc(sizeof(t_texture))))
		return (NULL);
	tex->tex_ptr = mlx_xpm_file_to_image(calcul->mlx, path, &tex->width,
	&tex->height);
	tex->tex_data = (int *)mlx_get_data_addr(tex->tex_ptr, &tex->bpp,
	&tex->size_line, &tex->endian);
	tex->height = 64;
	tex->width = 64;
	return (tex);
}

t_image			*ft_new_image(t_calcul *calcul)
{
	t_image		*image;

	if (!(image = malloc(sizeof(t_image))))
		return (NULL);
	image->img_ptr = mlx_new_image(calcul->mlx, calcul->w, calcul->h);
	image->img_data = (int *)mlx_get_data_addr(image->img_ptr, &image->bpp,
	&image->size_line, &image->endian);
	image->width = calcul->w;
	image->height = calcul->h;
	return (image);
}

void			ft_free_sprite(t_calcul *calcul)
{
	if (calcul->tex_sp)
	{
		mlx_destroy_image(calcul->mlx, calcul->tex_sp->tex_ptr);
		free(calcul->tex_sp);
		calcul->tex_sp = NULL;
	}
}

void			ft_free_tex(t_calcul *calcul)
{
	if (calcul->tex_no)
	{
		mlx_destroy_image(calcul->mlx, calcul->tex_no->tex_ptr);
		free(calcul->tex_no);
		calcul->tex_no = NULL;
	}
	if (calcul->tex_so)
	{
		mlx_destroy_image(calcul->mlx, calcul->tex_so->tex_ptr);
		free(calcul->tex_so);
		calcul->tex_so = NULL;
	}
	if (calcul->tex_ea)
	{
		mlx_destroy_image(calcul->mlx, calcul->tex_ea->tex_ptr);
		free(calcul->tex_ea);
		calcul->tex_ea = NULL;
	}
	if (calcul->tex_we)
	{
		mlx_destroy_image(calcul->mlx, calcul->tex_we->tex_ptr);
		free(calcul->tex_we);
		calcul->tex_we = NULL;
	}
}

void			ft_free_img(t_calcul *calcul)
{
	if (calcul->image)
	{
		mlx_destroy_image(calcul->mlx, calcul->image->img_ptr);
		free(calcul->image);
		calcul->image = NULL;
	}
}

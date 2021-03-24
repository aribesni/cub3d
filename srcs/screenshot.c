/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <aribesni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 18:56:40 by aribesni          #+#    #+#             */
/*   Updated: 2021/02/27 19:03:36 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void			ft_fill(t_calcul *calcul, t_save *save)
{
	int				i;
	int				j;
	int				k;
	int				fd;

	i = 0;
	j = 0;
	k = 0;
	fd = open("save.bmp", O_CREAT | O_RDWR | O_APPEND, 0644);
	while (j < calcul->h)
	{
		i = 0;
		while (i < calcul->w)
		{
			k = (calcul->h - 1 - j) * calcul->w + i;
			save->body[k] = calcul->image->img_data[i + (j * calcul->w)];
			i++;
		}
		j++;
	}
	write(fd, save->header, 54);
	write(fd, save->body, 4 * calcul->w * calcul->h);
	close(fd);
	free(save->header);
	free(save->body);
}

static void			ft_header(t_calcul *calcul, t_save *save)
{
	ft_memcpy(&save->header[0], &save->type, 2);
	ft_memcpy(&save->header[2], &save->bmp_size, 4);
	ft_memcpy(&save->header[10], &save->start, 4);
	ft_memcpy(&save->header[14], &save->hdr_size, 4);
	ft_memcpy(&save->header[18], &calcul->w, 4);
	ft_memcpy(&save->header[22], &calcul->h, 4);
	ft_memcpy(&save->header[26], &save->planes, 2);
	ft_memcpy(&save->header[28], &save->bpp, 2);
	ft_memcpy(&save->header[34], &save->raw_size, 4);
	ft_memcpy(&save->header[38], &save->res, 4);
	ft_memcpy(&save->header[42], &save->res, 4);
	ft_fill(calcul, save);
}

static void			ft_init_save(t_calcul *calcul, t_save *save)
{
	save->type = 0x4d42;
	save->bmp_size = 54 + 4 * calcul->w * calcul->h;
	save->start = 54;
	save->hdr_size = 40;
	save->planes = 1;
	save->bpp = 32;
	save->raw_size = 4 * calcul->w * calcul->h;
	save->res = 2835;
}

int					ft_screenshot(t_calcul *calcul)
{
	t_save			*save;

	if (!(save = malloc(sizeof(t_save))))
		return (-1);
	if (!(save->header = malloc(sizeof(unsigned char*) * 54)))
		return (-1);
	if (!(save->body = calloc(calcul->w * calcul->h, sizeof(int))))
		return (-1);
	ft_calculate(calcul);
	ft_init_save(calcul, save);
	ft_bzero(save->header, save->start);
	ft_bzero(save->body, calcul->w * calcul->h);
	ft_header(calcul, save);
	if (save)
	{
		free(save);
		save = NULL;
	}
	return (1);
}

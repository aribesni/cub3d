/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <aribesni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 18:54:41 by aribesni          #+#    #+#             */
/*   Updated: 2021/02/27 21:28:17 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		ft_get_rgb(char *color, unsigned char *bit)
{
	*bit = ft_atoi(color);
	free(color);
}

void		ft_get_res(t_calcul *calcul, int i, int *j, char *res)
{
	int		k;

	k = 0;
	while ((calcul->read[i][*j] < '0' || calcul->read[i][*j] > '9'))
		*j = *j + 1;
	while (calcul->read[i][*j] >= '0' && calcul->read[i][*j] <= '9')
	{
		res[k] = calcul->read[i][*j];
		*j = *j + 1;
		k++;
	}
	res[k] = '\0';
}

void		ft_floor_ceiling(t_calcul *calcul, int i, int j, char c)
{
	int		size;

	size = ft_strlen(calcul->read[i] + j);
	if (!(calcul->color_temp = (char*)malloc(sizeof(char) * size)))
		return ;
	ft_get_res(calcul, i, &j, calcul->color_temp);
	ft_get_rgb(calcul->color_temp, &calcul->bit_1);
	if (!(calcul->color_temp = (char*)malloc(sizeof(char) * size)))
		return ;
	ft_get_res(calcul, i, &j, calcul->color_temp);
	ft_get_rgb(calcul->color_temp, &calcul->bit_2);
	if (!(calcul->color_temp = (char*)malloc(sizeof(char) * size)))
		return ;
	ft_get_res(calcul, i, &j, calcul->color_temp);
	ft_get_rgb(calcul->color_temp, &calcul->bit_3);
	ft_file_error(calcul, i, j);
	ft_convert_endian(calcul, c);
	calcul->count_c += (c == 'C') ? 1 : 0;
	calcul->count_f += (c == 'F') ? 1 : 0;
}

void		ft_get_path(t_calcul *calcul, int i, int j, char *path)
{
	int		k;

	k = 0;
	j++;
	if (calcul->read[i][j] == 'E' || calcul->read[i][j] == 'O' ||
		calcul->read[i][j] == 'A')
		j++;
	while (calcul->read[i][j] != '.' && calcul->read[i][j])
	{
		if (calcul->read[i][j] != ' ')
			ft_exit(calcul, "File Error");
		else
			j++;
	}
	if (calcul->read[i][j] == '.')
	{
		while (calcul->read[i][j] != ' ' && calcul->read[i][j] != '\t' &&
		calcul->read[i][j] != '\n' && calcul->read[i][j] != '\v' &&
		calcul->read[i][j] != '\f' && calcul->read[i][j] != '\r' &&
		calcul->read[i][j])
			path[k++] = calcul->read[i][j++];
	}
	path[k] = '\0';
	ft_file_error(calcul, i, j);
	ft_check_path(calcul, path);
}

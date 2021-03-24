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

char		*ft_get_res(t_calcul *calcul, int i, int *j)
{
	int		k;
	int		size;
	char	*res;

	k = 0;
	size = ft_strlen(calcul->read[i] + *j);
	if (!(res = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	while ((calcul->read[i][*j] < '0' || calcul->read[i][*j] > '9'))
		*j = *j + 1;
	while (calcul->read[i][*j] >= '0' && calcul->read[i][*j] <= '9')
	{
		res[k] = calcul->read[i][*j];
		*j = *j + 1;
		k++;
	}
	res[k] = '\0';
	return (res);
}

void		ft_floor_ceiling(t_calcul *calcul, int i, int j, char c)
{
	calcul->color_temp = ft_get_res(calcul, i, &j);
	ft_get_rgb(calcul->color_temp, &calcul->bit_1);
	calcul->color_temp = ft_get_res(calcul, i, &j);
	ft_get_rgb(calcul->color_temp, &calcul->bit_2);
	calcul->color_temp = ft_get_res(calcul, i, &j);
	ft_get_rgb(calcul->color_temp, &calcul->bit_3);
	ft_file_error(calcul, i, j);
	ft_convert_endian(calcul, c);
	calcul->count_c += (c == 'C') ? 1 : 0;
	calcul->count_f += (c == 'F') ? 1 : 0;
}

static void	ft_get_path_2(t_calcul *calcul, int *i, int *j)
{
	while (calcul->read[*i][*j] != '.' && calcul->read[*i][*j])
	{
		if (calcul->read[*i][*j] != ' ')
			ft_exit("File Error : Invalid Character");
		else
			*j = *j + 1;
	}
}

char		*ft_get_path(t_calcul *calcul, int i, int j)
{
	int		k;
	char	*path;
	int		size;

	k = 0;
	size = ft_strlen(calcul->read[i] + j);
	j++;
	if (!(path = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	if (calcul->read[i][j] == 'E' || calcul->read[i][j] == 'O' ||
		calcul->read[i][j] == 'A')
		j++;
	ft_get_path_2(calcul, &i, &j);
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
	ft_check_path(path);
	return (path);
}

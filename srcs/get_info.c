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

void		ft_get_rgb(t_calcul *calcul, char *color, unsigned char *bit)
{
	if (ft_atoi(color) < 0 || ft_atoi(color) > 255)
	{
		ft_free_tab(calcul->read, calcul->read_h);
		ft_free(calcul);
		ft_exit("Color Error");
	}
	*bit = ft_atoi(color);
	free(color);
}

char		*ft_get_res(t_calcul *calcul, int i, int *j)
{
	int		size;
	int		temp;
	char	*res;

	temp = 0;
	size = ft_strlen(calcul->read[i] + *j);
	if (!(res = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	temp += (*j == 0) ? 1 : 0;
	*j = *j + 1;
	if (temp == 1 && ft_is_space(calcul->read[i][*j]) == 0)
		ft_free_data(calcul, res, "Resolution Error");
	while (ft_is_space(calcul->read[i][*j]) == 1)
		*j = *j + 1;
	if (calcul->read[i][*j] < '0' || calcul->read[i][*j] > '9')
		ft_free_data(calcul, res, "Resolution Error");
	return (ft_extract_info(calcul, i, j, res));
}

static char	*ft_get_color(t_calcul *calcul, int i, int *j)
{
	int		size;
	int		temp;
	int		comma;
	char	*res;

	comma = 0;
	temp = 0;
	size = ft_strlen(calcul->read[i] + *j);
	if (!(res = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	temp += (*j == 0) ? 1 : 0;
	*j = *j + 1;
	if (temp == 1 && ft_is_space(calcul->read[i][*j]) == 0)
		ft_free_data(calcul, res, "Color Error");
	while (ft_is_space(calcul->read[i][*j]) == 1 || calcul->read[i][*j] == ',')
	{
		if (calcul->read[i][*j] == ',')
			comma++;
		*j = *j + 1;
	}
	if ((temp == 0 && comma > 1) || (temp == 1 && comma > 0))
		ft_free_data(calcul, res, "Color Error");
	return (ft_extract_info(calcul, i, j, res));
}

void		ft_floor_ceiling(t_calcul *calcul, int i, int j, char c)
{
	calcul->color_temp = ft_get_color(calcul, i, &j);
	ft_get_rgb(calcul, calcul->color_temp, &calcul->bit_1);
	calcul->color_temp = ft_get_color(calcul, i, &j);
	ft_get_rgb(calcul, calcul->color_temp, &calcul->bit_2);
	calcul->color_temp = ft_get_color(calcul, i, &j);
	ft_get_rgb(calcul, calcul->color_temp, &calcul->bit_3);
	if (ft_file_error(calcul, i, j) == 0)
	{
		ft_free_tab(calcul->read, calcul->read_h);
		ft_free(calcul);
		ft_exit("Color Error");
	}
	ft_convert_endian(calcul, c);
	calcul->count_c += (c == 'C') ? 1 : 0;
	calcul->count_f += (c == 'F') ? 1 : 0;
}

char		*ft_get_path(t_calcul *calcul, int i, int j)
{
	int		k;
	char	*path;
	int		size;

	k = 0;
	size = ft_strlen(calcul->read[i] + j);
	if (!(path = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	if (calcul->read[i][j] == 'E' || calcul->read[i][j] == 'O' ||
		calcul->read[i][j] == 'A')
		j++;
	while (ft_is_space(calcul->read[i][j]) == 1 && calcul->read[i][j])
		j++;
	if (ft_is_space(calcul->read[i][j]) == 0)
	{
		while (ft_is_space(calcul->read[i][j]) == 0 && calcul->read[i][j])
			path[k++] = calcul->read[i][j++];
	}
	path[k] = '\0';
	if (ft_file_error(calcul, i, j) == 0 || ft_check_path(path) == 0)
		ft_free_get_path(calcul, path, "File Error : Invalid Character");
	return (path);
}

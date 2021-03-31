/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <aribesni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 18:51:13 by aribesni          #+#    #+#             */
/*   Updated: 2021/02/27 19:26:15 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	ft_parse_map_3(t_calcul *calcul, int i, int j)
{
	if (calcul->map[i][j] == 'N' || calcul->map[i][j] == 'S' ||
		calcul->map[i][j] == 'E' || calcul->map[i][j] == 'W')
	{
		if (calcul->count_pos == 0)
			ft_spawn(calcul, calcul->read[calcul->start][j],
			(double)i, (double)j);
		else
			ft_free_map(calcul, i, "Error In Spawn Position");
		calcul->map[i][j] = '0';
		calcul->count_pos++;
	}
}

static void	ft_parse_map_2(t_calcul *calcul, int i, int j, int count)
{
	if (calcul->read[calcul->start][j] == 'N' ||
		calcul->read[calcul->start][j] == 'S' ||
		calcul->read[calcul->start][j] == 'E' ||
		calcul->read[calcul->start][j] == 'W' ||
		calcul->read[calcul->start][j] == '0' ||
		calcul->read[calcul->start][j] == '2')
	{
		if (i == 0 || i == count - 1 ||
			calcul->read[calcul->start - 1][j] == ' ' ||
			calcul->read[calcul->start - 1][j] == '\0' ||
			calcul->read[calcul->start + 1][j] == ' ' ||
			calcul->read[calcul->start + 1][j] == '\0' ||
			calcul->read[calcul->start][j - 1] == ' ' ||
			calcul->read[calcul->start][j - 1] == '\0' ||
			calcul->read[calcul->start][j + 1] == ' ' ||
			calcul->read[calcul->start][j + 1] == '\0')
			ft_free_map(calcul, i, "Invalid Space in Map");
	}
	ft_parse_map_3(calcul, i, j);
}

static void	ft_parse_map(t_calcul *calcul, int i, int j, int count)
{
	calcul->sp_count += (calcul->read[calcul->start][j] == '2') ? 1 : 0;
	if (calcul->map[i][j] == ' ')
	{
		if ((calcul->read[calcul->start - 1][j] != '1' &&
			calcul->read[calcul->start - 1][j] != ' ' &&
			calcul->read[calcul->start + 1][j] != '1' &&
			calcul->read[calcul->start + 1][j] != ' ' &&
			calcul->read[calcul->start][j - 1] != '1' &&
			calcul->read[calcul->start][j - 1] != ' ' &&
			calcul->read[calcul->start][j + 1] != '1' &&
			calcul->read[calcul->start][j + 1] != ' '))
			ft_free_map(calcul, i, "Invalid Space In Map");
	}
	if (calcul->map[i][j] != 'N' && calcul->map[i][j] != 'S' &&
		calcul->map[i][j] != 'E' && calcul->map[i][j] != 'W' &&
		calcul->map[i][j] != '0' && calcul->map[i][j] != '1' &&
		calcul->map[i][j] != '2' && calcul->map[i][j] != ' ')
		ft_free_map(calcul, i, "Invalid Character In Map");
	ft_parse_map_2(calcul, i, j, count);
}

static int	ft_fill_map(t_calcul *calcul, int i, int j, int count)
{
	int		size;

	ft_printf("COUNT : %i\n", count);
	while (++i < count)
	{
		size = ft_strlen(calcul->read[calcul->start]);
		if (!(calcul->map[i] = (char*)malloc(sizeof(char) * size + 1)))
			return (-1);
		while (calcul->read[calcul->start][j] != '1' &&
		calcul->read[calcul->start][j] == ' ')
			calcul->map[i][j++] = ' ';
		if (calcul->read[calcul->start][j] != '1')
			ft_free_map(calcul, i, "Map Not Closed");
		while (calcul->read[calcul->start][j])
		{
			calcul->map[i][j] = calcul->read[calcul->start][j];
			ft_parse_map(calcul, i, j, count);
			j++;
		}
		calcul->map[i][j] = '\0';
		j = 0;
		calcul->start++;
	}
	return (1);
}

int			ft_create_map(t_calcul *calcul, int count)
{
	int		i;
	int		j;
	int		size;

	i = -1;
	j = 0;
	size = count;
	count -= calcul->start;
	calcul->sp_count = 0;
	calcul->count_pos = 0;
	if (!(calcul->map = (char**)malloc(sizeof(char*) * count)))
		return (-1);
	ft_fill_map(calcul, i, j, count);
	ft_free_tab(calcul->read, size);
	ft_cub3d(calcul);
	return (0);
}

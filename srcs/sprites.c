/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <aribesni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 19:03:53 by aribesni          #+#    #+#             */
/*   Updated: 2021/02/27 19:04:02 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	ft_sort_sprites(double *dist, int *order, int count)
{
	int		i;
	int		temp;
	double	temp2;

	i = 0;
	temp = 0;
	temp2 = 0.0;
	while (i < count - 1)
	{
		if (dist[i] < dist[i + 1])
		{
			temp2 = dist[i + 1];
			dist[i + 1] = dist[i];
			dist[i] = temp2;
			temp = order[i + 1];
			order[i + 1] = order[i];
			order[i] = temp;
			i = 0;
		}
		else
			i++;
	}
}

static void	ft_order_sprite(t_calcul *calcul)
{
	int		i;

	i = 0;
	while (i < calcul->sp_count)
	{
		calcul->order[i] = i;
		calcul->dist[i] = ((calcul->posX - calcul->sprite[i].x) *
		(calcul->posX - calcul->sprite[i].x) +
		(calcul->posY - calcul->sprite[i].y) *
		(calcul->posY - calcul->sprite[i].y));
		i++;
	}
	ft_sort_sprites(calcul->dist, calcul->order, calcul->sp_count);
	ft_add_sprite(calcul);
}

static void	ft_place_sprite(t_calcul *calcul)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	x = 0;
	y = 0;
	while (y < calcul->mapH)
	{
		x = 0;
		while (x < ft_strlen(calcul->map[y]))
		{
			if (calcul->map[y][x] == '2')
			{
				calcul->sprite[i].x = (double)x + 0.5;
				calcul->sprite[i].y = (double)y + 0.5;
				i++;
			}
			x++;
		}
		y++;
	}
}

int			ft_init_sprite(t_calcul *calcul)
{
	if (!(calcul->sprite = malloc(sizeof(t_sprite) * calcul->sp_count)))
		return (-1);
	if (!(calcul->dist = malloc(sizeof(double) * calcul->sp_count)))
		return (-1);
	if (!(calcul->order = malloc(sizeof(int) * calcul->sp_count)))
		return (-1);
	ft_place_sprite(calcul);
	ft_order_sprite(calcul);
	if (calcul->sprite)
	{
		free(calcul->sprite);
		calcul->sprite = NULL;
	}
	if (calcul->dist)
	{
		free(calcul->dist);
		calcul->dist = NULL;
	}
	if (calcul->order)
	{
		free(calcul->order);
		calcul->order = NULL;
	}
	return (1);
}

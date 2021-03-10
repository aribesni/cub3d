/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <aribesni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 19:03:48 by aribesni          #+#    #+#             */
/*   Updated: 2021/02/27 21:59:46 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_spawn(t_calcul *calcul, char c, double x, double y)
{
	calcul->posX = y + 0.5;
	calcul->posY = x + 0.5;
	if (c == 'N')
	{
		calcul->dirY = -1.0;
		calcul->planeX = -0.80;
	}
	if (c == 'S')
	{
		calcul->dirY = 1.0;
		calcul->planeX = 0.80;
	}
	if (c == 'E')
	{
		calcul->dirX = 1.0;
		calcul->planeY = -0.80;
	}
	if (c == 'W')
	{
		calcul->dirX = -1.0;
		calcul->planeY = 0.80;
	}
}

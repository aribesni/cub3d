/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <aribesni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 18:54:59 by aribesni          #+#    #+#             */
/*   Updated: 2021/02/27 18:55:11 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		ft_init(t_calcul *calcul)
{
	calcul->w = ft_atoi(calcul->res_x);
	calcul->h = ft_atoi(calcul->res_y);
	free(calcul->res_x);
	free(calcul->res_y);
	calcul->movSpeed = 0.15;
	calcul->rotSpeed = 0.5;
	calcul->up = 0;
	calcul->down = 0;
	calcul->left = 0;
	calcul->right = 0;
	calcul->rt_left = 0;
	calcul->rt_right = 0;
	if (!(calcul->ZBuffer = malloc(sizeof(double) * calcul->w)))
		return (-1);
	return (1);
}

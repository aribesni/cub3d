/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <aribesni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 19:04:32 by aribesni          #+#    #+#             */
/*   Updated: 2021/02/27 19:04:35 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		ft_texture(t_calcul *calcul)
{
	double	wallx;

	wallx = 0.0;
	if (calcul->side == 0)
		wallx = calcul->rayPosY + calcul->perpWall * calcul->rayDirY;
	else
		wallx = calcul->rayPosX + calcul->perpWall * calcul->rayDirX;
	wallx -= (int)wallx;
	calcul->texX = (int)(wallx * 64);
	if (calcul->side == 0 && calcul->rayDirX > 0)
		calcul->texX = 64 - calcul->texX - 1;
	else if (calcul->side == 1 && calcul->rayDirX < 0)
		calcul->texX = 64 - calcul->texX - 1;
	calcul->step_tex = 1.0 * 64 / calcul->lineH;
	calcul->texPos = (calcul->drawStart - calcul->h / 2 + calcul->lineH / 2) *
	calcul->step_tex;
}

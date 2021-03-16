/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_endian.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <aribesni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 18:50:35 by aribesni          #+#    #+#             */
/*   Updated: 2021/02/27 19:10:13 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		ft_convert_endian(t_calcul *calcul, char c)
{
	int		temp;

	temp = calcul->bit_1 << 16;
	temp = temp | calcul->bit_2 << 8;
	temp = temp | calcul->bit_3;
	if (c == 'C')
		calcul->color_c = temp;
	if (c == 'F')
		calcul->color_f = temp;
}

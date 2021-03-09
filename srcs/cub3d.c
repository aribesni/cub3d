/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <aribesni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 18:51:34 by aribesni          #+#    #+#             */
/*   Updated: 2021/02/27 18:51:39 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_cub3d(t_calcul *calcul)
{
	int		first_display;

	first_display = true;
	ft_init(calcul);
	if (calcul->up == true || calcul->down == true || calcul->left == true ||
		calcul->right == true || first_display == true)
	{
		first_display = false;
		ft_key_events(calcul);
	}
}
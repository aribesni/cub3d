/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <aribesni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 21:26:13 by aribesni          #+#    #+#             */
/*   Updated: 2021/02/27 21:26:16 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_file_error(t_calcul *calcul, int i, int j)
{
	while (calcul->read[i][j])
	{
		if (calcul->read[i][j] != ' ')
			ft_exit("File Error");
		j++;
	}
}

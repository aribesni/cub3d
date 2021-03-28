/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <aribesni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 14:59:25 by aribesni          #+#    #+#             */
/*   Updated: 2021/03/28 14:59:28 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		ft_free_get_path(t_calcul *calcul, char *path, char *str)
{
	ft_free_tab(calcul->read, calcul->readH);
	ft_free_res(calcul);
	free(path);
	ft_exit(str);
}

void		ft_free_tab(char **tab, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void		ft_free_info(t_calcul *calcul, char *str)
{
	ft_free_tab(calcul->read, calcul->readH);
	ft_free(calcul);
	ft_exit(str);
}

void		ft_free_map(t_calcul *calcul, int i, char *str)
{
	ft_free_res(calcul);
	ft_free_path(calcul);
	ft_free_tab(calcul->read, calcul->readH);
	ft_free_tab(calcul->map, i + 1);
	ft_exit(str);
}

void		ft_exit(char *str)
{
	ft_putendl("Error");
	ft_putendl(str);
	exit(1);
}

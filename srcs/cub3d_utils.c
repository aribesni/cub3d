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

#include "cub.h"

void		ft_check_path(char *path)
{
	int		fd;
	int		i;

	i = ft_strlen(path);
	fd = open(path, O_RDONLY);
	if (fd == -1 || (path[i - 1] != 'm' && path[i - 2] != 'p' &&
		path[i - 3] != 'x' && path[i - 4] != '.'))
	{
		close(fd);
		ft_exit("Path Error");
	}
}

static void	ft_free_arg(t_calcul *calcul, int count, char *str)
{
	ft_free(calcul);
	ft_free_tab(calcul->read, count);
	free(calcul->res_x);
	free(calcul->res_y);
	if (calcul->mlx)
	{
		free(calcul->mlx);
		calcul->mlx = NULL;
	}
	ft_exit(str);
}

void		ft_arg(t_calcul *calcul, int argc, char **argv, int count)
{
	if (argc >= 3)
	{
		if (argc > 3)
			ft_free_arg(calcul, count, "Too many arguments");
		if (ft_strcmp(argv[2], "-save") == 0)
			calcul->save = 1;
		else
			ft_free_arg(calcul, count, "Invalid Argument");
	}
}

void		ft_file_error(t_calcul *calcul, int i, int j)
{
	while (calcul->read[i][j])
	{
		if (calcul->read[i][j] != ' ')
			ft_exit("File Error");
		j++;
	}
}

void		ft_exit(char *str)
{
	ft_putendl("Error");
	ft_putendl(str);
	exit(1);
}

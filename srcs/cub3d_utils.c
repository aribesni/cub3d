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

void		ft_init(t_calcul *calcul)
{
	ft_bzero(calcul, sizeof(t_calcul));
	calcul->movspeed = 0.15;
	calcul->rotspeed = 0.5;
	calcul->up = 0;
	calcul->down = 0;
	calcul->left = 0;
	calcul->right = 0;
	calcul->rt_left = 0;
	calcul->rt_right = 0;
	calcul->color = 0;
	calcul->color_c = 0;
	calcul->color_f = 0;
	calcul->save = 0;
	calcul->start = 0;
	calcul->count_res = 0;
	calcul->count_tex_no = 0;
	calcul->count_tex_so = 0;
	calcul->count_tex_ea = 0;
	calcul->count_tex_we = 0;
	calcul->count_sprite = 0;
	calcul->count_c = 0;
	calcul->count_f = 0;
	calcul->bit_1 = 0;
	calcul->bit_2 = 0;
	calcul->bit_3 = 0;
}

int			ft_check_path(char *path)
{
	int		fd;
	int		i;

	i = ft_strlen(path);
	fd = open(path, O_RDONLY);
	if (fd == -1 || (path[i - 1] != 'm' && path[i - 2] != 'p' &&
		path[i - 3] != 'x' && path[i - 4] != '.'))
	{
		close(fd);
		return (0);
	}
	return (1);
}

void		ft_arg(t_calcul *calcul, int argc, char **argv)
{
	int		size;

	size = ft_strlen(argv[1]) - 4;
	if (size < 0)
		ft_exit("File Name Incorrect");
	if (argc >= 3)
	{
		if (argc > 3)
			ft_exit("Too many arguments");
		if (ft_strcmp(argv[2], "-save") == 0)
			calcul->save = 1;
		else
			ft_exit("Invalid Argument");
	}
	if (ft_strcmp(argv[1] + size, ".cub"))
		ft_exit("File Name Incorrect");
}

int			ft_file_error(t_calcul *calcul, int i, int j)
{
	while (calcul->read[i][j])
	{
		if (ft_is_space(calcul->read[i][j]) == 0)
			return (0);
		j++;
	}
	return (1);
}

int			ft_is_space(char c)
{
	if (c == ' ' || c == '\t' ||
		c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

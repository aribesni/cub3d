/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <aribesni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 18:55:43 by aribesni          #+#    #+#             */
/*   Updated: 2021/02/27 18:55:59 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void		ft_read_file_3(t_calcul *calcul, int j)
{
	int			width;

	width = 0;
	if (calcul->read[calcul->start][j] != '1')
	{
		ft_free_tab(calcul->read, calcul->count);
		ft_exit("Map Not Closed");
	}
	ft_def_world(calcul);
	if (calcul->count_res != 1 || calcul->count_tex_no != 1 ||
		calcul->count_tex_so != 1 || calcul->count_tex_ea != 1 ||
		calcul->count_tex_we != 1 || calcul->count_sprite != 1 ||
		calcul->count_c != 1 || calcul->count_f != 1)
	{
		ft_free_tab(calcul->read, calcul->count);
		ft_exit("File Error");
	}
	calcul->readH = calcul->count;
	width = calcul->count - calcul->start;
	calcul->mapH = --width;
}

static void		ft_read_file_2(t_calcul *calcul, int fd, int tmp, char *line)
{
	int			j;

	j = 0;
	if (tmp == 0)
	{
		get_next_line(fd, &line);
		free(line);
	}
	while (calcul->start < calcul->count - 1)
	{
		j = 0;
		while (calcul->read[calcul->start][j] &&
		calcul->read[calcul->start][j] == ' ')
			j++;
		if (calcul->read[calcul->start][j] == '1')
			break ;
		calcul->start++;
	}
	ft_read_file_3(calcul, j);
}

static int		ft_read_file(t_calcul *calcul, int fd, int tmp)
{
	int			i;
	int			j;
	char		*line;

	i = -1;
	j = -1;
	if (!(calcul->read = malloc(sizeof(char*) * calcul->count)))
		return (-1);
	while (++i < calcul->count)
	{
		get_next_line(fd, &line);
		if (!(calcul->read[i] = (char*)malloc(sizeof(char) *
			calcul->size_max + 1)))
			return (-1);
		while (++j < ft_strlen(line))
			calcul->read[i][j] = line[j];
		while (j < calcul->size_max)
			calcul->read[i][j++] = ' ';
		free(line);
		calcul->read[i][j] = '\0';
		j = -1;
	}
	ft_read_file_2(calcul, fd, tmp, line);
	return (1);
}

static void		ft_set_file(t_calcul *calcul, int fd, int *tmp)
{
	int			ret;
	char		*line;

	while (get_next_line(fd, &line))
	{
		ret = ft_strlen(line);
		if (ret > calcul->size_max)
			calcul->size_max = ret;
		calcul->count++;
		free(line);
	}
	if (line && line[0] != '\0')
	{
		ret = ft_strlen(line);
		if (ret > calcul->size_max)
			calcul->size_max = ret;
		calcul->count++;
		*tmp = *tmp + 1;
	}
	free(line);
}

int				main(int argc, char **argv)
{
	int			fd;
	int			tmp;
	t_calcul	calcul;

	calcul.count = 0;
	tmp = 0;
	if (argc == 1)
		ft_exit("Missing Argument");
	fd = open(argv[1], O_RDONLY);
	ft_init(&calcul);
	if (fd < 0)
		ft_exit("Invalid Argument");
	calcul.size_max = 0;
	ft_set_file(&calcul, fd, &tmp);
	if (calcul.count == 0)
		ft_exit("Empty File");
	fd = open(argv[1], O_RDONLY);
	ft_arg(&calcul, argc, argv);
	ft_read_file(&calcul, fd, tmp);
	ft_create_map(&calcul);
	return (0);
}

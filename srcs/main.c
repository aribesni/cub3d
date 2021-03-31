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

static void		ft_read_file_3(t_calcul *calcul, int j, int count)
{
	int			width;

	width = 0;
	if (calcul->read[calcul->start][j] != '1')
	{
		ft_free_tab(calcul->read, count);
		ft_exit("Map Not Closed");
	}
	ft_def_world(calcul);
	if (calcul->count_res != 1 || calcul->count_tex_no != 1 ||
		calcul->count_tex_so != 1 || calcul->count_tex_ea != 1 ||
		calcul->count_tex_we != 1 || calcul->count_sprite != 1 ||
		calcul->count_c != 1 || calcul->count_f != 1)
	{
		ft_free_tab(calcul->read, count);
		ft_exit("File Error");
	}
	calcul->readH = count;
	width = count - calcul->start;
	calcul->mapH = --width;
}

static void		ft_read_file_2(t_calcul *calcul, int count)
{
	int			j;

	j = 0;
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
	while (calcul->start < count - 1)
	{
		j = 0;
		while (calcul->read[calcul->start][j] &&
		calcul->read[calcul->start][j] == ' ')
			j++;
		if (calcul->read[calcul->start][j] == '1')
			break ;
		calcul->start++;
	}
	ft_read_file_3(calcul, j, count);
}

static int		ft_read_file(t_calcul *calcul, int fd, int count, char *line)
{
	int			i;
	int			j;
	int			ret;

	i = 0;
	j = 0;
	if (!(calcul->read = malloc(sizeof(char*) * count)))
		return (-1);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
	//	get_next_line(fd, &line);
		if (!(calcul->read[i] = (char*)malloc(sizeof(char) *
			ft_strlen(line) + 1)))
			return (-1);
		while (j < ft_strlen(line))
		{
			calcul->read[i][j] = line[j];
			j++;
		}
		free(line);
		calcul->read[i][j] = '\0';
		j = 0;
		i++;
	}
	ft_read_file_2(calcul, count);
	return (1);
}

int				main(int argc, char **argv)
{
	int			fd;
	int			count;
	int			ret;
	char		*line;
	t_calcul	calcul;

	count = 0;
	if (argc == 1)
		ft_exit("Missing Argument");
	fd = open(argv[1], O_RDONLY);
	ft_init(&calcul);
	if (fd < 0)
		ft_exit("Invalid Argument");
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		count++;
		free(line);
	}
//	count += (line[0] == '\0') ? 0 : 1;
//	count++;
	free(line);
	if (count == 0)
		ft_exit("Empty File");
	fd = open(argv[1], O_RDONLY);
	ft_arg(&calcul, argc, argv);
	ft_read_file(&calcul, fd, count, line);
	ft_create_map(&calcul, count);
	return (0);
}

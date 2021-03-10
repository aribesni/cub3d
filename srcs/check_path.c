/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <aribesni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 21:36:59 by aribesni          #+#    #+#             */
/*   Updated: 2021/02/26 21:37:47 by aribesni         ###   ########.fr       */
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

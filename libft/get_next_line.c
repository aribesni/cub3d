/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 16:21:10 by aribesni          #+#    #+#             */
/*   Updated: 2019/11/16 16:23:04 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_next_line(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (i);
}

char		*ft_line(char *line, char **str)
{
	char	*s1;

	if (ft_strchr(*str, '\n'))
	{
		line = ft_substr(*str, 0, ft_next_line(*str));
		s1 = *str;
		*str = ft_substr(s1, ft_next_line(s1) + 1, ft_strlen(s1));
		free(s1);
	}
	else
	{
		line = ft_strdup(*str);
		free(*str);
		*str = NULL;
	}
	return (line);
}

int			get_next_line(int fd, char **line)
{
	char		buff[BUFFER_SIZE + 1];
	int			ret;
	static char	*str = NULL;
	char		*keep;

	if (fd == -1 || !line || BUFFER_SIZE <= 0)
		return (-1);
	ret = 0;
	while (!(ft_strchr(str, '\n')) && (ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';
		keep = str;
		str = ft_strjoin(keep, buff);
		free(keep);
	}
	if ((ret == -1) || (!(*line = ft_line(*line, &str))))
		return (-1);
	if (!(str))
		return (0);
	return (1);
}

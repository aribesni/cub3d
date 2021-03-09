/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 13:47:29 by aribesni          #+#    #+#             */
/*   Updated: 2019/10/25 15:08:47 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_set(const char *set, char c)
{
	int		i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		else
			i++;
	}
	return (0);
}

char		*ft_strtrim(const char *str, const char *set)
{
	int		i;
	int		j;
	int		len;
	char	*dest;

	i = 0;
	len = ft_strlen(str);
	j = len - 1;
	while (str[i] && ft_check_set(set, str[i]) == 1)
	{
		i++;
		len--;
	}
	while (j >= 0 && ft_check_set(set, str[j]) == 1 && len > 0)
	{
		len--;
		j--;
	}
	if (!(dest = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	len = 0;
	while (i <= j)
		dest[len++] = str[i++];
	dest[len] = '\0';
	return (dest);
}

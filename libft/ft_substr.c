/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 10:24:30 by aribesni          #+#    #+#             */
/*   Updated: 2019/10/25 15:09:01 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *str, unsigned int start, size_t len)
{
	size_t	i;
	char	*cpy;

	if (!str)
		return (NULL);
	if (!len || (ft_strlen(str) < (int)start))
	{
		if (!(cpy = (char*)malloc(sizeof(char))))
			return (NULL);
		cpy[0] = '\0';
		return (cpy);
	}
	if (!(cpy = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len && str[start])
		cpy[i++] = str[start++];
	cpy[i] = '\0';
	return (cpy);
}

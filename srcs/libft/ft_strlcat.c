/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 11:46:51 by aribesni          #+#    #+#             */
/*   Updated: 2019/10/25 15:18:01 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	lendest;
	size_t	lensrc;
	size_t	i;

	lendest = ft_strlen(dest);
	lensrc = ft_strlen(src);
	i = 0;
	if (destsize > lendest)
	{
		while (src[i] && i < destsize - lendest - 1)
		{
			dest[lendest + i] = src[i];
			i++;
		}
		dest[lendest + i] = '\0';
	}
	if (destsize <= lendest)
		return (lensrc + destsize);
	return (lendest + lensrc);
}

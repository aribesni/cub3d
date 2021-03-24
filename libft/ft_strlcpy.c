/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 09:39:36 by aribesni          #+#    #+#             */
/*   Updated: 2019/10/25 15:08:00 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcpy(char *dest, const char *src, size_t destsize)
{
	size_t	count;
	size_t	i;

	if (destsize == 0)
		return (ft_strlen(src));
	count = 0;
	i = 0;
	while (src[count] != '\0')
		count++;
	while (src[i] && i < (destsize - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (count);
}

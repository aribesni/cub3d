/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 17:52:05 by aribesni          #+#    #+#             */
/*   Updated: 2019/10/24 16:01:06 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	k;
	unsigned char	*ptr;
	size_t			i;

	k = (unsigned char)c;
	ptr = (unsigned char*)str;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == k)
			return (ptr + i);
		i++;
	}
	return (NULL);
}

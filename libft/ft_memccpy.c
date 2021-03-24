/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:18:23 by aribesni          #+#    #+#             */
/*   Updated: 2019/10/24 14:51:30 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*new_dest;
	unsigned char	*new_src;
	size_t			i;

	new_dest = (unsigned char*)dest;
	new_src = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		if (new_src[i] != (unsigned char)c)
			new_dest[i] = new_src[i];
		else
		{
			new_dest[i] = new_src[i];
			return (new_dest + i + 1);
		}
		i++;
	}
	return (NULL);
}

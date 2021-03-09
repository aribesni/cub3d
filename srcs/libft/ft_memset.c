/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 10:28:37 by aribesni          #+#    #+#             */
/*   Updated: 2019/10/08 16:15:04 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *pointer, int value, size_t len)
{
	unsigned char	*new;
	size_t			count;

	count = 0;
	new = (unsigned char *)pointer;
	while (count < len)
	{
		new[count] = (unsigned char)value;
		count++;
	}
	return (new);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:09:18 by aribesni          #+#    #+#             */
/*   Updated: 2019/10/08 16:15:23 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *string, size_t n)
{
	unsigned char	*new;
	size_t			count;

	count = 0;
	new = (unsigned char *)string;
	while (count < n)
		new[count++] = 0;
}

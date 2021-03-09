/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 09:54:20 by aribesni          #+#    #+#             */
/*   Updated: 2019/10/16 15:08:16 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	int		i;

	i = 0;
	if (!(str = malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (str[i])
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}

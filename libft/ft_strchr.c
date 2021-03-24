/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 09:52:53 by aribesni          #+#    #+#             */
/*   Updated: 2019/10/09 21:48:20 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	k;
	char	*str;

	i = 0;
	if (!s)
		return (NULL);
	k = (char)c;
	str = (char*)s;
	while (str[i] && str[i] != k)
		i++;
	if (str[i] == k)
		return (str + i);
	return (NULL);
}

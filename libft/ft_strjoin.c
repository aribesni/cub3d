/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 09:53:35 by aribesni          #+#    #+#             */
/*   Updated: 2019/10/25 15:07:14 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		j;
	int		len_1;
	int		len_2;
	char	*dest;

	i = 0;
	j = 0;
	len_1 = ft_strlen(s1);
	len_2 = ft_strlen(s2);
	if (!(dest = (char*)malloc(sizeof(char) * (len_1 + len_2 + 1))))
		return (NULL);
	while (s1 && s1[i])
		dest[j++] = s1[i++];
	i = 0;
	while (s2[i] && s2)
		dest[j++] = s2[i++];
	dest[j] = '\0';
	return (dest);
}

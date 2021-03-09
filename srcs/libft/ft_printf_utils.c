/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <aribesni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 22:42:41 by aribesni          #+#    #+#             */
/*   Updated: 2020/05/04 22:53:48 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_reset(t_list *elem)
{
	elem->wid = 0;
	elem->prec = 0;
	elem->size = 0;
	elem->space = 0;
	elem->neg = 0;
	elem->tmp = 0;
	elem->tmp2 = 0;
	elem->conv = '0';
}

void		ft_flags(const char *str, int **i)
{
	while (str[**i + 1] >= '0' && str[**i + 1] <= '9')
		**i += 1;
	if (str[**i + 1] == '*')
		**i += 1;
	while (str[**i + 1] == '-')
		**i += 1;
	if (str[**i + 1] == '*')
		**i += 1;
	while (str[**i + 1] >= '0' && str[**i + 1] <= '9')
		**i += 1;
	if (str[**i + 1] == '.')
		**i += 1;
	if (str[**i + 1] == '*')
		**i += 1;
	while (str[**i + 1] >= '0' && str[**i + 1] <= '9')
		**i += 1;
}

void		ft_dot_bis(int i, const char *str, t_list *elem)
{
	int		j;
	char	*s1;

	i += 2;
	j = i;
	while (str[j] >= '0' && str[j] <= '9' && str[j])
		j++;
	if (str[i] == '*')
		elem->prec = elem->tmp2;
	else
	{
		s1 = ft_substr(str, i, (j - i));
		if (ft_atoi(s1) > ft_strlen(elem->string))
			elem->prec = ft_strlen(elem->string);
		else
			elem->prec = ft_atoi(s1);
		free(s1);
	}
	if (elem->prec > elem->size || elem->prec < 0)
		elem->prec = elem->size;
	elem->size = ft_strlen(elem->string);
	elem->space = elem->wid - elem->prec;
	elem->ret += (elem->prec > elem->wid) ? elem->prec : elem->wid;
}

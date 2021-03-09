/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <aribesni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 13:40:38 by aribesni          #+#    #+#             */
/*   Updated: 2020/10/20 11:46:18 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_no_zero(int nb, int size, char *base)
{
	if (base[0] == '0')
		ft_putchar(base[nb]);
	else
	{
		if (nb == 0)
			ft_putchar(base[size - 1]);
		else
			ft_putchar(base[nb - 1]);
	}
}

void		ft_div(int nb, int size, char *base)
{
	long	div;
	int		count;
	int		count_2;

	count = 0;
	div = nb / size;
	while (div >= size && ++count)
		div = div / size;
	count_2 = count;
	ft_no_zero(div, size, base);
	while (count_2--)
	{
		div = nb;
		count = count_2 + 1;
		while (count--)
			div = div / size;
		while (div >= size)
			div = div - size;
		ft_no_zero(div, size, base);
	}
	div = nb - (size * (nb / size));
	ft_no_zero(div, size, base);
}

int			ft_check_base(char *base, int size)
{
	int		i;
	int		array[255];

	i = -1;
	if (size == 0 || size == 1)
		return (0);
	while (base[i])
	{
		if ((base[i] >= 0 &&  base[i] <= 47) || (base[i] >= 58 && base[i] <= 64)
		|| (base[i] >= 91 && base[i] <= 96) || (base[i] >= 123))
			return (0);
		i++;
	}
	i = -1;
	while (i++ < 255)
		array[i] = 0;
	i = -1;
	while (base[i++])
	{
		if (array[(int)base[i]] == 0)
			array[(int)base[i]] = 1;
		else
			return (0);
	}
	return (1);
}

void		ft_putnbr_base(int nb, char *base)
{
	int		size;

	size = ft_strlen(base);
	if (ft_check_base(base, size) == 1)
	{
		if (nb < 0)
		{
			nb = -nb;
			ft_putchar('-');
		}
		if (nb < size)
			ft_no_zero(nb, size, base);
		else if (nb >= size)
			ft_div(nb, size, base);
	}
}

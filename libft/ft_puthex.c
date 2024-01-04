/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:47:48 by gbazart           #+#    #+#             */
/*   Updated: 2023/12/08 17:41:45 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hexlen(unsigned int num)
{
	int	i;

	i = 0;
	while (num != 0)
	{
		num = num / 16;
		i++;
	}
	return (i);
}

int	ft_puthex(unsigned int num, const char c)
{
	if (num == 0)
		return (ft_putchar('0'));
	if (num >= 16)
	{
		ft_puthex(num / 16, c);
		ft_puthex(num % 16, c);
	}
	else if (num <= 9)
		ft_putchar(num + '0');
	else
	{
		if (c == 'x')
			ft_putchar(num - 10 + 'a');
		else if (c == 'X')
			ft_putchar(num - 10 + 'A');
	}
	return (ft_hexlen(num));
}

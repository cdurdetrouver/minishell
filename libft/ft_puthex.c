/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:47:48 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/11 16:58:16 by gbazart          ###   ########.fr       */
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

/**
 * @brief Outputs the unsigned int ’num’ in hexadecimal to the standard output.
 *
 * @param num (unsigned int) The number to output.
 * @param c (const char) The case of the hexadecimal letters to use.
 * @return (int) The number of characters output.
 * @note If c is 'x', the letters are lowercase, if c is 'X', the letters are
 * uppercase.
 */
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

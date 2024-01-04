/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:50:43 by gbazart           #+#    #+#             */
/*   Updated: 2023/12/08 17:40:57 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	conversions(const char c, va_list list)
{
	if (c == 'c')
		return (ft_putchar(va_arg(list, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(list, char *)));
	else if (c == 'p')
		return (ft_putptr(va_arg(list, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(list, int)));
	else if (c == 'u')
		return (ft_putu((va_arg(list, unsigned int))));
	else if (c == 'x' || c == 'X')
		return (ft_puthex(va_arg(list, unsigned int), c));
	else if (c == '%')
		return (ft_putchar('%'));
	else
		return (0);
}

int	ft_printf(const char *string, ...)
{
	va_list	list;
	int		length;
	int		i;

	if (!string)
		return (-1);
	i = 0;
	length = 0;
	va_start(list, string);
	while (string[i])
	{
		if (string[i] == '%')
		{
			length += conversions(string[i + 1], list);
			i++;
		}
		else
			length += ft_putchar(string[i]);
		i++;
	}
	va_end(list);
	return (length);
}

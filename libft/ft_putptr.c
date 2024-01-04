/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:48:08 by gbazart           #+#    #+#             */
/*   Updated: 2023/12/08 17:46:03 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hexlenptr(unsigned long long num)
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

int	ft_puthexptr(unsigned long long num)
{
	if (num >= 16)
	{
		ft_puthexptr(num / 16);
		ft_puthexptr(num % 16);
	}
	else if (num <= 9)
		ft_putchar(num + '0');
	else
		ft_putchar(num - 10 + 'a');
	return (ft_hexlenptr(num));
}

int	ft_putptr(void *ptr)
{
	int	len;

	len = 0;
	if (ptr == NULL)
		len += ft_putstr("(nil)");
	else
	{
		len = ft_putstr("0x");
		len += ft_puthexptr((unsigned long long)ptr);
	}
	return (len);
}

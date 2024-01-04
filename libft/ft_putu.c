/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:06:28 by gbazart           #+#    #+#             */
/*   Updated: 2023/12/08 17:50:32 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static char	*fill_str(char *str, unsigned int n, int len)
{
	if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		str[--len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

char	*ft_utoa(unsigned int n)
{
	char	*str;
	int		len;

	len = count_digits(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	return (fill_str(str, n, len));
}

int	ft_putu(unsigned int n)
{
	char	*str;
	int		len;

	str = ft_utoa(n);
	if (!str)
		return (0);
	len = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (len);
}

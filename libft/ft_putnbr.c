/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:50:26 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/11 16:58:48 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Outputs the integer ’n’ to the standard output.
 *
 * @param n (int) The integer to output.
 * @return (int) The number of characters output.
 */
int	ft_putnbr(int n)
{
	char	*temp;
	int		result;

	temp = ft_itoa(n);
	result = ft_putstr(temp);
	free(temp);
	return (result);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:42:32 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/11 16:57:41 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Outputs the character ’c’ to the standard output.
 *
 * @param c (char) The character to output.
 * @return (int) The number of characters output.
 */
int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

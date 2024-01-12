/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:22:20 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/11 16:54:21 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief check if a char is ascii.
 *
 * @param c (int) char to check
 * @return (int) 1 if true, 0 if false
 */
int	ft_isascii(int c)
{
	if (c > 127 || c < 0)
		return (0);
	return (1);
}

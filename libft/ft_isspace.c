/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:55:19 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/11 16:54:43 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief check if a char is a space.
 *
 * @param c (int) char to check
 * @return (int) 1 if true, 0 if false
 */
int	ft_isspace(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

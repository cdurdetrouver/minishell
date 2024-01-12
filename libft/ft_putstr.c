/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:47:16 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/11 16:47:42 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief write a string on the standard output.
 *
 * @param s (char *) string to write
 * @return (int) number of char written
 */
int	ft_putstr(char *s)
{
	if (s == NULL)
		return (ft_putstr("(null)"));
	return (write(1, s, ft_strlen(s)));
}

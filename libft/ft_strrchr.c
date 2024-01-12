/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:57:34 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/11 16:50:15 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief find a char in a string with c % 256.
 *
 * @param s (char *) string
 * @param c (int) char to find
 * @return (char *) pointer to the char equal in the string or NULL.
 */
char	*ft_strrchr(const char *s, int c)
{
	char	*ch;

	ch = NULL;
	while (*s)
	{
		if (*s == c % 256)
			ch = (char *)s;
		s++;
	}
	if (*s == c)
		ch = (char *)s;
	return (ch);
}

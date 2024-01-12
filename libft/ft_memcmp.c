/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:00:19 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/11 16:56:53 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Compares byte string s1 against byte string s2.
 * Both strings are assumed to be n bytes long.
 *
 * @param s1 (const void *) The first string to be compared.
 * @param s2 (const void *) The second string to be compared.
 * @param n (size_t) The maximum number of bytes to compare.
 *
 * @return (int) The difference between the first differing pair
 * of bytes (treated as unsigned char values).
 * Zero-length strings are always identical.
 * This behavior is not required by
 * C and portable code should only depend on the sign
 * of the returned value.
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned long	i;
	int				delta;

	i = 0;
	while (i < n)
	{
		delta = *(unsigned char *)s1 - *(unsigned char *)s2;
		if (delta)
			return (delta);
		i++;
		s1++;
		s2++;
	}
	return (0);
}

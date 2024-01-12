/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:49:35 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/11 16:57:05 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Fills the first n bytes of the memory area pointed to by s with the
 * constant byte c.
 *
 * @param s (void *) The memory area to be filled.
 * @param c (int) The character to fill the memory area with.
 * @param n (size_t) The number of bytes to be filled.
 * @return (void *) The original value of s.
 */
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*s2;
	size_t			i;

	s2 = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		s2[i] = c;
		i++;
	}
	s = s2;
	return (s);
}

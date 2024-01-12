/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:29:48 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/11 16:56:48 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Scans the initial n bytes of the memory area pointed to by s for the
 * first instance of c. Both c and the bytes of the memory area pointed to by s
 * are interpreted as unsigned char.
 *
 * @param s (const void *) The memory area to be scanned.
 * @param c (int) The character to be located.
 * @param n (size_t) The number of bytes to be scanned.
 * @return (void *) A pointer to the matching byte or NULL if the character does
 * not occur in the given memory area.
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n)
	{
		if (*str == (unsigned char)c)
			return (str);
		str++;
		n--;
	}
	return (NULL);
}

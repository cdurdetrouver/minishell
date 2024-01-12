/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:10:41 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/11 16:56:57 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Copies n bytes from memory area src to memory area dest.
 *
 * @param dest (void *) The destination memory area.
 * @param src (void *) The source memory area.
 * @param n (size_t) The number of bytes to copy.
 * @return (void *) The original value of dest.
 */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	long unsigned int	i;
	char				*d;
	char				*s;

	d = (char *)dest;
	s = (char *)src;
	i = 0;
	while (i < n)
	{
		*d = *s;
		d++;
		s++;
		i++;
	}
	return (dest);
}

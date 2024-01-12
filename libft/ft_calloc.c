/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:12:06 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/11 16:54:01 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief allocate memory and fill it with 0.
 *
 * @param nmemb (size_t) number of elements
 * @param size (size_t) size of each element
 * @return (void *) pointer to the allocated memory
 */
void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*tab;
	size_t			i;

	i = 0;
	tab = malloc(size * nmemb);
	if (!tab)
		return (0);
	while (i < size * nmemb)
		tab[i++] = 0;
	return (tab);
}

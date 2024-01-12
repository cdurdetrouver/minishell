/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:24:03 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/11 16:49:36 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief find a string in a string.
 *
 * @param big (const char *) string
 * @param little (const char *) string to find
 * @param len (size_t) number of char to search
 * @return (char *) pointer to the string equal in the string or NULL.
 */
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	len_little;

	if (little[0] == '\0')
		return ((char *)big);
	if (big[0] == '\0')
		return (NULL);
	len_little = ft_strlen(little);
	while (len-- >= len_little && *little != '\0')
	{
		if (*little == *big && ft_strncmp(big, little, len_little) == 0)
			return ((char *)big);
		big++;
	}
	return (NULL);
}

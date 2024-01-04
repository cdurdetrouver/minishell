/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gbazart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:24:03 by gbazart           #+#    #+#             */
/*   Updated: 2023/11/14 17:21:36 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

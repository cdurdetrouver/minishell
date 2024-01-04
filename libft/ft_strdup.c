/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gbazart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:04:42 by gbazart           #+#    #+#             */
/*   Updated: 2023/11/09 15:45:31 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	char	*s2;
	size_t	len;
	size_t	i;

	s2 = (char *)s;
	len = ft_strlen(s);
	dest = malloc(len * sizeof(char) + 1);
	i = 0;
	while (i < len)
	{
		dest[i] = s2[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

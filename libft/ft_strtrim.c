/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gbazart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:27:37 by gbazart           #+#    #+#             */
/*   Updated: 2023/11/20 14:50:50 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_issame(const char *s1, const char s2)
{
	while (*s1)
	{
		if (*s1 == s2)
			return (1);
		s1++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dest;
	size_t	start;
	size_t	end;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	start = 0;
	while (*(s1 + start) && ft_issame(set, *(s1 + start)))
		start++;
	end = ft_strlen(s1);
	while (*(s1 + (end - 1))
		&& ft_issame(set, *(s1 + (end - 1))) && end > start)
		end--;
	dest = ft_substr(s1, start, end - start);
	if (!dest)
		return (NULL);
	return (dest);
}

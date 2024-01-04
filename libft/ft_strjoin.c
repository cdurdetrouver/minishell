/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gbazart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:22:29 by gbazart           #+#    #+#             */
/*   Updated: 2023/11/14 18:02:25 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	i;
	size_t	j;

	new = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		new[j] = s1[j];
		i++;
		j++;
	}
	i = 0;
	while (s2[i])
	{
		new[j] = s2[i];
		j++;
		i++;
	}
	new[j] = '\0';
	return (new);
}

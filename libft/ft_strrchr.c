/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gbazart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:57:34 by gbazart           #+#    #+#             */
/*   Updated: 2023/11/14 16:56:02 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ch;

	ch = NULL;
	while (*s)
	{
		if (*s == c % 256)
			ch = (char *)s;
		s++;
	}
	if (*s == c)
		ch = (char *)s;
	return (ch);
}

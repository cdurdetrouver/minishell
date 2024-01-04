/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gbazart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:00:19 by gbazart           #+#    #+#             */
/*   Updated: 2023/11/09 14:10:25 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned long	i;
	int				delta;

	i = 0;
	while (i < n)
	{
		delta = *(unsigned char *)s1 - *(unsigned char *)s2;
		if (delta)
			return (delta);
		i++;
		s1++;
		s2++;
	}
	return (0);
}

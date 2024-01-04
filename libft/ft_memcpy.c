/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gbazart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:10:41 by gbazart           #+#    #+#             */
/*   Updated: 2023/11/09 15:46:27 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
		d ++;
		s ++;
		i ++;
	}
	return (dest);
}

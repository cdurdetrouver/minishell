/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gbazart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:12:06 by gbazart           #+#    #+#             */
/*   Updated: 2023/11/20 15:08:54 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

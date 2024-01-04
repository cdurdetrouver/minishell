/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gbazart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:14:44 by marvin            #+#    #+#             */
/*   Updated: 2023/11/20 13:08:51 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*maillon;

	maillon = (t_list *)malloc(sizeof(t_list));
	if (!maillon)
		return (NULL);
	maillon->content = content;
	maillon->next = NULL;
	return (maillon);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:14:44 by marvin            #+#    #+#             */
/*   Updated: 2024/01/11 16:56:36 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Allocates and returns a new element.
 *
 * @param content (void *) The content to create the new element with.
 * @return (t_list *) The new element.
 */
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

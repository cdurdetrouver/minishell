/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:59:26 by marvin            #+#    #+#             */
/*   Updated: 2024/01/11 16:56:05 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief clear a list.
 *
 * @param lst (t_list **) The address of a pointer to the first link of a list.
 * @param del (void (*)(void *)) The address of the function used to delete the
 * content of the element.
 */
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;

	if (!del)
		return ;
	while (*lst)
	{
		current = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = current;
	}
}

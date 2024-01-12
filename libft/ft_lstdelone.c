/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:35:45 by marvin            #+#    #+#             */
/*   Updated: 2024/01/11 16:56:18 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Takes as a parameter an element and frees the memory of the element’s
 * content using the function ’del’ given as a parameter and free the element.
 * The memory of ’next’ must not be freed.
 *
 * @param lst (t_list *) The element to free.
 * @param del (void (*)(void *)) The address of the function used to delete the
 * content of the element.
 */
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!del)
		return ;
	del(lst->content);
	free(lst);
}

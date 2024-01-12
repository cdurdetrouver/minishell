/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:20:33 by marvin            #+#    #+#             */
/*   Updated: 2024/01/11 16:56:41 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Counts the number of elements in a list.
 *
 * @param lst (t_list *) The beginning of the list.
 * @return (int) The length of the list.
 */
int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*current;
	t_list	*next;

	count = 0;
	current = lst;
	while (current)
	{
		next = current->next;
		current = next;
		count++;
	}
	return (count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gbazart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:20:33 by marvin            #+#    #+#             */
/*   Updated: 2023/11/20 13:32:59 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

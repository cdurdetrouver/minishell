/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 19:12:37 by hlamnaou          #+#    #+#             */
/*   Updated: 2024/01/11 15:52:17 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	give_types(t_token *t)
{
	while (t->next)
	{
		if (t->content)
			t->type = get_type(t->content);
		t = t->next;
	}
	t = tokenfirst(t);
	while (t->next)
	{
		if (!type_is_sep(t->next->type) && t->next->type != END)
		{
			if (t->type == GREAT)
				t->next->type = A_GREAT;
			else if (t->type == LESS)
				t->next->type = A_LESS;
			else if (t->type == D_GREAT)
				t->next->type = A_DGREAT;
			else if (t->type == D_LESS)
				t->next->type = A_DLESS;
		}
		t = t->next;
	}
}

void	quote(t_token *t)
{
	char	*tmp;

	while (t->next)
	{
		if (t->content)
		{
			tmp = remove_quotes(t->content);
			free(t->content);
			t->content = tmp;
		}
		t = t->next;
	}
	t = tokenfirst(t);
}

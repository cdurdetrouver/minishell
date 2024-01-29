/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlamnaou <hlamnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:16:55 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/29 17:55:05 by hlamnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief handle the signal ctrl + c.
 *
 * @param signum
 */
void	sig_handler(int signum)
{
	if (signum == SIGINT)
	{
		g_exit_code = 130;
		ft_putchar_fd('\n', 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

/**
 * @brief handle the signal ctrl + \ in execution.
 *
 * @param sig
 */
void	handle_sigquit(int sig)
{
	(void)sig;
	ft_putstr_fd("Quit (core dumped)\n", 2);
	g_exit_code = 131;
}

/**
 * @brief handle the signal ctrl + C in execution.
 *
 * @param sig
 */
void	handle_sigint(int sig)
{
	(void)sig;
	g_exit_code = 130;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:16:55 by gbazart           #+#    #+#             */
/*   Updated: 2024/01/07 20:10:00 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Handle SIGQUIT signal
 *
 * @param signum int signal number
 */
void	sigint_handler(int signum)
{
	(void)signum;
	printf("\n");
}

// void	sig_init(void)
// {
// 	g_sig.sigint = 0;
// 	g_sig.sigquit = 0;
// 	g_sig.exit_status = 0;
// 	g_sig.pid = 0;
// }

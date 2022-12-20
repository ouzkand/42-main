/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okandemi <okandemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:37:00 by okandemi          #+#    #+#             */
/*   Updated: 2022/12/19 14:56:17 by okandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static int	g_set = 0;

int	ft_write(int i)
{
	if (g_set == '\0')
		i = 1;
	else
		ft_printf ("%c", (char) g_set);
	return (i);
}

void	ft_bit_editing(int x)
{
	static int		bit = 7;
	static int		i = 0;
	static int		pid = 0;

	g_set = g_set + (x << bit);
	if (bit == 0)
	{
		if (i != 1)
			i = ft_write(i);
		else if (i == 1)
		{
			if (g_set == '\0')
			{
				i = 0;
				kill(pid, SIGUSR1);
				pid = 0;
			}
			else
				pid = (pid * 10) + (g_set - '0');
		}
		bit = 7;
		g_set = 0;
	}
	else
		bit--;
}

void	ft_signal_catch(int x)
{
	if (x == SIGUSR1)
		ft_bit_editing(1);
	else
		ft_bit_editing(0);
}

int	main(void)
{
	int		pid;

	pid = getpid();
	ft_printf("pid: %u\n", pid);
	signal(SIGUSR1, ft_signal_catch);
	signal(SIGUSR2, ft_signal_catch);
	while (1)
		pause();
}

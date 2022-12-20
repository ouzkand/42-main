/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okandemi <okandemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:32:52 by okandemi          #+#    #+#             */
/*   Updated: 2022/12/19 15:29:44 by okandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

char	*g_clientpid;

void	ft_success(int x)
{
	if (x == SIGUSR1)
		ft_printf("The signal was successfully reached.\n");
}

void	ft_shift(int pid, int i, char c)
{
	while (i--)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(150);
	}
}

void	ft_bit_shift(int pid, char *str)
{
	int				i;
	unsigned char	c;
	int				len;

	while (1)
	{
		i = 8;
		c = *str;
		ft_shift(pid, i, c);
		if (*str == '\0')
			break ;
		str++;
	}
	len = ft_strlen(g_clientpid) + 1;
	while (len--)
	{
		i = 8;
		c = *g_clientpid++;
		ft_shift(pid, i, c);
		signal(SIGUSR1, ft_success);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_printf("You have to enter 3 arguments!");
		return (0);
	}
	g_clientpid = ft_itoa(getpid());
	ft_bit_shift(ft_atoi(argv[1]), argv[2]);
}

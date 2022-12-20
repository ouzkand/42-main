/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okandemi <okandemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:32:56 by okandemi          #+#    #+#             */
/*   Updated: 2022/12/19 13:17:25 by okandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include "./ft_printf/ft_printf.h"

int		ft_atoi(char *str);
void	ft_bit_editing(int x);
void	ft_signal_catch(int x);
void	ft_bit_shift(int pid, char *str);
char	*ft_itoa(int n);
int		ft_count(long int tmp);
size_t	ft_strlen(const char *str);
void	ft_shift(int pid, int i, char c);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okandemi <okandemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:43:44 by okandemi          #+#    #+#             */
/*   Updated: 2023/02/04 16:47:51 by okandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_stack
{
	int	*a_s;
	int	*b_s;
	int	*sorted;
	int	a_len;
	int	b_len;
	int	len;
	int	max_bit;
}	t_stack;

int		sort_control(t_stack *data);
void	repeat_numbers(t_stack *data);

void	ft_a_len(char **argv, t_stack *data);
void	error(t_stack *data);
void	ft_free(t_stack *data);
int		get_index(t_stack *data, int nbr);

void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t num, size_t size);
void	my_atoi(const char *str, t_stack *data);
void	max_control(long int result, t_stack *data);
void	max_bit(t_stack *data);

void	ft_sort(t_stack *data);
void	three(t_stack *data);
void	array_sort(t_stack *data);
void	radix(t_stack *data);
void	five(t_stack *data);

void	swap_a(t_stack *data);
void	swap_b(t_stack *data);
void	revrotate_a(t_stack *data);
void	revrotate_b(t_stack *data);
void	rotate_a(t_stack *data);

void	ft_push(int *d, int len);
void	ft_pop(int *d, int len);
void	push_a(t_stack *data);
void	push_b(t_stack *data);
void	rotate_b(t_stack *data);

#endif
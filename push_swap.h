/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cylini <cylini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:48:56 by cde-sous          #+#    #+#             */
/*   Updated: 2024/11/03 22:34:23 by cylini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"

typedef struct s_stack
{
	struct s_stack	*next;
	int				data;
	int				i;
}					t_stack;

typedef struct s_stacks
{
	t_stack			*a;
	t_stack			*b;
}					t_stacks;

void				ft_all_clean(t_stacks *stacks, int index, char **number);
void				call_all_algo(t_stacks *all_stack);
void				f_swap(t_stack **a_b);
void				f_rotate(t_stack **a_b);
void				f_rev_rotate(t_stack **a_b);
void				f_push(t_stack **first, t_stack **second);
void radix_sort(t_stacks *all_stack);
int	stack_size(t_stack *a);
void push_between_a_b(t_stack **a, t_stack **b, int total_bit);
int	check_sort(t_stack *a);





#endif
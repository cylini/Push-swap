/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carzhang <carzhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:48:56 by cde-sous          #+#    #+#             */
/*   Updated: 2024/11/18 15:54:59 by carzhang         ###   ########.fr       */
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

// f_clean.c
void				ft_all_clean(t_stacks *stacks, int index, char ***number);
void				free_number(char ***number);

// f_call_all_algo.c
void				call_all_algo(t_stacks *all_stack);
int					stack_size(t_stack *a);

// f_all_type_op.c
void				f_swap(t_stack **a_b, char id);
void				f_rotate(t_stack **a_b, char id);
void				f_rev_rotate(t_stack **a_b, char id);
void				f_push(t_stack **first, t_stack **second, char id);

// radix.c
int					check_sort(t_stack *a);
void				push_rotate_between_a_b(t_stack **a, t_stack **b,
						int total_bit, int current_bit);
void				radix_sort(t_stacks *all_stack);

// f_utils.c
int					find_position(t_stack *stack, t_stack *target);
void				move_to_top(t_stack **a, t_stack *smaller_number, char id);

#endif
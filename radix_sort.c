/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cylini <cylini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 16:12:51 by cylini            #+#    #+#             */
/*   Updated: 2024/11/06 18:05:35 by cylini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	index_the_numbers(t_stack *a)
{
	t_stack	*tmp;
	t_stack	*tmp2;
	int		i;
	int		index_max;

	tmp = a;
	index_max = 0;
	while (tmp)
	{
		i = 0;
		tmp2 = a;
		while (tmp2)
		{
			if (tmp->data > tmp2->data)
				i++;
			tmp2 = tmp2->next;
		}
		tmp->i = i;
		if (tmp->i > index_max)
			index_max = tmp->i;
		tmp = tmp->next;
	}
	return (index_max);
}

int	check_sort(t_stack *a)
{
	t_stack	*tmp;

	tmp = a;
	while (tmp && tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	check_reverse_sort(t_stack *b)
{
	t_stack	*tmp;

	tmp = b;
	while (tmp && tmp->next)
	{
		if (tmp->data < tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	push_rotate_between_a_b(t_stack **a, t_stack **b, int total_bit,
		int current_bit)
{
	int	size;

	size = stack_size(*a);
	while (size-- > 0 && (check_sort(*a) == 0))
	{
		if (((*a)->i >> current_bit) & 1)
			f_rotate(a, 'a');
		else
			f_push(a, b, 'b');
	}
	size = stack_size(*b);
	if (check_reverse_sort(*b) == 0)
	{
		while (size-- > 0 && (current_bit + 1) <= total_bit)
		{
			if (((*b)->i >> (current_bit + 1)) & 1)
				f_push(b, a, 'a');
			else
				f_rotate(b, 'b');
		}
	}
}

void	radix_sort(t_stacks *all_stack)
{
	int	index_max;
	int	total_bit;
	int	current_bit;

	index_max = index_the_numbers(all_stack->a);
	total_bit = 0;
	while (index_max > 0)
	{
		index_max = index_max / 2;
		total_bit++;
	}
	current_bit = 0;
	while (current_bit < total_bit)
	{
		push_rotate_between_a_b(&all_stack->a, &all_stack->b, total_bit,
			current_bit);
		current_bit++;
	}
	while (stack_size(all_stack->b) > 0)
		f_push(&all_stack->b, &all_stack->a, 'a');
	while (check_sort(all_stack->a) == 0)
		f_rotate(&all_stack->a, 'a');
}

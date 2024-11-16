/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_call_all_algo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carzhang <carzhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:02:45 by cde-sous          #+#    #+#             */
/*   Updated: 2024/11/16 20:38:14 by carzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_position(t_stack *stack, t_stack *target)
{
	int	pos;

	pos = 0;
	while (stack && stack != target)
	{
		pos++;
		stack = stack->next;
	}
	return (pos);
}

// void	move_to_top(t_stack **stack, t_stack *target, char id)
// {
// 	int	pos;
// 	int	size;

// 	pos = find_position(*stack, target);
// 	size = stack_size(*stack);
// 	if (pos <= size / 2)
// 		while (*stack != target)
// 			f_rotate(stack, id);
// 	else
// 		while (*stack != target)
// 			f_rev_rotate(stack, id);
// }

int	stack_size(t_stack *a)
{
	t_stack	*tmp;
	int		i;

	if (!a)
		return (0);
	i = 0;
	tmp = a;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
void	sort_3_numbers(t_stack **a)
{
	int	one;
	int	two;
	int	three;

	if (check_sort(*a))
		return ;
	one = (*a)->data;
	two = (*a)->next->data;
	three = (*a)->next->next->data;
	if (one < two && two > three && three > one)
	{
		f_rev_rotate(a, 'a');
		f_swap(a, 'a');
	}
	else if (one > two && two < three && three > one)
		f_swap(a, 'a');
	else if (one < two && two > three && three < one)
		f_rev_rotate(a, 'a');
	else if (one > two && two < three && three < one)
		f_rotate(a, 'a');
	else if (one > two && two > three && three < one)
	{
		f_rotate(a, 'a');
		f_swap(a, 'a');
	}
}

void	sort_4_and_5_numbers(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	t_stack	*smaller_number;
	int		pos;

	while (stack_size(*a) > 3)
	{
		tmp = *a;
		smaller_number = *a;
		while (tmp)
		{
			if (smaller_number->data > tmp->data)
				smaller_number = tmp;
			tmp = tmp->next;
		}
		if ((pos = find_position(*a, smaller_number)) <= stack_size(*a) / 2)
			while (*a != smaller_number)
				f_rotate(a, 'a');
		else
			while (*a != smaller_number)
				f_rev_rotate(a, 'a');
		// // while (*a != smaller_number)
		// // 	f_rotate(a, 'a');
		// move_to_top(a, smaller_number, 'a');
		f_push(a, b, 'b');
	}
	sort_3_numbers(a);
	while (stack_size(*b) != 0)
		f_push(b, a, 'a');
}

void	sort_6_and_7_numbers(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	t_stack	*smallest;

	while (stack_size(*a) > 4)
	{
		tmp = *a;
		smallest = *a;
		while (tmp)
		{
			if (tmp->data < smallest->data)
				smallest = tmp;
			tmp = tmp->next;
		}
		while (*a != smallest)
			f_rotate(a, 'a');
		f_push(a, b, 'b');
	}
	sort_4_and_5_numbers(a, b);
	while (stack_size(*b) > 0)
		f_push(b, a, 'a');
}

void	call_all_algo(t_stacks *all_stack)
{
	if (check_sort(all_stack->a))
		return ;
	if (stack_size(all_stack->a) == 2)
		f_swap(&all_stack->a, 'a');
	else if (stack_size(all_stack->a) == 3)
		sort_3_numbers(&all_stack->a);
	else if (stack_size(all_stack->a) == 4 || stack_size(all_stack->a) == 5)
		sort_4_and_5_numbers(&all_stack->a, &all_stack->b);
	else if (stack_size(all_stack->a) == 6 || stack_size(all_stack->a) == 7)
		sort_6_and_7_numbers(&all_stack->a, &all_stack->b);
	else
		radix_sort(all_stack);
}

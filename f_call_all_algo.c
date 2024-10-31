/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_call_all_algo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:02:45 by cde-sous          #+#    #+#             */
/*   Updated: 2024/10/31 15:34:16 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		f_rev_rotate(a);
		f_swap(a);
	}
	else if (one > two && two < three && three > one)
		f_swap(a);
	else if (one < two && two > three && three < one)
		f_rev_rotate(a);
	else if (one > two && two < three && three < one)
		f_rotate(a);
	else if (one > two && two > three && three < one)
	{
		f_rotate(a);
		f_swap(a);
	}
}

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

void	sort_4_and_5_numbers(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	t_stack	*smaller_number;

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
		while (*a != smaller_number)
			f_rotate(a);
		f_push(a, b);
	}
	sort_3_numbers(a);
	while (stack_size(*b) != 0)
		f_push(b, a);
}

void	call_all_algo(t_stacks *all_stack)
{
	if (check_sort(all_stack->a))
		return ;
	if (stack_size(all_stack->a) == 2)
		f_swap(&all_stack->a);
	else if (stack_size(all_stack->a) == 3)
		sort_3_numbers(&all_stack->a);
	else if (stack_size(all_stack->a) == 4 || stack_size(all_stack->a) == 5)
		sort_4_and_5_numbers(&all_stack->a, &all_stack->b);
	else
		;
	// radix;
}

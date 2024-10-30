/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_call_all_algo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:02:45 by cde-sous          #+#    #+#             */
/*   Updated: 2024/10/30 17:04:45 by cde-sous         ###   ########.fr       */
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
void	call_all_algo(t_stacks *all_stack)
{
	if (check_sort(all_stack->a))
	{
		return ;
	}
	f_swap(all_stack->a);
}
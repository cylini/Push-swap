/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carzhang <carzhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 21:15:20 by carzhang          #+#    #+#             */
/*   Updated: 2024/11/17 16:11:36 by carzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_position(t_stack *a, t_stack *smaller_number)
{
	int		pos;
	t_stack	*tmp;

	tmp = a;
	pos = 0;
	while (tmp && tmp != smaller_number)
	{
		pos++;
		tmp = tmp->next;
	}
	return (pos);
}

void	move_to_top(t_stack **a, t_stack *smaller_number, char id)
{
	int	pos;
	int	size;

	size = stack_size(*a);
	pos = find_position(*a, smaller_number);
	if (pos <= size / 2)
	{
		while (*a != smaller_number)
			f_rotate(a, id);
	}
	else
	{
		while (*a != smaller_number)
			f_rev_rotate(a, id);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carzhang <carzhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 21:15:20 by carzhang          #+#    #+#             */
/*   Updated: 2024/11/16 21:22:40 by carzhang         ###   ########.fr       */
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

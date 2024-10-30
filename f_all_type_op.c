/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_all_type_op.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:34:29 by cde-sous          #+#    #+#             */
/*   Updated: 2024/10/30 17:06:06 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	f_swap(t_stack *a_b)
{
	t_stack	*head;
	t_stack	*second;

	if (!a_b || !a_b->next)
		return ;
	head = a_b;
	second = a_b->next;
	a_b = second;
	head->next = second->next;
	second->next = head;
	/* head = a_b;
	ft_printf("     head: %d", head->data);
	while (head)
	{
		ft_printf(" %d\n", head->data);
		head = head->next;
	} */
}

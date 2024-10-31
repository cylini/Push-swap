/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_all_type_op.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:34:29 by cde-sous          #+#    #+#             */
/*   Updated: 2024/10/31 15:33:09 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	f_swap(t_stack **a_b)
{
	t_stack	*head;
	t_stack	*second;

	if (!*a_b || !(*a_b)->next)
		return ;
	head = *a_b;
	second = (*a_b)->next;
	*a_b = second;
	head->next = second->next;
	second->next = head;
}

void	f_rev_rotate(t_stack **a_b)
{
	t_stack	*head;
	t_stack	*new_tail;

	if (!*a_b || !(*a_b)->next)
		return ;
	head = *a_b;
	while (head && head->next)
	{
		if (head->next->next)
			new_tail = head->next;
		head = head->next;
	}
	head->next = *a_b;
	*a_b = head;
	new_tail->next = NULL;
}

void	f_rotate(t_stack **a_b)
{
	t_stack	*head;
	t_stack	*new_tail;

	if (!*a_b || !(*a_b)->next)
		return ;
	head = (*a_b)->next;
	new_tail = *a_b;
	while (new_tail && new_tail->next)
		new_tail = new_tail->next;
	new_tail->next = *a_b;
	new_tail->next->next = NULL;
	*a_b = head;
}

void	f_push(t_stack **first, t_stack **second)
{
	t_stack	*head;

	if (!*first)
		return ;
	head = *first;
	*first = head->next;
	head->next = *second;
	*second = head;
}

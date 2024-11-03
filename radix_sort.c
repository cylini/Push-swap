/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cylini <cylini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 16:12:51 by cylini            #+#    #+#             */
/*   Updated: 2024/11/03 23:46:08 by cylini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int 	index_the_numbers(t_stack *a)
{
	t_stack *tmp;
	t_stack *tmp2;
	int i;
	int index_max;

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
	return(index_max);
}


void push_between_a_b(t_stack **a, t_stack **b, int total_bit)
{
	int current_bit;
	int size;
	
	current_bit = 0;
	while (current_bit < total_bit)
	{
		size = stack_size(*a);
		while (size-- >0)
		{
			if (((*a)->i >> current_bit) & 1)
				f_rotate(a);
			else
				f_push(a, b);
		}
		size = stack_size(*b);
		while (size-- > 0)
		{
			if (((*b)->i >> (current_bit + 1) & 1))
				f_push(b, a);
			else
				f_rotate(b);
		}
        current_bit++;
    }
}


void radix_sort(t_stacks *all_stack)
{
	//index les nb du plus petit au plus gd
	int index_max;
	int total_bit;
	
	index_max = index_the_numbers(all_stack->a);
	total_bit = 0;
	//avoir le nb de bit total, c'est le l'index le plus grand de la liste
	while (index_max > 0)
	{
		index_max = index_max / 2;
		total_bit++;
	}
	push_between_a_b(&all_stack->a, &all_stack->b, total_bit);
	//en dehors de la boucle, arrive au bit total, push tt ce qui est dans la stack b dans la stack a
	while (stack_size(all_stack->b) > 0)
		f_push(&all_stack->b, &all_stack->a);
	//tant que la liste n'est pas trier, faire rotate, pour faire en sorte que le plus petit nb de la liste soit a la tete de la liste
	while (check_sort(all_stack->a) == 0)
		f_rotate(&all_stack->a);
}
	// ft_printf("index max : %d\n", index_max);
	// t_stack *a;
	// t_stack *b;
	// a = all_stack->a;
	// b = all_stack->b;
	// while (a)
	// {
	// 	ft_printf("stack a : %d\n", a->data);
	// 	a = a->next;
	// }
	// while (b)
	// {
	// 	ft_printf("stack b : %d\n", b->data);
	// 	b = b->next;
	// }
	// t_stack *tmp = all_stack->a;
	// while (tmp)
	// {
	// 	ft_printf("number %d : [%d]\n", tmp->data, tmp->i);
	// 	tmp = tmp->next;
	// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cylini <cylini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:49:17 by cde-sous          #+#    #+#             */
/*   Updated: 2024/11/06 18:05:27 by cylini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_end_for_create_new_node(t_stack **begin_list, t_stack *node)
{
	t_stack	*tmp;

	tmp = *begin_list;
	if (!*begin_list)
		*begin_list = node;
	else
	{
		while (tmp && tmp->next)
			tmp = tmp->next;
		tmp->next = node;
	}
}

t_stack	*create_node(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->data = value;
	node->next = NULL;
	return (node);
}

int	change_to_i(char *number, t_stack **begin_list)
{
	int		number_i;
	t_stack	*tmp;

	number_i = ft_atoi(number);
	if (number_i == 0 && number[0] != '0')
		return (0);
	tmp = *begin_list;
	while (tmp)
	{
		if (number_i == tmp->data)
			return (0);
		tmp = tmp->next;
	}
	find_end_for_create_new_node(begin_list, create_node(number_i));
	return (1);
}

void	arg_parse(char *argv[], t_stacks *all_stacks)
{
	int		i;
	int		j;
	char	**number;

	number = NULL;
	i = 1;
	while (argv[i])
	{
		number = ft_split(argv[i], ' ');
		if (!*number)
			ft_all_clean(all_stacks, 0, number);
		j = 0;
		while (number[j])
		{
			if (!change_to_i(number[j], &all_stacks->a))
				ft_all_clean(all_stacks, 0, number);
			free(number[j]);
			j++;
		}
		free(number);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_stacks	all_stack;

	if (!(argc >= 2))
		return (0);
	all_stack.a = NULL;
	all_stack.b = NULL;
	arg_parse(argv, &all_stack);
	call_all_algo(&all_stack);
	ft_all_clean(&all_stack, 1, NULL);
	return (0);
}

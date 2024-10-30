/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:49:17 by cde-sous          #+#    #+#             */
/*   Updated: 2024/10/30 18:03:05 by cde-sous         ###   ########.fr       */
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
		{
			tmp = tmp->next;
		}
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
			{
				free(number[j]);
				ft_all_clean(all_stacks, 0, number);
			}
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
	t_stack		*tmp;

	if (!(argc >= 2))
	{
		ft_printf("a\n");
		return (0);
	}
	all_stack.a = NULL;
	all_stack.b = NULL;
	arg_parse(argv, &all_stack);
	tmp = all_stack.a;
	while (tmp)
	{
		ft_printf("%d\n", tmp->data);
		tmp = tmp->next;
	}
	call_all_algo(&all_stack);
	ft_all_clean(&all_stack, 1, NULL);
	return (0);
}

// algo simple:
/// 3 nombres
/// 4 ou 5 nombres
// algo radix
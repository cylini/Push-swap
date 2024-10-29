/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:49:17 by cde-sous          #+#    #+#             */
/*   Updated: 2024/10/29 14:48:00 by cde-sous         ###   ########.fr       */
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
	node->data = value;
	node->next = NULL;
	return (node);
}
void	change_to_i(char *number, t_stack **begin_list)
{
	int	number_i;

	// int	i;
	number_i = ft_atoi(number);
	// ft_printf("%d\n", number_i);
	find_end_for_create_new_node(begin_list, create_node(number_i));
	// create_node(number_i);
}
void	arg_parse(char *argv[], t_stack **begin_list)
{
	int		i;
	int		j;
	char	**number;

	number = NULL;
	i = 1;
	while (argv[i])
	{
		number = ft_split(argv[i], ' ');
		j = 0;
		while (number[j])
		{
			change_to_i(number[j], begin_list);
			j++;
		}
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
	arg_parse(argv, &all_stack.a);
	tmp = all_stack.a;
	while (tmp)
	{
		ft_printf("%d\n", tmp->data);
		tmp = tmp->next;
	}
	// int i;
	// i = 1;
	return (0);
}

// args -> "1 2 3 4" "5 6"
// split chaque argv[i] return char **numbers -> "1", "2", "3", "4"
// int number => numbers[i] = "1", atoi pour le mettre dans le int
// creer le node
// mettre dans la liste chainee
// free a chaque boucle numbers

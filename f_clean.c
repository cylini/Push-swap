/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_clean.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:39:18 by cde-sous          #+#    #+#             */
/*   Updated: 2024/10/30 17:52:28 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_number(char **number)
{
	int	i;

	if (number)
	{
		i = -1;
		while (number[++i])
		{
			free(number[i]);
			number[i] = NULL;
		}
		free(number);
		number = NULL;
	}
}

void	ft_all_clean(t_stacks *stacks, int index, char **number)
{
	t_stack	*tmp;

	if (stacks->a)
	{
		while (stacks->a)
		{
			tmp = stacks->a;
			stacks->a = stacks->a->next;
			ft_printf("nb: %d\n", tmp->data);
			free(tmp);
		}
		free(stacks->a);
	}
	free_number(number);
	if (index == 0)
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	if (index == 1)
		exit(EXIT_SUCCESS);
}

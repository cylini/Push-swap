/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_clean.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cylini <cylini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:39:18 by cde-sous          #+#    #+#             */
/*   Updated: 2024/11/04 16:36:02 by cylini           ###   ########.fr       */
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

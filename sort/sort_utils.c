/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehay <ehay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:57:46 by ehay              #+#    #+#             */
/*   Updated: 2024/01/19 15:57:59 by ehay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_turny_a(t_stack **stack, char a_b, int depth, int size)
{
	int	offset;

	if (a_b == 'a')
		offset = -1;
	else
		offset = 0;
	if (depth <= size / 2)
	{
		while (depth > 0)
		{
			ra(stack, 1);
			depth--;
		}
	}
	else
	{
		depth = (size - (depth - 1)) + offset;
		while (depth > 0)
		{
			rra(stack, 1);
			depth--;
		}
	}
}

void	ft_turny_b(t_stack **stack, char a_b, int depth, int size)
{
	int	offset;

	if (a_b == 'a')
		offset = -1;
	else
		offset = 0;
	if (depth <= size / 2)
	{
		while (depth > 0)
		{
			rb(stack, 1);
			depth--;
		}
	}
	else
	{
		depth = (size - (depth - 1)) + offset;
		while (depth > 0)
		{
			rrb(stack, 1);
			depth--;
		}
	}
}

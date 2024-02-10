/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehay <ehay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:10:28 by ehay              #+#    #+#             */
/*   Updated: 2024/01/19 15:57:15 by ehay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_big2a(t_stack **a_stack, t_stack **b_stack)
{
	int		b_size;
	int		depth;
	int		i;
	t_stack	*temp;

	temp = *b_stack;
	b_size = size_stack(*b_stack) - 1;
	depth = 0;
	i = 0;
	while (temp)
	{
		if (temp->index == b_size)
		{
			depth = i;
			break ;
		}
		temp = temp->next;
		i++;
	}
	ft_turny_b(b_stack, 'b', depth, b_size);
	pa(a_stack, b_stack);
}

int	ft_closest(t_stack *a_stack, int index)
{
	int	closest;
	int	pos_closest;
	int	i;

	closest = 10000;
	pos_closest = 0;
	i = 0;
	while (a_stack)
	{
		if (a_stack->index > index && ((a_stack->index - index) <= closest))
		{
			closest = a_stack->index - index;
			pos_closest = i;
		}
		a_stack = a_stack->next;
		i++;
	}
	return (pos_closest);
}

void	quicksort_a2b(t_stack **a_stack, t_stack **b_stack, int a_size)
{
	int	chunk;
	int	it_chunk;

	chunk = a_size * 0.13;
	if (a_size > 250)
		chunk = a_size * 0.05;
	it_chunk = chunk;
	while (a_size > 1)
	{
		while (a_size > 0)
		{
			if ((*a_stack)->index < chunk + it_chunk)
			{
				pb(a_stack, b_stack);
				if ((*b_stack)->index < chunk)
					rb(b_stack, 1);
			}
			else
				ra(a_stack, 1);
			a_size--;
		}
		chunk += it_chunk + it_chunk;
		a_size = size_stack(*a_stack);
	}
}

void	quicksort_b2a(t_stack **a_stack, t_stack **b_stack)
{
	int		b_stack_size;
	int		a_stack_size;
	int		closest;

	a_stack_size = size_stack(*a_stack);
	if (a_stack_size == 0)
		ft_big2a(a_stack, b_stack);
	b_stack_size = size_stack(*b_stack);
	while (b_stack_size > 0)
	{
		closest = ft_closest(*a_stack, (*b_stack)->index);
		a_stack_size = size_stack(*a_stack);
		ft_turny_a(a_stack, 'a', closest, a_stack_size);
		pa(a_stack, b_stack);
		b_stack_size--;
	}
	a_stack_size = size_stack(*a_stack);
	closest = ft_closest(*a_stack, -1);
	ft_turny_a(a_stack, 'a', closest, a_stack_size);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehay <ehay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:25:20 by ehay              #+#    #+#             */
/*   Updated: 2024/01/30 13:49:37 by ehay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stacks(t_stack **lst)
{
	t_stack	*temp;

	while (*lst)
	{
		temp = (*lst)->next;
		free(*lst);
		*lst = temp;
	}
}

int	size_stack(t_stack *lst)
{
	int	lst_len;

	lst_len = 0;
	while (lst)
	{
		lst_len++;
		lst = lst->next;
	}
	return (lst_len);
}

int	is_sorted(t_stack *a)
{
	while (a && a->next)
	{
		if (a->num > a->next->num)
			return (0);
		a = a->next;
	}
	return (1);
}

int	place_min(t_stack *stack, int min)
{
	int		min_place;
	t_stack	*current;

	current = stack;
	min_place = current->index;
	while (current)
	{
		if (current->num == min)
			min_place = current->index;
		current = current->next;
	}
	return (min_place);
}

int	min(t_stack *stack)
{
	int		min;
	t_stack	*current;

	current = stack;
	min = current->num;
	while (current)
	{
		if (current->num < min)
			min = current->num;
		current = current->next;
	}
	return (min);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehay <ehay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:27:07 by ehay              #+#    #+#             */
/*   Updated: 2024/01/19 15:31:22 by ehay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_nums(t_stack *stack1, t_stack *stack2)
{
	int		temp;
	int		temp2;

	temp = stack1->num;
	temp2 = stack1->index;
	stack1->num = stack2->num;
	stack2->num = temp;
	stack1->index = stack2->index;
	stack2->index = temp2;
}

t_stack	*ft_sort_stack(t_stack *stack)
{
	t_stack	*sorted;
	t_stack	*temp;

	sorted = ft_lstmap(stack);
	if (!sorted)
		return (NULL);
	while (is_sorted(sorted) == 0)
	{
		temp = sorted;
		while (temp->next)
		{
			if (temp->num > temp->next->num)
			{
				swap_nums(temp, temp->next);
			}
			temp = temp->next;
		}
	}
	return (sorted);
}

int	ft_addindex(t_stack **a_stack)
{
	t_stack	*sorted;
	t_stack	*temp;
	t_stack	*temp2;
	int		i;

	i = 0;
	sorted = ft_sort_stack(*a_stack);
	if (!sorted)
		return (1);
	temp2 = sorted;
	while (sorted)
	{
		sorted->index = i;
		temp = *a_stack;
		while (temp)
		{
			if (temp->num == sorted->num)
				temp->index = sorted->index;
			temp = temp->next;
		}
		sorted = sorted->next;
		i++;
	}
	free_stacks(&temp2);
	return (0);
}

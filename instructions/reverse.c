/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehay <ehay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:12:32 by ehay              #+#    #+#             */
/*   Updated: 2024/01/19 15:43:59 by ehay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_stack **a, int aprint)
{
	t_stack	*temp;
	t_stack	*last;

	if (*a && (*a)->next)
	{
		temp = *a;
		while (temp->next->next)
		{
			temp = temp->next;
		}
		last = temp->next;
		temp->next = NULL;
		last->next = *a;
		*a = last;
	}
	if (aprint == 1)
	{
		ft_printf("rra\n");
	}
}

void	rrb(t_stack **b, int aprint)
{
	t_stack	*temp;
	t_stack	*last;

	if (*b && (*b)->next)
	{
		temp = *b;
		while (temp->next->next)
		{
			temp = temp->next;
		}
		last = temp->next;
		temp->next = NULL;
		last->next = *b;
		*b = last;
	}
	if (aprint == 1)
	{
		ft_printf("rrb\n");
	}
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a, 0);
	rrb(b, 0);
	ft_printf("rrr\n");
}

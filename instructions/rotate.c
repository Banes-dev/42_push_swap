/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehay <ehay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:12:19 by ehay              #+#    #+#             */
/*   Updated: 2024/01/19 15:47:49 by ehay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_stack **a, int aprint)
{
	t_stack	*last;
	t_stack	*temp;

	if (*a && (*a)->next)
	{
		last = *a;
		*a = (*a)->next;
		last->next = NULL;
		temp = *a;
		while (temp->next)
		{
			temp = temp->next;
		}
		temp->next = last;
	}
	if (aprint == 1)
	{
		ft_printf("ra\n");
	}
}

void	rb(t_stack **b, int aprint)
{
	t_stack	*last;
	t_stack	*temp;

	if (*b && (*b)->next)
	{
		last = *b;
		*b = (*b)->next;
		last->next = NULL;
		temp = *b;
		while (temp->next)
		{
			temp = temp->next;
		}
		temp->next = last;
	}
	if (aprint == 1)
	{
		ft_printf("rb\n");
	}
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a, 0);
	rb(b, 0);
	ft_printf("rr\n");
}

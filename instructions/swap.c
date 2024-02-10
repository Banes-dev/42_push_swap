/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehay <ehay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:11:25 by ehay              #+#    #+#             */
/*   Updated: 2024/01/19 15:50:46 by ehay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_stack **a, int aprint)
{
	int	temp;

	if (*a && (*a)->next)
	{
		temp = (*a)->num;
		(*a)->num = (*a)->next->num;
		(*a)->next->num = temp;
	}
	if (aprint == 1)
	{
		ft_printf("sa\n");
	}
}

void	sb(t_stack **b, int aprint)
{
	int	temp;

	if (*b && (*b)->next)
	{
		temp = (*b)->num;
		(*b)->num = (*b)->next->num;
		(*b)->next->num = temp;
	}
	if (aprint == 1)
	{
		ft_printf("sb\n");
	}
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a, 0);
	sb(b, 0);
	ft_printf("ss\n");
}

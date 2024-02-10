/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   banes_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehay <ehay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:38:14 by ehay              #+#    #+#             */
/*   Updated: 2024/02/10 14:25:57 by ehay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	banes_sort_3(t_stack **a)
{
	if ((*a)->num > (*a)->next->num && (*a)->num > (*a)->next->next->num)
	{
		ra(a, 1);
	}
	else if ((*a)->next->num > (*a)->num
		&& (*a)->next->num > (*a)->next->next->num)
	{
		rra(a, 1);
	}
	if ((*a)->num > (*a)->next->num)
	{
		sa(a, 1);
	}
}

static void	push_min_to_b(t_stack **a, t_stack **b, int *size)
{
	int	min_three;
	int	min_tree_place;

	min_three = min(*a);
	min_tree_place = place_min(*a, min_three);
	while ((*a)->num != min_three)
	{
		if (min_tree_place >= (*size / 2))
			ra(a, 1);
		else
			rra(a, 1);
	}
	if ((*a)->num == min_three)
	{
		pb(a, b);
		(*size)--;
	}
}

void	banes_sort_45(t_stack **a, t_stack **b, int size)
{
	while (size > 3)
	{
		push_min_to_b(a, b, &size);
	}
	banes_sort_3(a);
	while (*b)
	{
		pa(a, b);
		size++;
	}
}

void	banes_sort_all(t_stack **a, t_stack **b, int size)
{
	quicksort_a2b(a, b, size);
	quicksort_b2a(a, b);
}

void	banes_sort(t_stack *a, t_stack *b, int size)
{
	if (size == 2)
	{
		sa(&a, 1);
	}
	else if (size == 3)
	{
		banes_sort_3(&a);
	}
	else if (size == 4 || size == 5 || size == 6 || size == 7)
	{
		banes_sort_45(&a, &b, size);
	}
	else
	{
		banes_sort_all(&a, &b, size);
	}
	free_stacks(&a);
	free_stacks(&b);
}

	// // ft_printf la stack a pour voir qu'elle est dans l'ordre croissant
	// ft_printf("Stack A : ");
	// while (a != NULL)
	// {
	// 	ft_printf("%i ", a->num);
	// 	a = a->next;
	// }
	// ft_printf("\n");

	// // ft_printf la stack b pour test
	// ft_printf("Stack B : ");
	// while (b != NULL)
	// {
	// 	ft_printf("%i ", b->num);
	// 	b = b->next;
	// }
	// ft_printf("\n");
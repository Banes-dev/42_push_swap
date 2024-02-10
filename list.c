/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehay <ehay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:13:16 by ehay              #+#    #+#             */
/*   Updated: 2024/02/10 13:56:26 by ehay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstnew(int num)
{
	t_stack	*add2list;

	add2list = malloc(sizeof(t_stack));
	if (add2list)
	{
		add2list->num = num;
		add2list->next = NULL;
	}
	return (add2list);
}

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	new->next = *lst;
	*lst = new;
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	while (*lst != NULL)
		lst = &(*lst)->next;
	*lst = new;
}

t_stack	*ft_lstmap(t_stack *lst)
{
	t_stack	*new_list;
	t_stack	*new_node;
	t_stack	*temp;

	new_list = NULL;
	temp = lst;
	while (temp)
	{
		new_node = ft_lstnew(temp->num);
		if (!new_node)
		{
			free_stacks(&new_list);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		temp = temp->next;
	}
	return (new_list);
}

t_stack	*ft_makelist(int argc, int *argv)
{
	t_stack	*a_stack;
	t_stack	*temp;
	int		i;

	i = 0;
	a_stack = NULL;
	while (i < argc)
	{
		temp = ft_lstnew(argv[i]);
		if (!temp)
			return (temp);
		ft_lstadd_back(&a_stack, temp);
		i++;
	}
	ft_addindex(&a_stack);
	free(argv);
	return (a_stack);
}

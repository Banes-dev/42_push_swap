/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehay <ehay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:25:23 by ehay              #+#    #+#             */
/*   Updated: 2024/02/13 13:55:52 by ehay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_sort(t_stack *a, t_stack *b)
{
	int	size_temp;

	if (is_sorted(a) == 0)
	{
		size_temp = size_stack(a);
		banes_sort(a, b, size_temp);
	}
	else
	{
		free_stacks(&a);
		free_stacks(&b);
	}
}

int	count_argv(char **argv)
{
	int	i;

	i = 0;
	while (argv[i] != NULL)
	{
		i++;
	}
	i = i -1;
	return (i);
}

int	ft_argc(int argc, char **argv)
{
	if (argc == 2)
	{
		argc = count_argv(argv);
	}
	else if (argc > 2)
	{
		argc = argc - 1;
	}
	return (argc);
}

char	**transargv(int argc, char **argv)
{
	char	**temp;
	int		i;

	temp = malloc((argc - 1) * (sizeof (char *)));
	i = 0;
	if (argc >= 2)
	{
		while (argv[i + 1] != NULL)
		{
			temp[i] = argv[i + 1];
			i++;
		}
	}
	return (temp);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		*argv_atoi;
	char	**new_argv;
	int		new_argc;

	if (argc != 1)
	{
		new_argv = transargv(argc, argv);
		new_argc = ft_argc(argc, new_argv);
		argv_atoi = checkerror(new_argv, new_argc);
		if (argv_atoi == NULL)
		{
			ft_printf("Error\n");
			return (0);
		}
		a = ft_makelist(new_argc, argv_atoi);
		if (!a)
			return (0);
		b = NULL;
		exec_sort(a, b);
	}
	return (0);
}

	// if (argc == 2)
	// {
	// 	temp = split(argv[1], " ");
	// }
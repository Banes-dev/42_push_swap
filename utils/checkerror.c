/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerror.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehay <ehay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:43:14 by ehay              #+#    #+#             */
/*   Updated: 2024/02/10 13:56:08 by ehay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	checkifnum(char **argv, int argc)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (1);
			j++;
		}
		if (j == 0)
			return (1);
		i++;
	}
	return (0);
}

long	ft_atoi(const char *nptr)
{
	long	nbr;
	int		sign;
	size_t	i;

	nbr = 0;
	sign = 1;
	i = 0;
	while (nptr[i] == ' ' || ('\t' <= nptr[i] && nptr[i] <= '\r'))
		i++;
	if (nptr[i] == '+')
		i++;
	else if (nptr[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while ('0' <= nptr[i] && nptr[i] <= '9')
	{
		nbr = nbr * 10 + nptr[i] - '0';
		i++;
	}
	return (nbr * sign);
}

int	*checkatoi(char **acheck, int nbdenombre)
{
	int		i;
	int		j;
	long	nombre;
	int		*nombre_list;

	i = 0;
	j = 0;
	nombre_list = malloc(nbdenombre * sizeof(int));
	if (nombre_list == NULL)
		return (NULL);
	while (i < nbdenombre)
	{
		nombre = ft_atoi(acheck[i]);
		if (nombre < INT_MIN || nombre > INT_MAX)
		{
			free(nombre_list);
			return (NULL);
		}
		nombre_list[j] = (int)nombre;
		i++;
		j++;
	}
	return (nombre_list);
}

int	checkifdoublon(int *acheck, int nbdenombre)
{
	int	i;
	int	j;

	i = 0;
	while (i < nbdenombre)
	{
		j = i + 1;
		while (j < nbdenombre)
		{
			if (acheck[i] == acheck[j])
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	*checkerror(char **argv, int nbdenombre)
{
	int	error_state;
	int	*argv_int;

	error_state = 0 ;
	if (checkifnum(argv, nbdenombre) == 1)
		error_state = 1;
	argv_int = checkatoi(argv, nbdenombre);
	if (argv_int == NULL)
		error_state = 1;
	if (error_state == 0)
	{
		if (checkifdoublon(argv_int, nbdenombre) == 1)
			error_state = 1;
	}
	if (error_state == 1)
	{
		free(argv_int);
		argv_int = NULL;
	}
	free(argv);
	return (argv_int);
}

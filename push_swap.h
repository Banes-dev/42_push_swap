/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehay <ehay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:26:59 by ehay              #+#    #+#             */
/*   Updated: 2024/02/10 12:54:41 by ehay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "unistd.h"
# include "stdlib.h"          // malloc & free
# include "stdarg.h"          // fonction va_
# include "stddef.h"          // size_t
# include "limits.h"          // INT_MIN et INT_MAX

typedef struct s_stack
{
	int				index;
	int				num;
	struct s_stack	*next;
}					t_stack;

// Sort //
void	quicksort_a2b(t_stack **a_stack, t_stack **b_stack, int a_size);
void	quicksort_b2a(t_stack **a_stack, t_stack **b_stack);
void	banes_sort(t_stack *a, t_stack *b, int size);

// Instrucstions // 
void	sa(t_stack **a, int aprint);
void	sb(t_stack **b, int aprint);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a, int aprint);
void	rb(t_stack **b, int aprint);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a, int aprint);
void	rrb(t_stack **b, int aprint);
void	rrr(t_stack **a, t_stack **b);

// Stack //
t_stack	*ft_makelist(int argc, int *argv);
t_stack	*ft_lstmap(t_stack *lst);
t_stack	*ft_sort_stack(t_stack *stack);
int		ft_addindex(t_stack **a_stack);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
void	ft_lstadd_back(t_stack **lst, t_stack *new);

// Utils //
void	free_stacks(t_stack **lst);
int		size_stack(t_stack *lst);
int		is_sorted(t_stack *a);
int		place_min(t_stack *stack, int min);
int		min(t_stack *stack);
int		is_sorted(t_stack *a);
void	ft_turny_a(t_stack **stack, char a_b, int depth, int size);
void	ft_turny_b(t_stack **stack, char a_b, int depth, int size);

// Check Error
int		*checkerror(char **argv, int argc);

// Split
char	*ft_strchr(const char *s, int c);
char	*ft_strndup(const char *s, size_t n);
size_t	ft_word_len(char const *str, char const *sep);
size_t	ft_count_word(char const *str, char const *sep);
void	ft_split_free(char **split);
char	**split(char const *s, char *sep);

// Printf //
int		ft_printf(const char *format, ...);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr(int nb);
int		ft_putnbr_unsigned(unsigned int n);
int		ft_putpointer(void *adress);
int		ft_puthexalower(long double number);
int		ft_puthexaupper(long double number);

#endif
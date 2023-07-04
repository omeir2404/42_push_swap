/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oharoon <oharoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:56:45 by oharoon           #+#    #+#             */
/*   Updated: 2023/03/04 17:34:21 by oharoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_list
{
	int				value;
	int				len;
	struct s_list	*next;
}					t_list;

// typedef struct s_stack
// {
// 	t_list	*a;
// 	t_list	*b;
// }	t_stack;

int		check_input(int ac, char **arg);
t_list	*add_to_stack(char *num);
int		ft_atoi_ps(const char *str);
int		duplicates(int ac, char **arg);
void	print_stack(t_list *stack);

void	swap(t_list **stack);
void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);
void	print_both(t_list *stack_a, t_list *stack_b);
void	pb(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);
void	ra(t_list **stack);
void	rotate(t_list **stack);
void	rb(t_list **stack);
void	reverse_rotate(t_list **stack);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);

void	sort_2(t_list **stack_a);
void	sort_3(t_list **stack);
void	sort_4(t_list **stack_a, t_list **stack_b);
void	sort_5(t_list **stack_a, t_list **stack_b);
void	aux_sort_5(t_list **stack, int third, int fourth, int fifth);

void	back_a(t_list **a, t_list **b, int count);
int		ft_get_node_index(t_list **stack, int index);
void	small_stack(t_list **a, t_list **b);
int		ordered(t_list **a);
int		check_last(t_list **stack);

int		find_small(t_list **stack);
int		find_big(t_list **stack);
void	to_b(t_list **a, t_list **b);
void	to_be_aux(t_list **a, t_list **b);

int		*make_array(t_list **stack, int size);
int		mid_val(int *arr, int ac);
int		quart_val(int *arr, int size);
int		*array_sort(int *arr, int n);
void	swap_ip(int *a, int *b);

void	put_back(t_list **a, t_list **b);
int		last_val(t_list **a);
void	check_second(t_list **a, t_list **b);
void	check_second_back(t_list **a, t_list **b);
int		check_last_2push(t_list **a, t_list **b, int b_val);
void	one_more_aux_1(t_list **a, t_list **b);
int		one_more_aux_2(t_list **a, t_list **b);
int		aux_if_1(t_list **a, t_list **b, int count);
int		aux_if_2(t_list **a, t_list **b);

void	try_radix(t_list **a, t_list **b);

int		ft_atoi(const char *str);

t_list	*ft_lstnew(int value);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*lstnew_ps(int value);
char	**ft_split(char const *s, char c);
char	*create_str(char *str, int i, char **lst, char c);
int		word_count(char const *s, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
t_list	*check_split(char **arg);
void	main_aux(t_list **a, t_list **b);

void	free_list(t_list *list);
#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oharoon <oharoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:21:08 by oharoon           #+#    #+#             */
/*   Updated: 2023/01/20 19:58:36 by oharoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// void ra(t_list **stack)
// {
// 	t_list *last;
// 	t_list *first;
// 	t_list *second_last;
// 	int count;

// 	count = 1;

// 	if (ft_lstsize(*stack) < 2)
// 		return;
// 	first = (*stack); // tmp is first
// 	last = (*stack);
// 	second_last = (*stack);
// 	while (last->next != NULL)
// 		last = last->next; // last is last!
// 	while (count++ < ft_lstsize(*stack) - 1)
// 		second_last = second_last->next; // second_last is second last
// 	(*stack) = last;					 // stack is now last
// 	second_last->next = (*stack);
// 	(*stack)->next = NULL;
// 	last = first; // last is now first
// }
// void	ra(t_list **stack)
// {
// 	t_list	*last;
// 	t_list	*temp;

// 	last = (*stack);
// 	while (last->next != NULL)
// 		last = last->next;
// 	temp = (*stack);
// 	printf("%i\n", temp->value);
// 	(*stack)->value = last->value;
// 	printf("%i\n", temp->value);
// 	last->value = temp->value;
// }

void	rotate(t_list **stack)
{
	t_list	*first;
	t_list	*last;
	t_list	*temp;

	temp = *stack;
	if (!(temp && temp->next))
		return ;
	first = temp;
	temp = temp->next;
	last = temp;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
	*stack = temp;
}

void	ra(t_list **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_list **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_list **a, t_list **b)
{
	ra(a);
	rb(b);
	write(1, "rr\n", 3);
}

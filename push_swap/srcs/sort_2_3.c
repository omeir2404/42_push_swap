/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oharoon <oharoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:29:20 by oharoon           #+#    #+#             */
/*   Updated: 2023/03/04 17:35:47 by oharoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_2(t_list **stack_a)
{
	t_list	*first;
	t_list	*second;

	first = (*stack_a);
	second = first->next;
	if (first->value > second->value)
		sa(stack_a);
	return ;
}

void	sort_3(t_list **stack)
{
	int	first;
	int	second;
	int	third;

	first = (*stack)->value;
	second = (*stack)->next->value;
	third = (*stack)->next->next->value;
	if (first > second && second > third)
	{
		ra(stack);
		sa(stack);
	}
	else if (first < second && second < third)
		return ;
	else if (first > second && second < third && first < third)
		sa(stack);
	else if (first < third && first < second && second > third)
	{
		rra(stack);
		sa(stack);
	}
	else if (first < second && first > third && second > third)
		rra(stack);
	else if (first > second && first > third && second < third)
		ra(stack);
}

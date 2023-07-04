/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oharoon <oharoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:52:38 by oharoon           #+#    #+#             */
/*   Updated: 2023/03/04 21:06:19 by oharoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_4(t_list **stack_a, t_list **stack_b)
{
	int	first;
	int	second;
	int	third;
	int	fourth;

	first = (*stack_a)->value;
	second = (*stack_a)->next->value;
	third = (*stack_a)->next->next->value;
	fourth = (*stack_a)->next->next->next->value;
	if (fourth > third && third > second && second > first)
		return ;
	else if (second < first && second < third && second < fourth)
		ra(stack_a);
	else if (third < first && third < second && third < fourth)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (fourth < first && fourth < second && fourth < third)
		rra(stack_a);
	pb(stack_a, stack_b);
	sort_3(stack_a);
	pa(stack_a, stack_b);
}

void	aux_sort_5(t_list **stack_a, int third, int fourth, int fifth)
{
	if (fifth > fourth && fourth > third && third > (*stack_a)->next->value
		&& (*stack_a)->next->value > (*stack_a)->value)
		return ;
	if ((*stack_a)->next->value < (*stack_a)->value
		&& (*stack_a)->next->value < third && (*stack_a)->next->value < fourth
		&& (*stack_a)->next->value < fifth)
		ra(stack_a);
	if (third < (*stack_a)->value && third < (*stack_a)->next->value && third
		< fourth && third < fifth)
	{
		ra(stack_a);
		ra(stack_a);
	}
	if (fourth < (*stack_a)->value && fourth < (*stack_a)->next->value && fourth
		< third && fourth < fifth)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (fifth < (*stack_a)->value && fifth < (*stack_a)->next->value
		&& fifth < third && fifth < fourth)
		rra(stack_a);
}

void	sort_5(t_list **stack_a, t_list **stack_b)
{
	int	third;
	int	fourth;
	int	fifth;

	if (!(ft_lstsize((*stack_a)) == 5))
		return ;
	if (ordered(stack_a))
		return ;
	third = (*stack_a)->next->next->value;
	fourth = (*stack_a)->next->next->next->value;
	fifth = (*stack_a)->next->next->next->next->value;
	aux_sort_5(stack_a, third, fourth, fifth);
	pb(stack_a, stack_b);
	sort_4(stack_a, stack_b);
	pa(stack_a, stack_b);
}

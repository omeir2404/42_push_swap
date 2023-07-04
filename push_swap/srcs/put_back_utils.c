/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_back_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oharoon <oharoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 20:24:38 by oharoon           #+#    #+#             */
/*   Updated: 2023/02/25 20:33:42 by oharoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	check_second(t_list **a, t_list **b)
{
	if ((*b))
	{
		if ((*b)->next && (*b)->next->value > (*b)->value
			&& (*b)->next->value < (*a)->value
			&& (*b)->next->value > check_last(a))
		{
			sb(b);
			pa(a, b);
		}
	}
}

void	check_second_back(t_list **a, t_list **b)
{
	if ((*b))
	{
		if ((*b)->next && (*b)->next->value > (*b)->value
			&& (*b)->next->value < (*a)->value
			&& (*b)->next->value > check_last(a))
		{
			sb(b);
			pa(a, b);
			ra(a);
		}
	}
}

int	check_last_2push(t_list **a, t_list **b, int b_val)
{
	t_list	*temp;

	temp = (*a);
	while (temp->next)
		temp = temp->next;
	if (b_val > temp->value)
	{
		pa(a, b);
		ra(a);
		return (1);
	}
	return (0);
}

void	check_last_b(t_list **a, t_list **b)
{
	t_list	*last;

	last = (*b);
	while (last->next)
		last = last->next;
	if (last->value < (*a)->value)
		pa(a, b);
	if (last->value > (*b)->value
		&& last->value < (*a)->value && last->value > check_last(a))
	{
		rb(b);
		pa(a, b);
	}
}

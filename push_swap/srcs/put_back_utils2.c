/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_back_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oharoon <oharoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 20:47:15 by oharoon           #+#    #+#             */
/*   Updated: 2023/03/04 16:17:48 by oharoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	one_more_aux_1(t_list **a, t_list **b)
{
	int	bval;

	if (!(*b))
		return ;
	bval = (*b)->value;
	while (bval < (*a)->value && bval > last_val(a))
	{
		pa(a, b);
		if (*b)
			bval = (*b)->value;
	}
}

int	one_more_aux_2(t_list **a, t_list **b)
{
	int	bval;
	int	helper;

	if ((*b))
		bval = (*b)->value;
	helper = 0;
	while (bval < (*a)->value && bval > last_val(a))
	{
		pa(a, b);
		if ((*b))
			bval = (*b)->value;
		helper++;
		ra(a);
	}
	if ((*b) && (*b)->next && (*b)->value < (*b)->next->value)
	{
		sb(b);
		pa(a, b);
		ra(a);
	}
	return (helper);
}

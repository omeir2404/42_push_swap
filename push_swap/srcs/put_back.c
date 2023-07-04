/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_back.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oharoon <oharoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 20:24:54 by oharoon           #+#    #+#             */
/*   Updated: 2023/02/27 18:32:06 by oharoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	before_mid(t_list **a, t_list **b, int count)
{
	int	helper;

	helper = 0;
	check_second(a, b);
	while (helper <= count)
	{
		ra(a);
		check_second(a, b);
		helper++;
	}
	pa(a, b);
	while (helper > 0)
	{
		one_more_aux_1(a, b);
		rra(a);
		check_second(a, b);
		helper--;
	}
}

void	after_mid(t_list **a, t_list **b, int count)
{
	int	helper;
	int	help2;

	helper = 0;
	help2 = 0;
	while (helper < count - 1)
	{
		rra(a);
		helper++;
	}
	pa(a, b);
	while (helper >= 0)
	{
		help2 = one_more_aux_2(a, b);
		while (help2 > 0)
			helper--;
		check_second_back(a, b);
		ra(a);
		helper--;
	}
}

void	back_a(t_list **a, t_list **b, int count)
{
	int	a_size;

	a_size = ft_lstsize((*a));
	if (count < (a_size / 2))
		before_mid(a, b, count);
	else if (count >= (a_size / 2))
		after_mid(a, b, a_size - count);
}

int	aux_if_2(t_list **a, t_list **b)
{
	if ((*b)->value < (*a)->value)
	{
		pa(a, b);
		return (1);
	}
	return (0);
}

void	put_back(t_list **a, t_list **b)
{
	int		count;
	t_list	*aval;

	count = 0;
	aval = (*a);
	while (ft_lstsize((*b)) > 0 && (*b))
	{
		check_last_2push(a, b, (*b)->value);
		if (aux_if_2(a, b) == 1)
			aval = (*a);
		else if (aval->next)
		{
			if ((*b)->value < aval->next->value && (*b)->value > aval->value)
			{
				back_a(a, b, count);
				count = 0;
				aval = (*a);
			}
			else
			{
				aval = aval->next;
				count++;
			}
		}
	}
}

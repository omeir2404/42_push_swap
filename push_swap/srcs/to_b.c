/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_b.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oharoon <oharoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 12:35:56 by oharoon           #+#    #+#             */
/*   Updated: 2023/03/04 17:48:44 by oharoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	to_be_aux(t_list **a, t_list **b)
{
	int	*arr;
	int	val;
	int	a_size;
	int	count;

	arr = NULL;
	count = 6;
	while (count > 0)
	{
		arr = make_array(a, ft_lstsize((*a)));
		arr = array_sort(arr, ft_lstsize((*a)));
		val = quart_val(arr, ft_lstsize((*a)));
		a_size = ft_lstsize((*a));
		while (a_size > 0)
		{
			if ((*a)->value < val)
				pb(a, b);
			else
				ra(a);
			a_size--;
		}
		count--;
		free(arr);
	}
}

void	to_b(t_list **a, t_list **b)
{
	int	*arr;
	int	val;
	int	a_size;

	arr = NULL;
	to_be_aux(a, b);
	while (!(ft_lstsize((*a)) == 5) && !ordered(a))
	{
		arr = make_array(a, ft_lstsize((*a)));
		arr = array_sort(arr, ft_lstsize((*a)));
		val = mid_val(arr, ft_lstsize((*a)));
		a_size = ft_lstsize((*a));
		while (a_size > 0)
		{
			if ((*a)->value < val && !(ft_lstsize((*a)) == 5) && !ordered(a))
				pb(a, b);
			else if (!(ft_lstsize((*a)) == 5) && !ordered(a))
				ra(a);
			a_size--;
		}
		free(arr);
	}
	sort_5(a, b);
}

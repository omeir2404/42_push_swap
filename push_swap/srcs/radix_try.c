/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_try.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oharoon <oharoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 17:27:36 by oharoon           #+#    #+#             */
/*   Updated: 2023/02/25 18:06:17 by oharoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	try_radix(t_list **a, t_list **b)
{
	int	size;
	int	max_num;
	int	max_bits;
	int	i;
	int	j;

	size = ft_lstsize((*a));
	max_num = size - 1;
	max_bits = 0;
	i = -1;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	while (++i < max_bits)
	{
		j = -1;
		while (++j < size)
		{
			if ((((*a)->value >> i) & 1) == 1)
				ra(a);
			else
				pb(a, b);
		}
		while ((*b))
			pa(a, b);
	}
}

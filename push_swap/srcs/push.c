/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oharoon <oharoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:54:17 by oharoon           #+#    #+#             */
/*   Updated: 2023/01/20 19:57:34 by oharoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pb(t_list **a, t_list **b)
{
	t_list	*temp;

	if (!(*a))
		return ;
	temp = (*a)->next;
	(*a)->next = (*b);
	(*b) = (*a);
	(*a) = temp;
	write(1, "pb\n", 3);
}

void	pa(t_list **a, t_list **b)
{
	t_list	*temp;

	if (!(*b))
		return ;
	temp = (*b)->next;
	(*b)->next = (*a);
	(*a) = (*b);
	(*b) = temp;
	write(1, "pa\n", 3);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oharoon <oharoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:42:01 by oharoon           #+#    #+#             */
/*   Updated: 2023/01/20 19:59:02 by oharoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_list **stack)
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (ft_lstsize(*stack) < 2)
		return ;
	tmp1 = (*stack)->next;
	tmp2 = (*stack)->next;
	(*stack)->next = tmp2->next;
	tmp1->next = (*stack);
	(*stack) = tmp2;
}

void	sa(t_list **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_list **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_list **a, t_list **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}

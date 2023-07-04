/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oharoon <oharoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:36:26 by oharoon           #+#    #+#             */
/*   Updated: 2023/02/25 20:24:00 by oharoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_big(t_list **stack)
{
	t_list	*temp;
	int		biggest;

	if ((*stack))
		biggest = (*stack)->value;
	temp = (*stack);
	while (temp)
	{
		if (temp->value > biggest)
			biggest = temp->value;
		if (temp->next)
			temp = temp->next;
		else
			return (biggest);
	}
	return (biggest);
}

int	find_small(t_list **stack)
{
	t_list	*temp;
	int		smallest;

	smallest = (*stack)->value;
	temp = (*stack);
	while (temp)
	{
		if (temp->value < smallest)
			smallest = temp->value;
		if (temp->next)
			temp = temp->next;
		else
			return (smallest);
	}
	return (smallest);
}

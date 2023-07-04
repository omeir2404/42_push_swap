/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oharoon <oharoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:32:18 by oharoon           #+#    #+#             */
/*   Updated: 2023/02/25 18:01:04 by oharoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ordered(t_list **a)
{
	t_list	*temp;

	temp = (*a);
	while (temp->next)
	{
		if (!(temp->value < temp->next->value))
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	reversed(t_list **a)
{
	t_list	*temp;

	temp = (*a);
	while (temp->next)
	{
		if (temp->value > temp->next->value)
			temp = temp->next;
		else
			return (0);
	}
	return (1);
}

int	check_last(t_list **stack)
{
	t_list	*temp;

		temp = (*stack);
	while (temp->next)
		temp = temp->next;
	return (temp->value);
}

int	last_val(t_list **a)
{
	int		val;
	t_list	*temp;

	temp = (*a);
	while (temp->next)
		temp = temp->next;
	val = temp->value;
	return (val);
}

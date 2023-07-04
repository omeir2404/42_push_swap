/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oharoon <oharoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:06:47 by oharoon           #+#    #+#             */
/*   Updated: 2023/03/04 20:54:17 by oharoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_get_node_index(t_list **stack, int index)
{
	int		i;
	t_list	*temp;

	temp = (*stack);
	i = 0;
	while (temp && i < index)
	{
		if (temp->next)
			temp = temp->next;
		i++;
	}
	return (temp->value);
}

t_list	*add_to_stack(char *num)
{
	t_list	*node;

	node = lstnew_ps(ft_atoi(num));
	return (node);
}

void	small_stack(t_list **a, t_list **b)
{
	if (ft_lstsize((*a)) == 2)
		sort_2(a);
	else if (ft_lstsize((*a)) == 3)
		sort_3(a);
	else if (ft_lstsize((*a)) == 4)
		sort_4(a, b);
	else if (ft_lstsize((*a)) == 5)
		sort_5(a, b);
	if (!(*b) && ordered(a))
		return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstnew_ps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oharoon <oharoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 12:58:29 by oharoon           #+#    #+#             */
/*   Updated: 2023/03/04 17:22:59 by oharoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*lstnew_ps(int value)
{
	t_list	*newnode;

	newnode = malloc(sizeof(t_list));
	if (!newnode)
		return (NULL);
	newnode->value = value;
	newnode->next = NULL;
	return (newnode);
}

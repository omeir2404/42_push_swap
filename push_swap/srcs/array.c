/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oharoon <oharoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 13:51:44 by oharoon           #+#    #+#             */
/*   Updated: 2023/02/25 20:11:49 by oharoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*make_array(t_list **stack, int size)
{
	int		*v;
	int		i;
	t_list	*temp;

	i = 0;
	temp = (*stack);
	v = malloc((size) * sizeof(int));
	while (i < size || temp)
	{
		v[i] = temp->value;
		temp = temp->next;
		i++;
	}
	return (v);
}

void	swap_ip(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	*array_sort(int *arr, int n)
{
	int	i;
	int	j;
	int	min;

	i = 0;
	while (i < n - 1)
	{
		min = i;
		j = i + 1;
		while (j < n)
		{
			if (arr[j] < arr[min])
				min = j;
			j++;
		}
		swap_ip(&arr[min], &arr[i]);
		i++;
	}
	return (arr);
}

int	mid_val(int *arr, int size)
{
	int	val;
	int	index;

	index = (size) / 2;
	val = arr[index];
	return (val);
}

int	quart_val(int *arr, int size)
{
	int	val;
	int	index;

	index = 0;
	if (size >= 4)
		index = (size) / 4;
	else if (size >= 3)
		index = (size) / 3;
	else if (size >= 2)
		index = (size) / 2;
	val = arr[index];
	return (val);
}

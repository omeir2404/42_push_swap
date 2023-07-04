/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oharoon <oharoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 12:48:49 by oharoon           #+#    #+#             */
/*   Updated: 2023/03/04 21:07:29 by oharoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_list	*check_split(char **arg)
{
	t_list	*stack_a;
	char	**hold;
	int		count_args;

	count_args = 0;
	hold = NULL;
	stack_a = NULL;
	hold = ft_split(arg[1], 32);
	stack_a = add_to_stack(hold[count_args++]);
	while (hold[count_args])
		ft_lstadd_back(&stack_a, add_to_stack(hold[count_args++]));
	while (count_args >= 0)
		free(hold[count_args--]);
	free(hold);
	return (stack_a);
}

void	free_list(t_list *list)
{
	t_list	*tmp;

	while (list)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}	
}

void	main_aux(t_list **a, t_list **b)
{
	if (ft_lstsize((*a)) < 6)
		small_stack(a, b);
	else if (ft_lstsize((*a)) >= 6 && ft_lstsize((*a)) <= 151)
	{
		to_b(a, b);
		put_back(a, b);
	}
	else if (ft_lstsize((*a)) > 152)
		try_radix(a, b);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		count_args;

	count_args = 1;
	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1)
		exit(0);
	if (ac == 2)
		stack_a = check_split(av);
	else
	{
		count_args = 1;
		check_input(ac, av);
		stack_a = add_to_stack(av[count_args++]);
		while (count_args < ac)
			ft_lstadd_back(&stack_a, add_to_stack(av[count_args++]));
	}
	if (!ordered(&stack_a))
		main_aux(&stack_a, &stack_b);
	free_list(stack_a);
	free_list(stack_b);
}

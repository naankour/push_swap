/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naankour <naankour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 09:29:24 by naankour          #+#    #+#             */
/*   Updated: 2025/02/05 11:55:47 by naankour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *stack_a)
{
	if (!stack_a)
		return (1);
	while (stack_a && stack_a->next)
	{
		if (stack_a->value > stack_a->next->value)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

t_list	*parse_arguments(int argc, char **argv)
{
	int		i;
	int		num;
	char	**tab;
	t_list	*stack_a;

	stack_a = NULL;
	if (argc == 2 && ft_strchr(argv[1], ' ') != NULL)
	{
		tab = ft_split(argv[1], ' ');
		if (!tab)
			return (NULL);
	}
	else
		tab = &argv[1];
	i = 0;
	while (tab[i] != NULL)
	{
		if (ft_error(tab, stack_a, i, num))
			return (free_list(stack_a), NULL);
		num = ft_atoi(tab[i]);
		ft_addnode_back(&stack_a, ft_create_node(num));
		i++;
	}
	return (stack_a);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		size;

	stack_a = parse_arguments(argc, argv);
	if (!stack_a)
		return (1);
	if (is_sorted(stack_a))
	{
		free_list(stack_a);
		return (0);
	}
	stack_b = NULL;
	size = ft_lstsize(stack_a);
	if (size == 2)
		algo_2(&stack_a);
	else if (size == 3)
		algo_3(&stack_a);
	else if (size == 4 || size == 5)
		algo_5(&stack_a, &stack_b);
	else
		algo_n(&stack_a, &stack_b);
	free_list(stack_a);
	free_list(stack_b);
}

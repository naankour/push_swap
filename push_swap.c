/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazihaaankour <nazihaaankour@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 09:29:24 by naankour          #+#    #+#             */
/*   Updated: 2025/01/31 21:23:03 by nazihaaanko      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// void	free_tab(char **tab)
// {
// 	int	i;

// 	i = 0;
// 	while (tab[i] != NULL)
// 	{
// 		free(tab[i]);
// 		i++;
// 	}
// 	free(tab);
// }
int	main(int argc, char **argv)
{
	int	i;
	int	num;
	char	**tab;
	t_list	*stack_a = NULL;
	t_list	*stack_b = NULL;
	int	size;

	if (argc == 2 && ft_strchr(argv[1], ' ') != NULL)
		tab = ft_split(argv[1], ' ');
	else
		tab = &argv[1];
	i = 0;
	stack_a = NULL;
	while (tab[i] != NULL)
	{
		if (ft_error(tab, stack_a, i, num))
		{
			free_list(stack_a);
			return (1);
		}
		num = ft_atoi(tab[i]);
		ft_addnode_back(&stack_a, ft_create_node(num));
		i++;
	}
	size = ft_lstsize(stack_a);
	if (size == 2)
		algo_2(&stack_a);
	if (size == 3)
		algo_3(&stack_a);
	if (size == 4 || size == 5)
		algo_5(&stack_a, &stack_b);
	else 
        algo_n(&stack_a, &stack_b);
	// print_list(stack_a);
	free_list(stack_a);
	return (0);
}
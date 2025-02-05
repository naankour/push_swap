/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_n.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naankour <naankour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:04:01 by naankour          #+#    #+#             */
/*   Updated: 2025/02/05 15:22:56 by naankour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	search_max(t_list *stack)
{
	int		i;
	int		max;
	int		position;
	t_list	*temp;

	if (stack == NULL)
		return (-1);
	i = 0;
	temp = stack;
	max = temp->value;
	position = 0;
	while (temp != NULL)
	{
		if (temp->value > max)
		{
			max = temp->value;
			position = i;
		}
		temp = temp->next;
		i++;
	}
	return (position);
}

static void	move_largest_to_top(t_list **stack_b)
{
	int		size;
	int		max_position;

	size = ft_lstsize(*stack_b);
	max_position = search_max(*stack_b);
	if (max_position < size / 2)
	{
		while (max_position > 0)
		{
			rb(stack_b, 1);
			max_position--;
		}
	}
	else
	{
		while (max_position < size)
		{
			rrb(stack_b, 1);
			max_position++;
		}
	}
}

static void	sort_stack_b(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_b);
	while (*stack_b)
	{
		search_max(*stack_b);
		move_largest_to_top(stack_b);
		pa(stack_a, stack_b, 1);
	}
}

void	algo_n(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	median;

	if (!stack_a || !(*stack_a))
		return ;
	size = ft_lstsize(*stack_a);
	median = 0;
	if (size <= 100)
		while (ft_lstsize(*stack_a) > 5)
			push_small_to_b(stack_a, stack_b, median);
	else
		while (ft_lstsize(*stack_a) > 5)
			find_chunk_lim(stack_a, stack_b, 5);
	algo_5(stack_a, stack_b);
	sort_stack_b(stack_a, stack_b);
}

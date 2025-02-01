/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naankour <naankour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:18:34 by naankour          #+#    #+#             */
/*   Updated: 2025/01/28 13:18:34 by naankour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

static int search_min(t_list *stack)
{
	if (stack == NULL)
		return -1;
	int i = 0;
	int min = stack->value;
	int position = 0;
	t_list *temp = stack;

	while (temp != NULL)
	{
		if (temp->value < min)
		{
			min = temp->value;
			position = i;
		}
		temp = temp->next;
		i++;
	}
	return position;
}

int ft_lstsize(t_list *lst)
{
	int i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return i;
}

static void push_min_to_b(t_list **stack_a, t_list **stack_b)
{
	int min_position = search_min(*stack_a);
	int size = ft_lstsize(*stack_a);
	if (min_position <= (size / 2))
		while (min_position > 0)
		{
			ra(stack_a, 1);
			min_position--;
		}
	else
	{
		int moves = size - min_position;
		while (moves > 0)
		{
				rra(stack_a, 1);
				moves--;
		}
	}
	pb(stack_a, stack_b, 1);
}

void algo_5(t_list **stack_a, t_list **stack_b)
{
	push_min_to_b(stack_a, stack_b);
	push_min_to_b(stack_a, stack_b);
	if (ft_lstsize(*stack_a) == 3) 
		algo_3(stack_a);
	else if (ft_lstsize(*stack_a) == 2)
		algo_2(stack_a);
	pa(stack_a, stack_b, 1);
	pa(stack_a, stack_b, 1);
}

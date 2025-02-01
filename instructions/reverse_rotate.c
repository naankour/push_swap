/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naankour <naankour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:09:10 by naankour          #+#    #+#             */
/*   Updated: 2025/01/24 15:09:10 by naankour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_list **stack_a, int print)
{
	t_list	*cur;
	t_list	*prev;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	cur = *stack_a;
	prev = NULL;
	while (cur->next != NULL)
	{
		prev = cur;
		cur = cur->next;
	}
	cur->next = *stack_a;
	prev->next = NULL;
	*stack_a = cur;
	if (print)
		write(1, "rra\n", 4);
}

void	rrb(t_list **stack_b, int print)
{
	t_list	*cur;
	t_list	*prev;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	cur = *stack_b;
	prev = NULL;
	while (cur->next != NULL)
	{
		prev = cur;
		cur = cur->next;
	}
	cur->next = *stack_b;
	prev->next = NULL;
	*stack_b = cur;
	if (print)
		write(1, "rrb\n", 4);
}

void	rrr(t_list **stack_a, t_list **stack_b, int print)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	if (print)
		write(1, "rrr\n", 3);
}

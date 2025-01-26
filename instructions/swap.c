/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naankour <naankour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:01:00 by naankour          #+#    #+#             */
/*   Updated: 2025/01/24 15:01:00 by naankour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_list **stack_a, int print)
{
	t_list	*temp;

	if (*stack_a != NULL && (*stack_a)->next != NULL)
	{
		temp = (*stack_a)->next;
		(*stack_a)->next = temp->next;
		temp->next = *stack_a;
		*stack_a = temp;
		if (print)
			write(1, "sa\n", 3);
	}
}

void	swap_b(t_list **stack_b, int print)
{
	t_list	*temp;

	if (*stack_b != NULL && (*stack_b)->next != NULL)
	{
		temp = (*stack_b)->next;
		(*stack_b)->next = temp->next;
		temp->next = *stack_b;
		*stack_b = temp;
		if (print)
			write(1, "sb\n", 3);
	}
}

void	swap_ss(t_list **stack_a, t_list **stack_b)
{
	swap_a(stack_a, 0);
	swap_b(stack_b, 0);
	write(1, "ss\n", 3);
}

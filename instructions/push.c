/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naankour <naankour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:10:18 by naankour          #+#    #+#             */
/*   Updated: 2025/01/24 15:10:18 by naankour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_list **stack_a, t_list **stack_b, int print)
{
	t_list	*temp;

	if (stack_b == NULL || *stack_b == NULL)
		return ;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = *stack_a;
	*stack_a = temp;
	if (print)
		write(1, "pa\n", 3);
}

void	push_b(t_list **stack_a, t_list **stack_b, int print)
{
	t_list	*temp;

	if (stack_a == NULL || *stack_a == NULL)
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = *stack_b;
	*stack_b = temp;
	if (print)
		write(1, "pb\n", 3);
}

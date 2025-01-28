/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naankour <naankour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:03:56 by naankour          #+#    #+#             */
/*   Updated: 2025/01/24 15:03:56 by naankour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_ra(t_list **stack_a, int print)
{
	t_list	*temp;
	t_list	*last;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	last = *stack_a;
	while (last->next != NULL)
		last = last->next;
	last->next = temp;
	temp->next = NULL;
	if (print)
		write(1, "ra\n", 3);
}

void	rotate_rb(t_list **stack_b, int print)
{
	t_list	*temp;
	t_list	*last;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	last = *stack_b;
	while (last->next != NULL)
		last = last->next;
	last->next = temp;
	temp->next = NULL;
	if (print)
		write(1, "rb\n", 3);
}

void	rotate_rr(t_list **stack_a, t_list **stack_b)
{
	rotate_ra(stack_a, 0);
	rotate_rb(stack_b, 0);
	write(1, "rr\n", 3);
}

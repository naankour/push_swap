/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naankour <naankour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 16:33:28 by naankour          #+#    #+#             */
/*   Updated: 2025/01/26 16:33:28 by naankour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_3(t_list **stack_a)
{
	int	A = (*stack_a)->value;
	int	B = (*stack_a)->next->value;
	int	C = (*stack_a)->next->next->value;

	if (*stack_a == NULL || (*stack_a)->next == NULL || (*stack_a)->next->next == NULL)
		return ;
	if (A < B && B < C)
		return ;
	if (A < C && B < A)
		swap_a(stack_a, 1);
	else if (A < B && C < A)
		reverse_rotate_ra(stack_a, 1);
	else if (B < C && C < A)
		rotate_ra(stack_a, 1);
	else if (A < C && C < B)
	{
		swap_a(stack_a, 1);
		rotate_ra(stack_a, 1);
	}
	else if (B < A && C < B)
	{
		rotate_ra(stack_a, 1);
		swap_a(stack_a, 1);
	}
}

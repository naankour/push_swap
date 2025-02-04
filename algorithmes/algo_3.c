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

#include "../push_swap.h"

void	algo_3(t_list **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->value;
	b = (*stack_a)->next->value;
	c = (*stack_a)->next->next->value;
	if (*stack_a == NULL || (*stack_a)->next == NULL || (*stack_a)->next->next == NULL)
		return ;
	if (a < b && b < c)
		return ;
	if (a < c && b < a)
		sa(stack_a, 1);
	else if (a < b && c < a)
		rra(stack_a, 1);
	else if (b < c && c < a)
		ra(stack_a, 1);
	else if (a < c && c < b)
	{
		sa(stack_a, 1);
		ra(stack_a, 1);
	}
	else if (b < a && c < b)
	{
		ra(stack_a, 1);
		sa(stack_a, 1);
	}
}

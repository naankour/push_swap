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
	if(*stack_a == NULL || (*stack_a)->next == NULL || (*stack_a)->next->next == NULL)
		return ;
	if((*stack_a)->value < (*stack_a)->next->value && (*stack_a)->next->value < (*stack_a)->next->next->value)
		return ;
	if((*stack_a)->value > (*stack_a)->next->value && (*stack_a)->next->next->value)
		swap_sa(stack_a, 1);
		rotate_ra(stack_a, 1);
}
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

#include "push_swap.h"

void	algo_5(t_list **stack_a)
{
	t_list	*current;
	current = *stack_a;

	while(current != NULL && current->next != NULL)
	{
		if(current->value > current->next->value)
		{
				swap_a(stack_a, 1);
		}
		else
			current = current->next;
	}
}
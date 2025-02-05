/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_n_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naankour <naankour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:24:59 by naankour          #+#    #+#             */
/*   Updated: 2025/02/05 15:24:59 by naankour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_small_to_b(t_list **stack_a, t_list **stack_b, int median)
{
	int	size;
	int	*arr;
	int	i;
	int	count;

	size = ft_lstsize(*stack_a);
	arr = stack_to_arr(*stack_a, size);
	if (!arr)
		return ;
	bubble_sort(arr, size);
	median = find_median(arr, size);
	free(arr);
	i = 0;
	count = 0;
	while (i < size)
	{
		if ((*stack_a)->value < median)
		{
			pb(stack_a, stack_b, 1);
			count++;
		}
		else
			ra(stack_a, 1);
		i++;
	}
}

void	push_chunk_to_b(t_list **stack_a, t_list **stack_b, int *limits,
int chunk_count)
{
	int	i;
	int	j;
	int	size;

	size = ft_lstsize(*stack_a);
	i = 0;
	while (i < chunk_count)
	{
		j = 0;
		while (j < size)
		{
			if ((*stack_a) && (*stack_a)->value <= limits[i])
			{
				pb(stack_a, stack_b, 1);
				if ((*stack_b)->value <= limits[i] - (limits[i] / 6))
					rb(stack_b, 1);
			}
			else
				ra(stack_a, 1);
			j++;
		}
		i++;
	}
}

void	find_chunk_lim(t_list **stack_a, t_list **stack_b, int chunk_count)
{
	int	i;
	int	size;
	int	*arr;
	int	*limits;

	size = ft_lstsize(*stack_a);
	arr = stack_to_arr(*stack_a, size);
	if (!arr)
		return ;
	limits = malloc(sizeof(int) * chunk_count);
	if (!limits)
	{
		free (arr);
		return ;
	}
	bubble_sort(arr, size);
	i = 0;
	while (i < chunk_count)
	{
		limits[i] = arr[(size / chunk_count) * (i + 1)];
		i++;
	}
	free (arr);
	push_chunk_to_b(stack_a, stack_b, limits, chunk_count);
	free (limits);
}

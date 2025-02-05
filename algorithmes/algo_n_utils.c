/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_n_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naankour <naankour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:15:20 by naankour          #+#    #+#             */
/*   Updated: 2025/02/05 15:15:20 by naankour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*stack_to_arr(t_list *stack_a, int size)
{
	int		i;
	int		*arr;
	t_list	*temp;

	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	i = 0;
	temp = stack_a;
	while (i < size)
	{
		arr[i] = temp->value;
		temp = temp->next;
		i++;
	}
	return (arr);
}

void	bubble_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < (size - 1))
	{
		j = 0;
		while (j < (size - 1 - i))
		{
			if (arr[j] > arr [j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr [j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

int	find_median(int	*arr, int size)
{
	return (arr[size / 2]);
}

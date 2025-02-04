/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_n.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naankour <naankour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:04:01 by naankour          #+#    #+#             */
/*   Updated: 2025/02/04 11:45:54 by naankour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//mettre liste dans arr
static int	*stack_to_arr(t_list *stack_a, int size)
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

// trier arr pour trouver mediane
static void	bubble_sort(int *arr, int size)
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

// // trouver la mediane
static int	find_median(int	*arr, int size)
{
	return (arr[size / 2]);
}

// pousser la moitié avec les plus petits int dans stack_b
static void	push_small_to_b(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	*arr;
	int	median;
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

static void	push_chunks_to_b(t_list **stack_a, t_list **stack_b, int chunk_count)
{
	int		*arr;
	int		size;
	int		limits[chunk_count];
	int		i, j;

	size = ft_lstsize(*stack_a);
	arr = stack_to_arr(*stack_a, size);
	if (!arr)
		return;
	bubble_sort(arr, size);
	i = 0;
	while(i < chunk_count)
	{
		limits[i] = arr[(size / chunk_count) * (i + 1)];
		i++;
	}
	free(arr);

	// Pousser les éléments vers stack_b par chunks
	i = 0;
	while (i < chunk_count)
	{
		j = 0;
		while (j < size)
		{
			if ((*stack_a) && (*stack_a)->value <= limits[i])
			{
				pb(stack_a, stack_b, 1); // Pousser dans stack_b
				if ((*stack_b)->value < limits[i] / 2) // Optimisation
					rb(stack_b, 1); // Faire tourner stack_b pour équilibrer
			}
			else
				ra(stack_a, 1); // Tourner stack_a pour avancer
			j++;
		}
		i++;
	}
}

// chercher le plus grand dans stack_b
static int	search_max(t_list *stack)
{
	int		i;
	int		max;
	int		position;
	t_list	*temp;

	if (stack == NULL)
		return (-1);
	i = 0;
	temp = stack;
	max = temp->value;
	position = 0;
	while (temp != NULL)
	{
		if (temp->value > max)
		{
			max = temp->value;
			position = i;
		}
		temp = temp->next;
		i++;
	}
	return (position);
}

// apres avoir trouver la position duplus grand dans stack_b,
// on le met en tete de liste

void	move_largest_to_top(t_list **stack_b)
{
	int		i;
	int		size;
	int		max_value;
	int		max_position;
	t_list	*temp;

	i = 0;
	size = ft_lstsize(*stack_b);
	temp = NULL;
	temp = *stack_b;
	max_value = temp->value;
	max_position = 0;
	while (temp)
	{
		if (temp->value > max_value)
		{
			max_value = temp->value;
			max_position = i;
		}
		temp = temp->next;
		i++;
	}

	if (max_position < size / 2)
	{
		while (max_position > 0)
		{
			rb(stack_b, 1);
			max_position--;
		}
	}
	else
	{
		while (max_position < size)
		{
			rrb(stack_b, 1);
			max_position++;
		}
	}
}

void	sort_stack_b(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_b);
	while (*stack_b)
	{
		search_max(*stack_b);
		move_largest_to_top(stack_b);
		pa(stack_a, stack_b, 1);
	}
}

void	algo_n(t_list **stack_a, t_list **stack_b)
{
	if (!stack_a || !(*stack_a))
		return ;
	int	size;
	size = ft_lstsize(*stack_a);

	if (size <= 100)
		while (ft_lstsize(*stack_a) > 5)
			push_small_to_b(stack_a, stack_b);
	else
		while (ft_lstsize(*stack_a) > 5)
			push_chunks_to_b(stack_a, stack_b, 5);
	algo_5(stack_a, stack_b);
	sort_stack_b(stack_a, stack_b);
}

// garder la mediane dans le cas de 100 elements ou moins
// couper em 5 blocs dans le cas de 500 elements dans un premier temps ? check si ca trie correctement ?
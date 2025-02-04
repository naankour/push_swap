/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_n.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naankour <naankour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:04:01 by naankour          #+#    #+#             */
/*   Updated: 2025/02/04 16:09:01 by naankour         ###   ########.fr       */
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
static void	push_small_to_b(t_list **stack_a, t_list **stack_b, int median)
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
				if ((*stack_b)->value <= limits[i] - (limits[i] / 4))
				rb(stack_b, 1);
			}
			else
				ra(stack_a, 1);
			j++;
		}
		i++;
	}
}

// determiner limite des chunks
static void	find_chunk_lim(t_list **stack_a, t_list **stack_b, int chunk_count)
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
static void	rotation_opti(t_list **stack_b, int max_position, int size)
{
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

static void	move_largest_to_top(t_list **stack_b)
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
	rotation_opti(stack_b, max_position, size);
}

static void	sort_stack_b(t_list **stack_a, t_list **stack_b)
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
	int	size;
	int	median;

	if (!stack_a || !(*stack_a))
		return ;
	size = ft_lstsize(*stack_a);
	median = 0;
	if (size <= 100)
		while (ft_lstsize(*stack_a) > 5)
			push_small_to_b(stack_a, stack_b, median);
	else
		while (ft_lstsize(*stack_a) > 5)
			find_chunk_lim(stack_a, stack_b, 5);
	algo_5(stack_a, stack_b);
	sort_stack_b(stack_a, stack_b);
}

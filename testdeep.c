#include "push_swap.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

void	print_stack(t_list *a)
{
	while (a)
	{
		printf("%d\n", a->value);
		a = a->next;
	}
}
void	init_stack(t_list **a, char **argv)
{
	int		value;
	t_list	*new_node;

	while (*argv)
	{
		value = atoi(*argv);  // Convertit l'argument en entier
		new_node = ft_lstnew(value);  // Crée un nouveau nœud
		if (!new_node)
		{
			free_stack(*a);
			exit(EXIT_FAILURE);
		}
		ft_lstadd_back(a, new_node);  // Ajoute le nœud à la pile
		argv++;
	}
}
void	free_stack(t_list *a)
{
	t_list	*temp;

	while (a)
	{
		temp = a;
		a = a->next;
		free(temp);
	}
}
/* Convertit la pile en tableau */
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

/* Trie le tableau avec bubble sort */
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
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

/* Trouve la médiane inférieure */
static int	find_median(int *arr, int size)
{
	return (arr[size / 2 - 1]);
}

/* Calcule les rotations nécessaires pour stack_a */
static int	calculate_rotations_a(t_list *a, int value)
{
	int		rotations;
	t_list	*current;
	int		min;
	int		max;

	rotations = 0;
	current = a;
	min = INT_MAX;
	max = INT_MIN;
	while (current)
	{
		if (current->value < min)
			min = current->value;
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	if (value < min || value > max)
	{
		while (a->value != min && ++rotations)
			a = a->next;
	}
	else
	{
		while (!(a->value < value && a->next->value > value) && ++rotations)
			a = a->next;
		rotations++;
	}
	if (rotations > ft_lstsize(a) / 2)
		rotations -= ft_lstsize(a);
	return (rotations);
}

/* Calcule les rotations nécessaires pour stack_b */
static int	calculate_rotations_b(t_list *b, int value)
{
	int		rotations;
	t_list	*current;

	rotations = 0;
	current = b;
	while (current && current->value != value)
	{
		rotations++;
		current = current->next;
	}
	if (rotations > ft_lstsize(b) / 2)
		rotations -= ft_lstsize(b);
	return (rotations);
}

/* Exécute les rotations optimisées */
static void	perform_rotations(t_list **a, t_list **b, int rot_a, int rot_b)
{
	while (rot_a > 0 && rot_b > 0)
	{
    	rr(a, b, 1);
    	rot_a--;
    	rot_b--;
	}
	while (rot_a < 0 && rot_b < 0)
	{
    	rrr(a, b, 1);
    	rot_a++;
    	rot_b++;
	}
	while (rot_a-- > 0)
		ra(a, 1);
	while (rot_a++ < 0)
		rra(a, 1);
	while (rot_b-- > 0)
		rb(b, 1);
	while (rot_b++ < 0)
		rrb(b, 1);
}

/* Ramène les éléments de b vers a de manière optimisée */
void	greedy_push_back_to_a(t_list **a, t_list **b)
{
	t_list	*current;
	int		min_cost;
	int		best_rot[2];

	while (*b)
	{
		current = *b;
		min_cost = INT_MAX;
		while (current)
		{
			int rot_a = calculate_rotations_a(*a, current->value);
			int rot_b = calculate_rotations_b(*b, current->value);
			int total = abs(rot_a) + abs(rot_b);

			if (total < min_cost)
			{
				min_cost = total;
				best_rot[0] = rot_a;
				best_rot[1] = rot_b;
			}
			current = current->next;
		}
		perform_rotations(a, b, best_rot[0], best_rot[1]);
		pa(a, b, 1);
	}
}

/* Algorithme principal */
void	algo_n(t_list **a, t_list **b)
{
	if (!a || !*a)
		return;
	push_small_to_b(a, b);
	greedy_push_back_to_a(a, b);
}

/* Fonction main pour exécuter l'algorithme */
int main(int argc, char **argv)
{
	t_list *a = NULL;
	t_list *b = NULL;

	if (argc < 2)
		return (1);
	init_stack(&a, argv + 1);
	algo_n(&a, &b);
	print_stack(a);
	free_stack(a);
	return (0);
}

#include "../push_swap.h"

//mettre liste dans arr
static int	*stack_to_arr(t_list *stack_a, int size)
{
	int	i;
	int	*arr;
	t_list	*temp;

	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	i = 0;
	temp = stack_a;
	while(i < size)
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
	while(i < (size - 1))
	{
		j = 0;
		while(j < (size - 1 - i))
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

// trouver la mediane
static int	find_median(int	*arr, int size)
{
	if (size % 2 != 0)
	{
		return (arr[size / 2]);
	}
	else
		return ((arr[(size / 2) - 1] + arr[size / 2]) / 2);
}

// pousser la moitie avec les plus petits int dans stack_b
static void	push_small_to_b(t_list **stack_a, t_list **stack_b)
{
	int		*arr;
	int		size;
	int		median;

	while (ft_lstsize(*stack_a) > 5) // On arrête quand il reste 5 éléments
	{
		size = ft_lstsize(*stack_a);
		arr = stack_to_arr(*stack_a, size);
		if (!arr)
			return;
		bubble_sort(arr, size);
		median = find_median(arr, size);
		free(arr);

		int i = 0;
		int initial_size = size; // On stocke la taille de départ pour éviter les erreurs

		while (i < initial_size && ft_lstsize(*stack_a) > 5)
		{
			if ((*stack_a)->value < median)
				pb(stack_a, stack_b, 1); // On pousse les plus petits vers stack_b
			else
				ra(stack_a, 1); // On fait tourner stack_a pour ne pas perdre les autres valeurs
			i++;
		}
	}
}

void	algo_n(t_list **stack_a,t_list **stack_b)
{
	if(!stack_a || !(*stack_a))
		return;
	push_small_to_b(stack_a, stack_b);
	algo_5(stack_a, stack_b);
}
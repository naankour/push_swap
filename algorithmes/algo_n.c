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

static void	push_small_to_b(t_list ** stack_a, t_list **stack_b)
{
	int i;
	int	size;
	int median;
	int count;

	size = ft_lstsize(*stack_a);
	median = find_median(*stack_a, size);
	i = 0;
	count = 0;
	while(i < size)
	{
		if((*stack_a)->value < median)
		{
		pb(stack_a, stack_b, 1);
		count++;
		}
		else
			ra(stack_a, 1);
		i++;
	}
}

void	algo_n(t_list **stack_a,t_list **stack_b)
{
	int	*arr;
	int	size;
	int	median;

	size = ft_lstsize(*stack_a);
	arr = stack_to_arr(*stack_a, size);
	if(!arr)
		return (NULL);
	bubble_sort(arr, size);
	median = find_median(arr, size);
	free(arr);
	push_small_to_b(stack_a, stack_b);
}































// int main()
// {
// 	int arr[] = {18, 19, 20, 21, 22, 23};
// 	int size = sizeof(arr) / sizeof(arr[0]);

// 	printf("Médiane : %d\n", find_median(arr, size));
// 	return 0;
// }

// t_list	*ft_create_node(int value)
// {
// 	t_list	*node;
// 	node = malloc(sizeof(t_list));
// 	if (!node)
// 		return (NULL);
// 	node->value = value;
// 	node->next = NULL;
// 	return (node);
// }

// void	free_list(t_list *head)
// {
// 	t_list	*temp;
// 	while (head != NULL)
// 	{
// 		temp = head;
// 		head = head->next;
// 		free(temp);
// 	}
// }
// int main()
// {
// 	t_list  *stack_a = ft_create_node(5);
// 	stack_a->next = ft_create_node(4);
// 	stack_a->next->next = ft_create_node(3);
// 	stack_a->next->next->next = ft_create_node(2);

// 	int size = 4;

// 	int *arr = stack_to_arr(stack_a, size);
// 	if (!arr)
// 	{
// 		printf("Error: Memory allocation failed\n");
// 		free_list(stack_a);
// 		return (1);
// 	}

// 	printf("Array contents:\n");

// 	int i = 0;
// 	while(i < size)
// 	{
// 		printf("%d ", arr[i]);
// 		i++;
// 	}
// 	printf("\n");
// 	bubble_sort(arr, size);
// 	int median = find_median(arr, size);
// 	printf("Après le tri : ");
//     for(int i = 0; i < size; i++)
// 		printf("%d", arr[i]);
// 		printf("\n");
// 	printf("%d\n", median );

// 	free(arr);
// 	free_list(stack_a);
// 	return (0);
// }


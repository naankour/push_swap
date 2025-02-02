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
	int	*arr;

	size = ft_lstsize(*stack_a);
	arr = stack_to_arr(*stack_a, size);
	if (!arr)
		return;
	bubble_sort(arr, size);
	median = find_median(arr, size);
	free(arr);
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
//algo_3 pour trier dans l ordre decroissant
void	algo_3_b(t_list **stack_b)
{
	int	A = (*stack_b)->value;
	int	B = (*stack_b)->next->value;
	int	C = (*stack_b)->next->next->value;

	if (*stack_b == NULL || (*stack_b)->next == NULL || (*stack_b)->next->next == NULL)
		return ;
	if (A < B && B < C)
		return ;
	if (A < C && C < B)
		sb(stack_b, 1);
	else if (B < A && A < C)
		rb(stack_b, 1);
	else if (C < A && A < B)
		rrb(stack_b, 1);
	else if (B < C && C < A)
	{
		sb(stack_b, 1);
		rb(stack_b, 1);
	}
	else if (C < B && B < A)
	{
		rb(stack_b, 1);
		sb(stack_b, 1);
	}
}
// algo_2 pour trier dans l ordre decroissant
void	algo_2_b(t_list **stack_b)
{
	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	if((*stack_b)->value < (*stack_b)->next->value)
		sb(stack_b, 1);
}
// algo_5 pour trier dans l ordre decroissant

static int search_max(t_list *stack)
{
	if (stack == NULL)
		return -1;
	int i = 0;
	int max = stack->value;
	int position = 0;
	t_list *temp = stack;

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
	return position;
}

static void push_max_to_a(t_list **stack_a, t_list **stack_b)
{
	int max_position = search_max(*stack_b);
	int size = ft_lstsize(*stack_b);

	if (max_position <= (size / 2))
		while (max_position > 0)
		{
			rb(stack_b, 1);
			max_position--;
		}
	else
	{
		int moves = size - max_position;
		while (moves > 0)
		{
			rrb(stack_b, 1);
			moves--;
		}
	}

	pa(stack_a, stack_b, 1);
}

void algo_5_b(t_list **stack_a, t_list **stack_b)
{
	push_max_to_a(stack_a, stack_b);
	push_max_to_a(stack_a, stack_b);

	if (ft_lstsize(*stack_b) == 3)
		algo_3_b(stack_b);
	else if (ft_lstsize(*stack_b) == 2)
		algo_2_b(stack_b);

	pb(stack_a, stack_b, 1);
	pb(stack_a, stack_b, 1);
}

void	sort_stack_b(t_list **stack_a, t_list **stack_b)
{
	int size;

	size = ft_lstsize(*stack_b);
	if(size == 2)
		algo_2_b(stack_b);
	if (size == 3)
		algo_3_b(stack_b);
	else if (size == 5)
		algo_5_b(stack_a, stack_b);
	// else
	// {
	// 	while (*stack_b)
	// 	{
	// 		move_largest_to_top(stack_b);
	// 		pa(stack_a, stack_b, 1);
	// 	}
	// }
}
void	algo_n(t_list **stack_a,t_list **stack_b)
{
	if(!stack_a || !(*stack_a))
		return;
	while(ft_lstsize(*stack_a) > 5)
	{
		push_small_to_b(stack_a, stack_b);
	}
	algo_5(stack_a, stack_b);
	sort_stack_b(stack_a, stack_b);
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


#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

void	algo_3(t_list **stack_a)
{
	int	A = (*stack_a)->value;
	int	B = (*stack_a)->next->value;
	int	C = (*stack_a)->next->next->value;

	if(*stack_a == NULL || (*stack_a)->next == NULL || (*stack_a)->next->next == NULL)
		return ;
	if(A < B && B < C)
		return ;
	if(A < C && B < A)
		swap_a(stack_a, 1);
	else if(A < B && C < A)
		reverse_rotate_ra(stack_a, 1);
	else if (B < C && C < A)
		rotate_ra(stack_a, 1);
	else if(A < C && C < B)
	{
		swap_a(stack_a, 1);
		rotate_ra(stack_a, 1);
	}
	else if (B < A && C < B)
	{
		rotate_ra(stack_a, 1);
		swap_a(stack_a, 1);
	}
}
void	rotate_ra(t_list **stack_a, int print)
{
	t_list	*temp;
	t_list	*last;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	last = *stack_a;
	while (last->next != NULL)
		last = last->next;
	last->next = temp;
	temp->next = NULL;
	if (print)
		write(1, "ra\n", 3);
}
void	reverse_rotate_ra(t_list **stack_a, int print)
{
	t_list	*cur;
	t_list	*prev;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	cur = *stack_a;
	prev = NULL;
	while (cur->next != NULL)
	{
		prev = cur;
		cur = cur->next;
	}
	cur->next = *stack_a;
	prev->next = NULL;
	*stack_a = cur;
	if (print)
		write(1, "rra\n", 4);
}
void	swap_a(t_list **stack_a, int print)
{
	t_list	*temp;

	if (*stack_a != NULL && (*stack_a)->next != NULL)
	{
		temp = (*stack_a)->next;
		(*stack_a)->next = temp->next;
		temp->next = *stack_a;
		*stack_a = temp;
		if (print)
			write(1, "sa\n", 3);
	}
}

// Fonction utilitaire pour créer un nouveau nœud de la pile
t_list	*create_node(int value)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}

// Fonction utilitaire pour ajouter un élément à la fin de la pile
void	add_to_stack(t_list **stack, int value)
{
	t_list	*new_node;
	t_list	*current;

	new_node = create_node(value);
	if (!*stack)
	{
		*stack = new_node;
		return ;
	}
	current = *stack;
	while (current->next)
		current = current->next;
	current->next = new_node;
}

// Fonction utilitaire pour imprimer la pile
void	print_stack(t_list *stack)
{
	while (stack)
	{
		printf("%d ", stack->value);
		stack = stack->next;
	}
	printf("\n");
}

// Main pour tester algo_3
int	main(void)
{
	t_list	*stack_a = NULL;

	// Ajouter des éléments à la pile (ordre initial : 3, 1, 2)
	add_to_stack(&stack_a, 3);
	add_to_stack(&stack_a, 2);
	add_to_stack(&stack_a, 1);

	// Afficher la pile avant tri
	printf("Pile avant tri : ");
	print_stack(stack_a);

	// Appliquer l'algorithme pour trier 3 éléments
	algo_3(&stack_a);

	// Afficher la pile après tri
	printf("Pile après tri : ");
	print_stack(stack_a);

	// Libérer la mémoire (facultatif ici mais recommandé)
	t_list	*temp;
	while (stack_a)
	{
		temp = stack_a;
		stack_a = stack_a->next;
		free(temp);
	}
	return (0);
}

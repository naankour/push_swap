#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Définition de la structure t_list
typedef struct s_list
{
	int data;
	struct s_list *next;
} t_list;

// Fonction pour ajouter un élément en tête de liste
t_list *add_to_list(t_list *head, int value)
{
	t_list *new_node = malloc(sizeof(t_list));
	if (!new_node)
		return NULL;

	new_node->data = value;
	new_node->next = head;
	return new_node;
}

// Fonction pour afficher une liste
void print_list(t_list *head)
{
	while (head)
	{
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}

// Fonction pour libérer la mémoire
void free_list(t_list *head)
{
	t_list *temp;
	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

// Fonction reverse_rotate_rb
void reverse_rotate_rb(t_list **stack_b, int print)
{
	t_list  *cur;
	t_list  *prev;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return;

	cur = *stack_b;
	prev = NULL;

	while (cur->next != NULL)
	{
		prev = cur;
		cur = cur->next;
	}

	cur->next = *stack_b;  // Le dernier élément pointe vers le sommet
	prev->next = NULL;     // Déconnecter l'avant-dernier élément
	*stack_b = cur;        // Le dernier élément devient le nouveau sommet

	if (print)
		write(1, "rrb\n", 4);
}

// Fonction principale
int main(void)
{
	t_list *stack_b = NULL;

	// Ajouter des éléments à la pile (5 -> 4 -> 3 -> 2 -> 1)
	stack_b = add_to_list(stack_b, 1);
	stack_b = add_to_list(stack_b, 2);
	stack_b = add_to_list(stack_b, 3);
	stack_b = add_to_list(stack_b, 4);
	stack_b = add_to_list(stack_b, 5);

	// Afficher la pile avant l'opération
	printf("Pile avant rrb : ");
	print_list(stack_b);

	// Appliquer la rotation inversée
	reverse_rotate_rb(&stack_b, 1);

	// Afficher la pile après l'opération
	printf("Pile après rrb : ");
	print_list(stack_b);

	// Libérer la mémoire
	free_list(stack_b);

	return 0;
}
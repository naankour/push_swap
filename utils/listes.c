/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naankour <naankour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:27:51 by naankour          #+#    #+#             */
/*   Updated: 2025/02/05 11:29:04 by naankour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*ft_create_node(int value)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}

void	ft_addnode_back(t_list **head, t_list *new)
{
	t_list	*current;

	if (!head || !new)
		return ;
	if (*head == NULL)
		*head = new;
	else
	{
		current = *head;
		while (current->next != NULL)
			current = current->next;
		current->next = new;
	}
}

void	print_list(t_list *head)
{
	t_list	*current;

	current = head;
	while (current != NULL)
	{
		printf("%d\n", current->value);
		current = current->next;
	}
}

void	free_list(t_list *head)
{
	t_list	*temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

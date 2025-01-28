/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naankour <naankour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 09:29:24 by naankour          #+#    #+#             */
/*   Updated: 2025/01/28 13:48:23 by naankour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	algo_5(t_list **stack_a)
{
	t_list	*current;
	current = *stack_a;

	while(current != NULL && current->next != NULL)
	{
		if(current->value > current->next->value)
		{
				swap_a(stack_a, 1);
		}
		else
			current = current->next;
	}
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if (c == '\0')
	{
		return ((char *)&s[i]);
	}
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*new;
	unsigned int	i;

	if (start >= ft_strlen(s))
		len = 0;
	else if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	new = malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (start + i < ft_strlen(s) && i < len)
	{
		new[i] = s[start + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

static size_t	ft_count_words(const char *s, char c)
{
	size_t	i;
	size_t	word;

	i = 0;
	word = 0;
	while (s[i] != '\0')
	{
		if ((s[i] != c) && ((s[i + 1] == c) || (s[i + 1] == '\0')))
		{
			word++;
		}
		i++;
	}
	return (word);
}

static	size_t	ft_word_len(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (s[count] != c && s[count] != '\0')
	{
		count++;
	}
	return (count);
}

char	**ft_split(const char *s, char c)
{
	char		**arr;
	size_t		i;
	size_t		length;
	size_t		index;

	arr = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!arr)
		return (NULL);
	i = 0;
	index = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			length = ft_word_len(&s[i], c);
			arr[index] = ft_substr(s, i, length);
			index++;
			i = i + length;
		}
	}
	arr[index] = NULL;
	return (arr);
}

int	ft_atoi(const char *str)
{
	size_t		i;
	int			sign;
	long long	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
		if (result > INT_MAX)
			return (INT_MIN);
	}
	result *= sign;
	if (result < INT_MIN || result > INT_MAX)
		return (INT_MIN);
	return ((int)result);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

int	ft_is_valid_nb(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return(1);
}

int	ft_check_double(t_list *head, int num)
{
		t_list *current;
		current = head;
		while (current != NULL)
		{
			if (current->value == num)
				return (1);
			current = current->next;
		}
		return (0);
}
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
	t_list *current;

	if(!head || !new)
		return;
	if(*head == NULL)
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
		current= current->next;
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
int	ft_error(char **tab, t_list *head, int i, int num)
{
	if (!ft_is_valid_nb(tab[i]))
	{
		printf("Error\n");
		return (1);
	}
	num = ft_atoi(tab[i]);
	if (num == INT_MIN)
	{
		printf("Error\n");
		return (1);
	}
	if (ft_check_double(head, num))
	{
		printf("Error\n");
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;
	int	num;
	char	**tab;
	t_list	*head;
	t_list	*stack_a = NULL;

	if (argc == 2 && ft_strchr(argv[1], ' ') != NULL)
		tab = ft_split(argv[1], ' ');
	else
		tab = &argv[1];
	i = 0;
	head = NULL;
	while (tab[i] != NULL)
	{
		if (ft_error(tab, head, i, num))
		{
			free_list(head);
			return (1);
		}
		num = ft_atoi(tab[i]);
		ft_addnode_back(&head, ft_create_node(num));
		i++;
	}
	stack_a = head;
	if(stack_a)
		algo_5(&stack_a);
	print_list(stack_a);
	free_list(stack_a);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naankour <naankour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 09:29:24 by naankour          #+#    #+#             */
/*   Updated: 2025/01/24 14:24:58 by naankour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>

typedef struct s_list
{
	int				value;
	struct s_list	*next;
}	t_list;

void	algo_2(t_list **stack_a);
void	algo_3(t_list **stack_a);
void	algo_5(t_list **stack_a, t_list **stack_b);

void	pa(t_list **stack_a, t_list **stack_b, int print);
void	pb(t_list **stack_a, t_list **stack_b, int print);
void	rra(t_list **stack_a, int print);
void	rrb(t_list **stack_b, int print);
void	rrr(t_list **stack_a, t_list **stack_b, int print);
void	ra(t_list **stack_a, int print);
void	rb(t_list **stack_b, int print);
void	rr(t_list **stack_a, t_list **stack_b, int print);
void	sa(t_list **stack_a, int print);
void	sb(t_list **stack_b, int print);
void	ss(t_list **stack_a, t_list **stack_b, int print);

int	ft_error(char **tab, t_list *head, int i, int num);
char	**ft_split(const char *s, char c);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);

t_list	*ft_create_node(int value);
void	ft_addnode_back(t_list **head, t_list *new);
void	print_list(t_list *head);
void	free_list(t_list *head);
int	ft_atoi(const char *str);

int ft_lstsize(t_list *lst);
void    greedy_push_back_to_a(t_list **a, t_list **b);
void	push_chunks_to_b(t_list **a, t_list **b, int size);
void algo_n(t_list **a, t_list **b);



char	**ft_split(const char *s, char c);
#endif

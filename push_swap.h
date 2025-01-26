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

void	swap_a(t_list **stack_a, int print);
void	swap_b(t_list **stack_b, int print);
void	swap_ss(t_list **stack_a, t_list **stack_b);
void	rotate_ra(t_list **stack_a, int print);
void	rotate_rb(t_list **stack_b, int print);
void	rotate_rr(t_list **stack_a, t_list **stack_b);
void	reverse_rotate_ra(t_list **stack_a, int print);
void	reverse_rotate_rb(t_list **stack_b, int print);
void	reverse_rotate_rr(t_list **stack_a, t_list **stack_b);
void	push_a(t_list **stack_a, t_list **stack_b, int print);
void	push_b(t_list **stack_a, t_list **stack_b, int print);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naankour <naankour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 09:29:24 by naankour          #+#    #+#             */
/*   Updated: 2024/12/23 12:11:18 by naankour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

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
		if(result > INT_MAX)
			return (INT_MIN);
	}
	result *= sign;
	if(result < INT_MIN || result > INT_MAX)
		return (INT_MIN);
	return ((int)result);
}

//check if double

int	ft_check_double(int *arr,int index, int num)
{
		int	i;

		i = 0;
		while(i < index)
		{
			if(arr[i] == num)
				return(1);
			i++;
		}
		return (0);
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
	if(str[i] == '-' || str[i] == '+')
		i++;
	if(str[i] == '\0')
		return(0);
	while(str[i] != '\0')
	{
		if(!ft_isdigit(str[i]))
			return(0);
		i++;
	}
	return(1);
}

int	main(int argc, char **argv)
{
	int	i;
	int	num;
	int	*arr;
	int	index;

	if (argc < 2)
	{
		printf("Error\n");
		return(1);
	}
	if (argc > 1)
	{
		arr = malloc(sizeof(int) * (argc -1));
		if(!arr)
			return (1);
		i = 1;
		index = 0;
		while(i < argc)
		{
			if(!ft_is_valid_nb(argv[i]))
			{
				printf("Error\n");
				free(arr);
				return(1);
			}
			num = ft_atoi(argv[i]);
			if(num == INT_MIN)
			{
				printf("Error\n");
				free (arr);
				return (1);
			}
			if(ft_check_double(arr, index, num))
			{
				printf("Error\n");
				free(arr);
				return (1);
			}
			arr[index++] = num;
			i++;
		}
		int j = 0;
		while(j < index)
		{
			printf("Argument %d : %d\n", j + 1, arr[j]);
			j++;
		}
		free (arr);
		return (0);
	}
}
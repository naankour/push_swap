#include "../push_swap.h"

static	int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

static	int	ft_is_valid_nb(char *str)
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

static	int	ft_check_double(t_list *head, int num)
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
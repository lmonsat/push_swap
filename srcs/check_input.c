/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonsat <lmonsat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 03:09:36 by lmonsat           #+#    #+#             */
/*   Updated: 2024/10/28 01:51:22 by lmonsat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_digit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_int(const char *str, struct s_stacks *stack)
{
	stack->is_string_numbers = 0;
	if (*str == '\0')
		return (0);
	if (*str == '+' || *str == '-')
		str++;
	if (!*str)
		return (0);
	while (*str)
	{
		while (*str == ' ')
		{
			stack->is_string_numbers = 1;
			str++;
		}
		/*if (*str == '+' || *str == '-')
			str++;*/
		if (!is_digit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	is_valid_int(char *str)
{
	int		len;
	char	*int_max_str;
	char	*int_min_str;

	len = ft_strlen(str);
	int_max_str = "2147483647";
	int_min_str = "-2147483648";
	if (str[0] == '-')
	{
		if (len > ft_strlen(int_min_str))
			return (0);
		if (len == ft_strlen(int_min_str) && ft_strcmp(str, int_min_str) > 0)
			return (0);
	}
	else
	{
		if (len > ft_strlen(int_max_str))
			return (0);
		if (len == ft_strlen(int_max_str) && ft_strcmp(str, int_max_str) > 0)
			return (0);
	}
	return (1);
}

void	check_numbers(struct s_stacks *value)
{
	int	i;
	int	j;
	int	nbr_i;
	int	nbr_j;

	i = 0;
	while (value->numbers[i])
	{
		if (!is_valid_int(value->numbers[i]))
		{
			write(2, "Error\n", 6);
			free_array(value->numbers);
			exit(EXIT_FAILURE);
		}
		nbr_i = atoi(value->numbers[i]);
		j = i + 1;
		while (value->numbers[j])
		{
			nbr_j = ft_atoi(value->numbers[j]);
			if (nbr_i == nbr_j)
			{
				write(2, "Error\n", 6);
				free_array(value->numbers);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
}

int	string_numbers(char *argv[], struct s_stacks *stack, int n, int i)
{
	char	**tmp_ptr;

	if (ft_strchr(argv[n], ' '))
	{
		stack->split_numbers = ft_split(argv[n], ' ');
		tmp_ptr = stack->split_numbers;
		while (*stack->split_numbers)
		{
			stack->numbers[i] = ft_strdup(*stack->split_numbers);
			stack->split_numbers++;
			i++;
		}
		free_array(tmp_ptr);
	}
	return (i);
}

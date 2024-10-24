/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonsat <lmonsat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 00:40:10 by lmonsat           #+#    #+#             */
/*   Updated: 2024/10/24 21:14:15 by lmonsat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void alloc_array(struct s_stacks *value, int size)
{
	int i;

	i = 0;
	value->numbers = malloc(size * sizeof(char *));
	if (value->numbers == NULL)
	{
		ft_printf("memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	while (i < size)
	{
		value->numbers[i] = NULL;
		i++;
	}
	/*i = 0;
	value->split_numbers = malloc(1500 * sizeof(char *));
	if (value->split_numbers == NULL)
	{
		ft_printf("memory allocation failed\n");
		exit(EXIT_FAILURE);
	}

	while (i < 1500)
	{
		value->split_numbers[i] = NULL;
		i++;
	}*/
}

int is_sorted(struct s_stacks **head)
{
	struct s_stacks *current;

	current = *head;
	if (*head && (*head)->next)
	{
		while (current->next)
		{
			if (current->data > current->next->data)
			{
				return (0);
			}
			current = current->next;
		}
	}
	return (1);
}

int max_in_stack(struct s_stacks **head)
{
	struct s_stacks *current;
	struct s_stacks *max;

	current = *head;
	max = *head;
	while (current->next)
	{
		if (current->next->data > max->data)
		{
			max = current->next;
		}
		current = current->next;
	}
	return (max->data);
}

int min_in_stack(struct s_stacks **head)
{
	struct s_stacks *current;
	struct s_stacks *min;

	current = *head;
	min = *head;
	while (current->next)
	{
		if (current->next->data < min->data)
		{
			min = current->next;
		}
		current = current->next;
	}
	return (min->data);
}

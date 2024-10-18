/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonsat <lmonsat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:13:07 by lmonsat           #+#    #+#             */
/*   Updated: 2024/10/11 17:41:53 by lmonsat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void free_stack(struct s_stacks *head)
{
	struct s_stacks *tmp;
    while (head != NULL) 
	{
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

void free_array(char **array)
{
	int i;

	i = 0;
	if (array != NULL)
	{
		while (array[i] != NULL)
		{
			free(array[i]);
			i++;
		}
		free(array);
	}
}

void free_multiple_arrays(char **array1, char **array2)
{
	free_array(array1);
	free_array(array2);
}
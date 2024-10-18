/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonsat <lmonsat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:15:03 by lmonsat           #+#    #+#             */
/*   Updated: 2024/10/11 19:38:45 by lmonsat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

struct s_stacks *create_node_a(int data)
{
    struct s_stacks *new_node;
	
	new_node = malloc(sizeof(struct s_stacks));
	if (new_node == NULL)
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return (new_node);
}

void insert_head_a(struct s_stacks **head, int new_data)
{
    struct s_stacks *new_node;
	
	new_node = create_node_a(new_data);
    new_node->next = *head;
    if (*head != NULL) 
	{
        (*head)->prev = new_node;
    }
    *head = new_node;
}
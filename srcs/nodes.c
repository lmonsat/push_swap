/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonsat <lmonsat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:15:03 by lmonsat           #+#    #+#             */
/*   Updated: 2024/10/24 17:31:57 by lmonsat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

struct s_stacks *create_node_a(int data)
{
    struct s_stacks *new_node;
	
	new_node = malloc(sizeof(struct s_stacks));
	if (new_node == NULL)
	{
		write(2, "Error\n", 6);
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

struct s_stacks *pop_last(struct s_stacks **head)
{
	struct s_stacks *current;
	struct s_stacks *prev;

	if (*head == NULL)
		return (NULL);

	current = *head;
	if (current->next == NULL)
	{
		*head = NULL;
		return (current);
	}
	while (current->next)
	{
		prev = current;
		current = current->next;
	}
	prev->next = NULL;
	current->prev = NULL;
	return (current);
}

void push_last(struct s_stacks **head, struct s_stacks *last)
{
	struct s_stacks *current;

	if (*head == NULL)
	{
		*head = last;
		last->next = NULL;
		last->prev = NULL;
		return;
	}
	current = *head;
	while (current->next)
	{
		current = current->next;
	}
	current->next = last;
	last->prev = current;
	last->next = NULL;
}
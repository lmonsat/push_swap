/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonsat <lmonsat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:15:03 by lmonsat           #+#    #+#             */
/*   Updated: 2024/10/23 16:43:14 by lmonsat          ###   ########.fr       */
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

struct s_stacks *pop_last(struct s_stacks **head)
{
	struct s_stacks *current;
	struct s_stacks *prev;

	// Si la liste est vide, rien à supprimer
	if (*head == NULL)
		return (NULL);

	current = *head;

	// Si la liste n'a qu'un seul élément
	if (current->next == NULL)
	{
		*head = NULL;  // La liste devient vide
		return (current);
	}

	// Parcourir la liste jusqu'à l'avant-dernier élément
	while (current->next)
	{
		prev = current;
		current = current->next;
	}

	// Supprimer le dernier élément
	prev->next = NULL;
	current->prev = NULL;

	return (current);
}

void push_last(struct s_stacks **head, struct s_stacks *last)
{
	struct s_stacks *current;

	// Si la liste est vide, le nouvel élément devient le premier
	if (*head == NULL)
	{
		*head = last;
		last->next = NULL;
		last->prev = NULL;
		return;
	}

	current = *head;

	// Parcourir jusqu'au dernier élément
	while (current->next)
	{
		current = current->next;
	}

	// Ajouter le nouvel élément à la fin
	current->next = last;
	last->prev = current;  // Mettre à jour le pointeur prev
	last->next = NULL;
}
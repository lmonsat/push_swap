/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonsat <lmonsat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 18:17:36 by lmonsat           #+#    #+#             */
/*   Updated: 2024/10/24 05:21:47 by lmonsat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void sa(struct s_stacks **head, int is_ss)
{
    struct s_stacks *first;
	struct s_stacks *second;

    if (*head && (*head)->next) 
    {
        first = *head;
		second = first->next;

		//ft_printf("test first %d\n", (*head)->data);
		//ft_printf("test second %d\n", (*head)->next->data);
		
		first->next = second->next;
		second->next = first;

		second->prev = NULL;
		first->prev = second;

		if (first->next)
		{
			first->next->prev = first;
		}
		*head = second;

		//ft_printf("test first %d\n", (*head)->data);
		//ft_printf("test second %d\n", (*head)->next->data);
		if (!is_ss)
			ft_printf("sa\n");
    }
}


void sb(struct s_stacks **head, int is_ss)
{
    struct s_stacks *first;
	struct s_stacks *second;

    if (*head && (*head)->next)
    {
        first = *head;
		second = first->next;

		first->next = second->next;
		second->next = first;

		second->prev = NULL;
		first->prev = second;

		if (first->next)
		{
			first->next->prev = first;
		}

		*head = second;
		if (!is_ss)
			ft_printf("sb\n");
    }
}

void ss(struct s_stacks **head_a, struct s_stacks **head_b)
{
	sa(head_a, 1);
	sb(head_b, 1);
	ft_printf("ss\n");
}

void ra(struct s_stacks **head, int is_rr)
{
	struct s_stacks *first;
	struct s_stacks *last;

	if (*head && (*head)->next)
	{
		first = *head;
		last = *head;
		while (last->next)
		{
			last = last->next;
		}
		
		*head = first->next;
		(*head)->prev = NULL;

		last->next = first;
		first->prev = last;
		first->next = NULL;
		if (!is_rr)
			ft_printf("ra\n");                
	}
}

void rb(struct s_stacks **head, int is_rr)
{
	struct s_stacks *first;
	struct s_stacks *last;

	if (*head && (*head)->next)
	{
		first = *head;
		last = *head;
		while (last->next)
		{
			last = last->next;
		}
		
		*head = first->next;
		(*head)->prev = NULL;

		last->next = first;
		first->prev = last;
		first->next = NULL;
		if (!is_rr)
			ft_printf("rb\n");              
	}
}

void rr(struct s_stacks **head_a, struct s_stacks **head_b)
{
	ra(head_a, 1);
	rb(head_b, 1);
	ft_printf("rr\n");
}

void rra(struct s_stacks **head, int is_rrr)
{
    struct s_stacks *last;
    struct s_stacks *second_last;

    if (*head && (*head)->next)
    {
        last = *head;
        second_last = NULL;

        // Se déplacer jusqu'au dernier et avant-dernier élément de la pile
        while (last->next)
        {
            second_last = last;
            last = last->next;
        }

        // Si last ou second_last sont NULL, on ne fait rien
        if (last == NULL || second_last == NULL) 
		{
            ft_printf("Erreur : liste incorrecte (last ou second_last est NULL)\n");
            return;
        }

        // Effectuer la rotation si second_last n'est pas NULL
        second_last->next = NULL;  // L'avant-dernier devient le dernier
        last->next = *head;        // Le dernier pointe vers l'ancienne tête
        if (*head != NULL)
            (*head)->prev = last;  // L'ancienne tête pointe vers le nouveau premier élément
        *head = last;              // Le dernier devient la nouvelle tête
        last->prev = NULL;         // La nouvelle tête n'a pas de précédent

        //ft_printf("Après rotation : nouvelle tête = %d\n", (*head)->data);
		if (!is_rrr)
        	ft_printf("rra\n");
    }
    else
    {
        ft_printf("rra ignorée : pile trop petite ou vide\n");
    }
}

void rrb(struct s_stacks **head, int is_rrr)
{
	struct s_stacks *last;
    struct s_stacks *second_last;

    if (*head && (*head)->next)
    {
        last = *head;
        second_last = NULL;

        // Se déplacer jusqu'au dernier et avant-dernier élément de la pile
        while (last->next)
        {
            second_last = last;
            last = last->next;
        }

        // Si last ou second_last sont NULL, on ne fait rien
        if (last == NULL || second_last == NULL) 
		{
            ft_printf("Erreur : liste incorrecte (last ou second_last est NULL)\n");
            return;
        }

        // Effectuer la rotation si second_last n'est pas NULL
        second_last->next = NULL;  // L'avant-dernier devient le dernier
        last->next = *head;        // Le dernier pointe vers l'ancienne tête
        if (*head != NULL)
            (*head)->prev = last;  // L'ancienne tête pointe vers le nouveau premier élément
        *head = last;              // Le dernier devient la nouvelle tête
        last->prev = NULL;         // La nouvelle tête n'a pas de précédent

        //ft_printf("Après rotation : nouvelle tête = %d\n", (*head)->data);
		if (!is_rrr)
        	ft_printf("rrb\n");
    }
    else
    {
        ft_printf("rrb ignorée : pile trop petite ou vide\n");
    }
}

void rrr(struct s_stacks **head_a, struct s_stacks **head_b)
{
	rra(head_a, 1);
	rrb(head_b, 1);
	ft_printf("rrr\n");
}

void pa(struct s_stacks **head_a, struct s_stacks **head_b)
{
	struct s_stacks *node_to_push;

	if (*head_b == NULL)
		return;

	// Transférer le nœud de head_a vers head_a
	node_to_push = *head_b;
	*head_b = (*head_b)->next;

	// Mettre à jour les pointeurs de head_b
	if (*head_b != NULL)
		(*head_b)->prev = NULL;

	// Insérer le nœud en tête de head_a
	node_to_push->next = *head_a;
	if (*head_a != NULL)
		(*head_a)->prev = node_to_push;

	*head_a = node_to_push;
	node_to_push->prev = NULL;

	ft_printf("pa\n");
}

void pb(struct s_stacks **head_a, struct s_stacks **head_b)
{
	struct s_stacks *node_to_push;

	if (*head_a == NULL)
		return;

	// Transférer le nœud de head_a vers head_b
	node_to_push = *head_a;
	*head_a = (*head_a)->next;

	// Mettre à jour les pointeurs de head_a
	if (*head_a != NULL)
		(*head_a)->prev = NULL;

	// Insérer le nœud en tête de head_b
	node_to_push->next = *head_b;
	if (*head_b != NULL)
		(*head_b)->prev = node_to_push;

	*head_b = node_to_push;
	node_to_push->prev = NULL;

	ft_printf("pb\n");
}

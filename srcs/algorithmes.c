/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithmes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonsat <lmonsat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:06:54 by lmonsat           #+#    #+#             */
/*   Updated: 2024/10/25 15:15:41 by lmonsat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void algo_2(struct s_stacks **head)
{
	if (!is_sorted(head))
	{
		sa(head, 0);
	}
}

void algo_3(struct s_stacks **head)
{
	/*ft_printf("(*head)->data: %d\n", (*head)->data);
	ft_printf("(*head)->next->data: %d\n", (*head)->next->data);
	ft_printf("(*head)->next->next->data: %d\n", (*head)->next->next->data);*/

	int min;
	int max;

	min = min_in_stack(head);
	max = max_in_stack(head);
	/*ft_printf("min in stack: %d\n", min);
	ft_printf("max in stack: %d\n", max);*/
	
	/*ft_printf("(*head)->data: %d\n", (*head)->data);
	ft_printf("(*head)->next->data: %d\n", (*head)->next->data);
	ft_printf("(*head)->next->next->data: %d\n", (*head)->next->next->data);*/
	if (!is_sorted(head))
	{
		if ((*head)->data == max)
			ra(head, 0);
		else if ((*head)->next->data == max)
			rra(head, 0);
		if ((*head)->data > (*head)->next->data)
			sa(head, 0);
	}
}

void algo_4(struct s_stacks **head_a, struct s_stacks **head_b)
{
	int min;
	struct s_stacks *last;
	
	min = min_in_stack(head_a);
	if (!is_sorted(head_a))
	{
		if (min == (*head_a)->next->data)
		{
			ra(head_a, 0);
		}
		else if (min == (*head_a)->next->next->data)
		{
			rra(head_a, 0);
			rra(head_a, 0);
		}
		else if (min == (*head_a)->next->next->next->data)
		{
			rra(head_a, 0);
		}
		pb(head_a, head_b);
		algo_3(head_a);
		pa(head_a, head_b);
	}
}

void algo_5(struct s_stacks **head_a, struct s_stacks **head_b)
{
	int min;
	
	min = min_in_stack(head_a);
	if (!is_sorted(head_a))
	{
		if (min == (*head_a)->next->data)
			ra(head_a, 0);
		else if (min == (*head_a)->next->next->data)
		{
			ra(head_a, 0);
			ra(head_a, 0);
		}
		else if (min == (*head_a)->next->next->next->data)
		{
			rra(head_a, 0);
			rra(head_a, 0);
		}
		else if (min == (*head_a)->next->next->next->next->data)
			rra(head_a, 0);
		pb(head_a, head_b);
		algo_4(head_a, head_b);
		pa(head_a, head_b);
	}
}

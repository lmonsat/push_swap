/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonsat <lmonsat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 00:37:27 by lmonsat           #+#    #+#             */
/*   Updated: 2024/10/23 21:41:54 by lmonsat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void check_input_errors(int argc, char *argv[], struct s_stacks *stack)
{
	int n;
	int i;
	int nb_space;

	i = 0;
	n = 0;
	while (argv[++n])
	{
		if (is_int(argv[n], stack))
		{
			if (!stack->is_string_numbers)
				stack->numbers[i++] = ft_strdup(argv[n]);
		}
		else
		{
			ft_printf("Error\n");
			free_array(stack->numbers);
			exit(EXIT_FAILURE);
		}
		i = string_numbers(argv, stack, n, i);
	}
	i = 0;
	while (stack->numbers[i])
	{
		//ft_printf("numbers : %s\n", stack->numbers[i]);
		i++;
	}
}

void arg_count(int argc)
{
	if (argc < 2)
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
}

void print_stack_a(struct s_stacks *current)
{
    ft_printf("Liste chainé a : ");
    while (current != NULL) 
	{
        ft_printf("%d -> ", current->data);
        current = current->next;
    }
    ft_printf("NULL\n");
}

void print_stack_b(struct s_stacks *current)
{
    ft_printf("Liste chainé b : ");
    while (current != NULL) 
	{
        ft_printf("%d -> ", current->data);
        current = current->next;
    }
    ft_printf("NULL\n");
}

void fill_stack_a(struct s_stacks **head, struct s_stacks *value)
{
	int	i;

	value->numbers_in_stack = 0;
	i = 0;
	while (value->numbers[i])
		i++;
	
	while (i--)
	{
		insert_head_a(head, ft_atoi(value->numbers[i]));
		value->numbers_in_stack++;
	}
}


int stack_size(struct s_stacks *stack)
{
    struct s_stacks *current;
	int size;
	
	if (!stack)
		return (0);
	
	size = 0;
	current = stack;
    while (current)
    {
        size++;
        current = current->next;
    }
    return (size);
}

int find_position(struct s_stacks *stack, struct s_stacks *target)
{
    int position;
    struct s_stacks *current;

	position = 0;
	current = stack;
    while (current)
    {
        if (current == target)
        {
            return (position);
        }
        position++;
        current = current->next;
    }
}

/* Permet d'attribuer a chaque élement d'un stack sa position dans le stack
	ainsi que de vérifier s'il se situe dans la partie haute du stack (above_median)
	ou la partie basse */
void	update_position(struct s_stacks *stack)
{
	int	i;
	int	median;

	if (NULL == stack)
		return ;
	i = 0;
	median = stack_size(stack) / 2;
	while (stack)
	{
		stack->current_position = i;
		if (i <= median)
			stack->above_median = 1;
		else
			stack->above_median = 0;
		stack = stack->next;
		i++;
	}
}

void ra_rotation (struct s_stacks **stack_a, struct s_stacks *node)
{
	while (*stack_a != node)
	{
		if (node->above_median)
		{
			ra(stack_a, 0);
		}
		else
		{
			rra(stack_a, 0);
		}
	}
}

void rb_rotation (struct s_stacks **stack_b, struct s_stacks *node)
{
	while (*stack_b != node)
	{
		if (node->above_median)
		{
			rb(stack_b, 0);
		}
		else
		{
			rrb(stack_b, 0);
		}
	}
}

struct s_stacks *min_node_in_stack(struct s_stacks *stack)
{
	struct s_stacks *current;
	struct s_stacks *min;

	current = stack;
	min = stack;
	while (current->next)
	{
		if (current->next->data < min->data)
		{
			min = current->next;
		}
		current = current->next;
	}
	return (min);
}

struct s_stacks *max_node_in_stack(struct s_stacks *stack)
{
	struct s_stacks *current;
	struct s_stacks *max;

	current = stack;
	max = stack;
	while (current->next)
	{
		if (current->next->data > max->data)
		{
			max = current->next;
		}
		current = current->next;
	}
	return (max);
}

/* Rotate ou reverse rotate la stack_a jusqu'au target_node */
void rotate_stack_a_to_target(struct s_stacks **stack_a, struct s_stacks *target)
{
    int position;
	int reverse_position;
    int size;
	
	position = find_position(*stack_a, target);
	size = stack_size(*stack_a);
    if (position <= size / 2)
    {
        while (position > 0)
        {
            ra(stack_a, 0);
            position--;
        }
    }
    else
    {
        reverse_position = size - position;
        while (reverse_position > 0)
        {
            rra(stack_a, 0);
            reverse_position--;
        }
    }
}

void move_min_to_top(struct s_stacks **stack_a) 
{
    struct s_stacks *min;
	
	min = min_node_in_stack(*stack_a);
    rotate_stack_a_to_target(stack_a, min);
}

/* Rotate ou reverse rorate la stack_a et stack_b en meme temps
	Update les position après */
void rotate_stack_a_and_b(struct s_stacks **stack_a, struct s_stacks **stack_b, struct s_stacks *cheapest_node)
{
	int position_a;
	int position_b;
    int size_a;
	int size_b;
	
	position_a = find_position(*stack_a, (*stack_a)->target_node);
	position_b = find_position(*stack_b, (*stack_b)->target_node);
	size_a = stack_size(*stack_a);
	size_b = stack_size(*stack_b);
	if (position_a <= (size_a / 2) && position_b <= (size_b / 2))
    {
        while (position_a-- > 0 && position_b-- > 0)
            rr(stack_a, stack_b);
    }
    else if (position_a > (size_a / 2) && position_b > (size_b / 2))
    {
        position_a = size_a - position_a;
		position_b = size_b - position_b;
        while (position_a-- > 0 && position_b-- > 0)
            rrr(stack_a, stack_b);
    }
	update_position(*stack_a);
	update_position(*stack_b);
}

/*
 *	Best match is..
 *   | "The Smallest-bigger value" |
 *
 *  if no node is Bigger, best_match is the Smallest node.
 *  TLDR 
 *  With this function every node in b gets its target node in a
*/
void	set_target_node(struct s_stacks *stack_a, struct s_stacks *stack_b)
{
	struct s_stacks *current_a;
	struct s_stacks *target_node;
	long			best_match_index;

	while (stack_b)
	{
		best_match_index = LONG_MAX;
		current_a = stack_a;
		while (current_a)
		{
			if (current_a->data > stack_b->data && current_a->data < best_match_index)
			{
				best_match_index = current_a->data;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (LONG_MAX == best_match_index)
			stack_b->target_node = min_node_in_stack(stack_a);
		else
			stack_b->target_node = target_node;
		stack_b = stack_b->next;
	}
}

/*
 * Set the prices to push the node
 * from b -> a
 * The price checks for the relative positions in the stack
 * for every node, setting the respective price
*/
void	set_cost(struct s_stacks *stack_a, struct s_stacks *stack_b)
{
	int	size_a;
	int	size_b;

	size_a = stack_size(stack_a);
	size_b = stack_size(stack_b);
	while (stack_b)
	{
		stack_b->push_cost = stack_b->current_position;
		if (!(stack_b->above_median))
			stack_b->push_cost = size_b - (stack_b->current_position);
		if (stack_b->target_node->above_median)
			stack_b->push_cost += stack_b->target_node->current_position;
		else
			stack_b->push_cost += size_a - (stack_b->target_node->current_position);
		stack_b = stack_b->next;
	}
}

/* Compare stack_b avec le meilleur coût trouvé jusqu'à présent
	en itérant toute la stack_b puis retourne l'élement ayant
	le cout minimum  */
struct s_stacks *find_cheapest_to_push_a(struct s_stacks *stack_a, struct s_stacks *stack_b) 
{
    long			best_match_value;
	struct s_stacks *best_match_node;
	
	best_match_node = NULL;
	if (stack_b == NULL)
		return (NULL);
	
	best_match_value = LONG_MAX;
	while (stack_b)
	{
		if (stack_b->push_cost < best_match_value)
		{
			best_match_value = stack_b->push_cost;
			best_match_node = stack_b;
		}
		stack_b = stack_b->next;
	}
    return (best_match_node);
}

/* Effectue les rotations necessaire afin de placer le cheapest node
	dans stadck_b vers son target node dans a.

	Effectuer ra_rotation afin d'alligné la position où l'element
	de b doit etre push.

	Effectuer rb_rotation afin de positionner le cheapest node
	en tête de stack_b.
	
	Push vers la stack_a */
void push_cheapest_to_a(struct s_stacks **stack_a, struct s_stacks **stack_b) 
{
    struct s_stacks *cheapest;
	
	cheapest = find_cheapest_to_push_a(*stack_a, *stack_b);
    rotate_stack_a_and_b(stack_a, stack_b, cheapest);
	
	ra_rotation(stack_a, cheapest->target_node);
	rb_rotation(stack_b, cheapest);
    pa(stack_a, stack_b);
}

void rush_b(struct s_stacks **stack_a, struct s_stacks **stack_b) 
{
	int size;
	
	size = stack_size(*stack_a);
    while (size-- > 3) 
	{
        pb(stack_a, stack_b);
    }
}

void rush_a(struct s_stacks **stack_a, struct s_stacks **stack_b) 
{
    while (*stack_b) 
	{
		update_position(*stack_a);
		update_position(*stack_b);
		set_target_node(*stack_a, *stack_b);
		set_cost(*stack_a, *stack_b);
		push_cheapest_to_a(stack_a, stack_b);
    }
}

void algo_plus(struct s_stacks **stack_a, struct s_stacks **stack_b, struct s_stacks *value)
{
	rush_b(stack_a, stack_b);
    algo_3(stack_a);
    rush_a(stack_a, stack_b);
	update_position(*stack_a);
    move_min_to_top(stack_a);
}

void algorithmes(struct s_stacks **head_a, struct s_stacks **head_b, struct s_stacks *value)
{
	if (value->numbers_in_stack == 2)
	{
		algo_2(head_a);
	}
	else if (value->numbers_in_stack == 3)
	{
		algo_3(head_a);
	}
	else if (value->numbers_in_stack == 4)
	{
		algo_4(head_a);
		//algo_plus(head_a, head_b, value);
	}
	else if (value->numbers_in_stack == 5)
	{
		algo_5(head_a);
		//algo_plus(head_a, head_b, value);
	}
	else
	{
		algo_plus(head_a, head_b, value);
	}
}

void check_sorted(struct s_stacks **head)
{
	if (!is_sorted(head))
	{
		ft_printf("not sorted\n");
		return ;
	}
	ft_printf("is sorted\n");
}


int main(int argc, char *argv[])
{
	struct s_stacks stacks;
	struct s_stacks *head_a;
	struct s_stacks *head_b;

	head_a = NULL;
	head_b = NULL;	
	arg_count(argc);
	alloc_array(&stacks);
	check_input_errors(argc, argv, &stacks);
	check_numbers(&stacks);
	fill_stack_a(&head_a, &stacks);
	//print_stack_a(head_a);
	//print_stack_b(head_b);
	//ft_printf("Check stack size : %d\n", stack_size(head_a));
	//check_sorted(&head_a);
	algorithmes(&head_a, &head_b, &stacks);
	check_sorted(&head_a);
	print_stack_a(head_a);
	//print_stack_b(head_b);
	//ft_printf("Check stack size : %d\n", stack_size(head_a));
	free_stack(head_a);
	free_stack(head_b);
	free_array(stacks.numbers);
	return (0);
}

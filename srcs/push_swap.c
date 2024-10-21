/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonsat <lmonsat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 00:37:27 by lmonsat           #+#    #+#             */
/*   Updated: 2024/10/21 02:33:09 by lmonsat          ###   ########.fr       */
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

void push_first(struct s_stacks **head_a, struct s_stacks **head_b)
{
	pb(head_a, head_b);
	pb(head_a, head_b);
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
    return (-1);
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

void rotate_to_position(struct s_stacks **stack_a, int position)
{
    int size;
	int reverse_position;
	
	size = stack_size(*stack_a);
    // Si la position est en première moitié de la pile (on fait des rotations normales)
    if (position <= size / 2)
    {
        // Effectuer des rotations "ra" vers le haut jusqu'à ce que l'élément soit en haut
        while (position > 0)
        {
            ra(stack_a, 0);
            position--;
        }
    }
    // Si la position est dans la seconde moitié de la pile (on fait des rotations inversées)
    else
    {
        reverse_position = size - position;  // Nombre de "rra" nécessaires
        // Effectuer des rotations "rra" vers le bas jusqu'à ce que l'élément soit en haut
        while (reverse_position > 0)
        {
            rra(stack_a, 0);
            reverse_position--;
        }
    }
}


void move_min_to_top(struct s_stacks **stack_a)
{
	/*struct s_stacks *min;
    int position;
	
	min = min_node_in_stack(*stack_a);
	position = find_position(*stack_a, min);
    // Appliquer la rotation seulement si le minimum n'est pas déjà en haut
    if (position > 0) 
    {
        rotate_to_position(stack_a, position);
    }*/
	struct s_stacks *min;
	min = min_node_in_stack(*stack_a);
	if (min->above_median)
		while (*stack_a != min)
			ra(stack_a, 0);
	else
		while (*stack_a != min)
			rra(stack_a, 0);
}

/*void move_min_to_top(struct s_stacks **stack_a) 
{
    struct s_stacks *min = min_node_in_stack(*stack_a);
    rotate_stack_a_to_target(stack_a, min);
}*/

struct s_stacks *find_node(struct s_stacks *stack, int value)
{
    struct s_stacks *current;
	
	current = stack;
    while (current)
    {
        if (current->data == value)
        {
            return (current);
        }
        current = current->next;
    }

    return (NULL);
}

	/*cheapest_node = return_cheapest(*b);
	if (cheapest_node->above_median
		&& cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		reverse_rotate_both(a, b, cheapest_node);
	finish_rotation(b, cheapest_node, 'b');
	finish_rotation(a, cheapest_node->target_node, 'a');
	pa(a, b, false);*/

void rotate_stack_a_to_target(struct s_stacks **stack, struct s_stacks *target)
{
    int position;
	int reverse_position;
    int size;
	
	position = find_position(*stack, target);
	size = stack_size(*stack);
    if (position == -1)
        return;

    // Choisir la rotation la plus rapide
    if (position <= size / 2)
    {
        // Effectuer des rotations vers le haut
        while (position > 0)
        {
            ra(stack, 0);
            position--;
        }
    }
    else
    {
        // Effectuer des rotations vers le bas
        reverse_position = size - position;
		//ft_printf("test crash 0, reverse_position : %d\n", reverse_position);
        while (reverse_position > 0)
        {
			//print_stack_a(*stack);
            rra(stack, 0);
			//print_stack_a(*stack);
            reverse_position--;
			//ft_printf("test crash 1, reverse_position : %d\n", reverse_position);
        }
    }
}

void rotate_stack_b_to_target(struct s_stacks **stack_b, struct s_stacks *target)
{
    int position;
	int reverse_position;
    int size;
	
	position = find_position(*stack_b, target);
	size = stack_size(*stack_b);
    if (position == -1)
        return;

    // Choisir la rotation la plus rapide
    if (position <= size / 2)
    {
        // Effectuer des rotations vers le haut
        while (position > 0)
        {
            rb(stack_b, 0);
            position--;
        }
    }
    else
    {
        // Effectuer des rotations vers le bas
        reverse_position = size - position;
		//ft_printf("test crash 0, reverse_position : %d\n", reverse_position);
        while (reverse_position > 0)
        {
			//print_stack_a(*stack_b);
            rrb(stack_b, 0);
			//print_stack_a(*stack_b);
            reverse_position--;
			//ft_printf("test crash 1, reverse_position : %d\n", reverse_position);
        }
    }
}

void rotate_stack_a_and_b(struct s_stacks **stack_a, struct s_stacks **stack_b, struct s_stacks *target_a, struct s_stacks *target_b)
{
	int position_a;
	int position_b;
	int reverse_position_a;
	int reverse_position_b;
    int size_a;
	int size_b;
	
	position_a = find_position(*stack_a, target_a);
	position_b = find_position(*stack_b, target_b);
	size_a = stack_size(*stack_a);
	size_b = stack_size(*stack_b);

	//struct s_stacks *cheapest_node = find_cheapest_to_push(stack_a, stack_b);

	if (position_a <= (size_a / 2) && position_b <= (size_b / 2))
    {
		//ft_printf("Test position a : %d, Test position b : %d\n", position_a, position_b);
        // Effectuer des rotations vers le haut
        while (position_a > 0 && position_b > 0)
        {
            rr(stack_a, stack_b);
            position_a--;
			position_b--;
        }
    }
    else if (position_a > (size_a / 2) && position_b > (size_b / 2))
    {
        // Effectuer des rotations vers le bas
        reverse_position_a = size_a - position_a;
		reverse_position_b = size_b - position_b;
		//ft_printf("test crash 0, reverse_position : %d\n", reverse_position);
        while (reverse_position_a > 0 && reverse_position_b > 0)
        {
			//print_stack_a(*stack);
            rrr(stack_a, stack_b);
			//print_stack_a(*stack);
            reverse_position_a--;
			reverse_position_b--;
			//ft_printf("test crash 1, reverse_position : %d\n", reverse_position);
        }
    }
	set_current_position(*stack_a);
	set_current_position(*stack_b);
	//rotate_stack_a_to_target(stack_a, target_a);
    //rotate_stack_b_to_target(stack_b, target_b);
}

struct s_stacks *find_target_node_old(struct s_stacks *stack_a, int value)
{
    struct s_stacks *target;
    struct s_stacks *current_a;

	target = NULL;
	current_a = stack_a;
	while (current_a)
	{
		// Trouve l'élément qui est le plus petit élément supérieur à 'value'
		if (current_a->data > value && (!target || current_a->data < target->data))
		{
			target = current_a;
		}
		current_a = current_a->next;
	}

	// Si aucune cible trouvée (le plus grand élément de A), retourne le plus petit élément
	if (!target)
	{
		target = min_node_in_stack(stack_a);
	}
	
    return (target);
}

struct s_stacks *find_target_node(struct s_stacks *stack_a, struct s_stacks *stack_b)
{
	struct s_stacks *current_a;
	struct s_stacks *target_node;
	long target_value;

	// Initialisation du meilleur match
	target_value = LONG_MAX;
	target_node = NULL;

	// Boucle sur la pile a pour trouver le meilleur match
	current_a = stack_a;
	while (current_a)
	{
		// On cherche un noeud dans a dont la valeur est supérieure à celle de b mais la plus proche possible
		if (current_a->data > stack_b->data && current_a->data < target_value)
		{
			target_value = current_a->data;
			target_node = current_a;
		}
		current_a = current_a->next;
	}

	// Si aucun match n'a été trouvé, on retourne le plus petit élément de la pile a
	if (target_value == LONG_MAX)
		return (min_node_in_stack(stack_a));  // Fonction qui retourne le plus petit élément de a

	// Retourne le nœud cible trouvé
	return (target_node);
}

struct s_stacks *find_target_node_in_b(struct s_stacks *stack_a, struct s_stacks *stack_b)
{
	struct s_stacks *current_b;
	struct s_stacks *target_node;
	long target_value;

	// Vérification de stack_a
	if (stack_a == NULL)
		return (min_node_in_stack(stack_b));  // Retourne le plus petit élément si stack_a est vide

	// Initialisation du meilleur match
	target_value = LONG_MAX;
	target_node = NULL;

	// Boucle sur la pile b pour trouver le meilleur match
	current_b = stack_b;
	while (current_b)
	{
		// On cherche un noeud dans b dont la valeur est supérieure à celle de a mais la plus proche possible
		if (current_b->data > stack_a->data && current_b->data < target_value)
		{
			target_value = current_b->data;
			target_node = current_b;
		}
		current_b = current_b->next;
	}

	// Si aucun match n'a été trouvé, on retourne le plus petit élément de la pile b
	if (target_value == LONG_MAX)
		return (min_node_in_stack(stack_b));  // Fonction qui retourne le plus petit élément de b

	// Retourne le nœud cible trouvé
	return (target_node);
}

int calculate_rotation_cost(struct s_stacks *stack, struct s_stacks *target)
{
    int position;
    int size;

	position = find_position(stack, target);
	size = stack_size(stack);
    // Choisir entre ra et rra pour le chemin le plus court
    if (position <= size / 2)
    {
        return (position);
    }
    else
    {
        return (size - position);
    }
}

int calculate_push_cost_old(struct s_stacks *stack_a, struct s_stacks *stack_b, int value) 
{
    struct s_stacks *target_b = find_target_node(stack_b, stack_a);
	//struct s_stacks *target_b = find_target_node_old(stack_b, value);
    int cost_a = calculate_rotation_cost(stack_a, find_node(stack_a, value));
    int cost_b = calculate_rotation_cost(stack_b, target_b);
    
    // Si les rotations peuvent être simultanées (rr ou rrr), on ajuste les coûts
    if ((cost_a <= stack_size(stack_a) / 2 && cost_b <= stack_size(stack_b) / 2) ||
        (cost_a > stack_size(stack_a) / 2 && cost_b > stack_size(stack_b) / 2)) 
		{
        return (cost_a > cost_b) ? cost_a : cost_b;
    	}
    // Sinon, on retourne la somme des coûts individuels
    return (cost_a + cost_b);
}

/*int calculate_push_cost(struct s_stacks *stack_a, struct s_stacks *stack_b, int value) 
{
	struct s_stacks *target_b = find_node(stack_b, value);  // Trouve le noeud avec la valeur donnée
	int position_b = find_position(stack_b, target_b);      // Trouve la position dans stack_b
	int target_position = find_position(stack_a, find_target_node(stack_a, target_b)); // Trouve où positionner dans A
	int	size_a = stack_size(stack_a);
	int	size_b = stack_size(stack_b);
	int push_cost;

	// Calcul du coût pour les rotations de B
	if (position_b <= size_b / 2)
		push_cost = position_b;  // Rotation vers le haut (rb)
	else
		push_cost = size_b - position_b;  // Rotation vers le bas (rrb)

	// Calcul du coût pour les rotations de A
	if (target_position <= size_a / 2)
		push_cost += target_position;  // Rotation vers le haut (ra)
	else
		push_cost += size_a - target_position;  // Rotation vers le bas (rra)

	return (push_cost);
}*/

int calculate_push_cost(struct s_stacks *stack_a, struct s_stacks *stack_b, int value) 
{
	struct s_stacks *target_a = find_node(stack_a, value);  // Trouve le noeud avec la valeur donnée dans stack_a
	int position_b = find_position(stack_b, find_node(stack_b, value));  // Trouve la position de 'value' dans stack_b
	int target_position = find_position(stack_a, find_target_node(stack_a, find_node(stack_b, value)));  // Trouve la position cible dans stack_a
	int size_a = stack_size(stack_a);
	int size_b = stack_size(stack_b);
	int push_cost;

	// Calcul du coût pour les rotations dans stack_b
	if (position_b <= size_b / 2)
		push_cost = position_b;  // Rotation vers le haut (rb)
	else
		push_cost = size_b - position_b;  // Rotation vers le bas (rrb)

	// Calcul du coût pour les rotations dans stack_a
	if (target_position <= size_a / 2)
		push_cost += target_position;  // Rotation vers le haut (ra)
	else
		push_cost += size_a - target_position;  // Rotation vers le bas (rra)

	return (push_cost);
}


/*struct s_stacks *find_cheapest_to_push(struct s_stacks *stack_a, struct s_stacks *stack_b) 
{
    long			best_match_value;
	struct s_stacks *best_match_node = NULL;

	// Si stack_b est vide, on ne fait rien
	if (stack_a == NULL)
		return (NULL);

	best_match_value = LONG_MAX;
	while (stack_a)
	{
		// Calculer le coût de pousser cet élément dans stack_a
		int push_cost = calculate_push_cost(stack_a, stack_b, stack_b->data);

		// Comparer avec le meilleur coût trouvé jusqu'à présent
		if (push_cost < best_match_value)
		{
			best_match_value = push_cost;
			best_match_node = stack_a;
		}
		stack_a = stack_a->next;  // Avancer dans stack_b
	}
    return (best_match_node);  // Retourner l'élément avec le coût minimum
}*/


/*struct s_stacks *find_cheapest_to_push_old(struct s_stacks *stack_a, struct s_stacks *stack_b) 
{
    struct s_stacks *current_a = stack_a;
    struct s_stacks *cheapest = NULL;
    int min_cost = INT_MAX;

    while (current_a) 
	{
        int cost = calculate_push_cost(stack_a, stack_b, current_a->data);
        if (cost < min_cost) 
		{
            min_cost = cost;
            cheapest = current_a;
        }
        current_a = current_a->next;
    }
    return (cheapest);
}*/

/*void push_cheapest_to_b(struct s_stacks **stack_a, struct s_stacks **stack_b) 
{
    //int push_cost = calculate_push_cost(stack_a, stack_b);
	struct s_stacks *cheapest = find_cheapest_to_push(*stack_a, *stack_b);

    // Rotation simultanée si possible
    rotate_stack_a_and_b(stack_a, stack_b, cheapest, find_target_node(*stack_a, *stack_a));
	//rotate_stack_a_and_b(stack_a, stack_b, cheapest, find_target_node_old(*stack_b, (*stack_b)->data));
    
    // Ajustement final dans les deux stacks avant de pousser
    rotate_stack_a_to_target(stack_a, cheapest);
    rotate_stack_b_to_target(stack_b, find_target_node(*stack_b, *stack_a));
	//rotate_stack_b_to_target(stack_b, find_target_node_old(*stack_b, (*stack_b)->data));
    
    // Pousser dans STACK_B
    pb(stack_a, stack_b);
}*/

struct s_stacks *find_cheapest_to_push_a(struct s_stacks *stack_a, struct s_stacks *stack_b) 
{
    long			best_match_value;
	struct s_stacks *best_match_node = NULL;

	// Si stack_b est vide, on ne fait rien
	if (stack_b == NULL)
		return (NULL);

	best_match_value = LONG_MAX;
	while (stack_b)
	{
		// Calculer le coût de pousser cet élément de stack_b vers stack_a
		int push_cost = calculate_push_cost(stack_a, stack_b, stack_b->data);

		// Comparer avec le meilleur coût trouvé jusqu'à présent
		if (push_cost < best_match_value)
		{
			best_match_value = push_cost;
			best_match_node = stack_b;
		}
		stack_b = stack_b->next;  // Avancer dans stack_b
	}
    return (best_match_node);  // Retourner l'élément avec le coût minimum
}

void push_cheapest_to_a(struct s_stacks **stack_a, struct s_stacks **stack_b) 
{
    struct s_stacks *cheapest = find_cheapest_to_push_a(*stack_a, *stack_b);
    
    // Trouver les cibles dans chaque pile
    struct s_stacks *target_a = find_target_node(*stack_a, cheapest);
    struct s_stacks *target_b = find_target_node_in_b(*stack_a, *stack_b);

    // Effectuer les rotations simultanées si possible
    rotate_stack_a_and_b(stack_a, stack_b, target_a, target_b);

    // Ajuster les rotations individuelles avant de pousser
    //rotate_stack_a_to_target(stack_a, target_a);
    //rotate_stack_b_to_target(stack_b, target_b);

	finish_rotation(stack_b, cheapest, 'b');
	finish_rotation(stack_a, find_target_node(*stack_a, cheapest), 'a');
    
    // Pousser dans STACK_A
    pa(stack_a, stack_b);
}

void	set_current_position(struct s_stacks *stack)
{
	int	i;
	int	centerline;

	i = 0;
	if (NULL == stack)
		return ;
	centerline = stack_size(stack) / 2;
	while (stack)
	{
		stack->current_position = i;
		if (i <= centerline)
			stack->above_median = 1;
		else
			stack->above_median = 0;
		stack = stack->next;
		++i;
	}
}

/*
 *	Best match is..
 *   | "The Smallest-bigger value" |
 *
 *  if no node is Bigger, best_match is the Smallest node.
 *  TLDR 
 *  With this function every node in b gets its target node in a
*/
static void	set_target_node(struct s_stacks *stack_a, struct s_stacks *stack_b)
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
void	set_price(struct s_stacks *stack_a, struct s_stacks *stack_b)
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

/*
 * Flag the cheapest node in the current
 * stacks configurations
*/
void	set_cheapest(struct s_stacks *stack_b)
{
	long			best_match_value;
	struct s_stacks	*best_match_node;

	if (stack_b == NULL)
		return ;
	best_match_value = LONG_MAX;
	best_match_node = NULL;
	while (stack_b)
	{
		if (stack_b->push_cost < best_match_value)
		{
			best_match_value = stack_b->push_cost;
			best_match_node = stack_b;
		}
		stack_b = stack_b->next;
	}
	if (best_match_node)
		best_match_node->cheapest = 1;
}

struct s_stacks *return_cheapest(struct s_stacks *stack)
{
	if (NULL == stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

/*
 * All the necessary values to make the push
 * 		~Relative Positions
 * 		~Target node, the b node to make emerge
 * 		~Price for every configuration
 * 		~Cheapest in the current configuration
*/
void	init_nodes(struct s_stacks *stack_a, struct s_stacks *stack_b)
{
	set_current_position(stack_a);
	set_current_position(stack_b);
	set_target_node(stack_a, stack_b);
	set_price(stack_a, stack_b);
	set_cheapest(stack_b);
}

static void	rotate_both(struct s_stacks **stack_a, struct s_stacks **stack_b, struct s_stacks *cheapest_node)
{
	while (*stack_a != cheapest_node->target_node && *stack_b != cheapest_node)
		rr(stack_a, stack_b);
	set_current_position(*stack_a);
	set_current_position(*stack_b);
}

static void	reverse_rotate_both(struct s_stacks **stack_a, struct s_stacks **stack_b, struct s_stacks *cheapest_node)
{
	while (*stack_a != cheapest_node->target_node && *stack_b != cheapest_node)
		rrr(stack_a, stack_b);

	set_current_position(*stack_a);
	set_current_position(*stack_b);
}

/*
 * Conclude the rotation of the stacks 
*/
void	finish_rotation(struct s_stacks **stack, struct s_stacks *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack, 0);
			else
				rra(stack, 0);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack, 0);
			else
				rrb(stack, 0);
		}	
	}
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

static void	move_nodes(struct s_stacks **stack_a, struct s_stacks **stack_b)
{
	struct s_stacks	*cheapest_node;

	cheapest_node = return_cheapest(*stack_b);
	
	/*if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_both(stack_a, stack_b, cheapest_node);

	else if (!(cheapest_node->above_median) && !(cheapest_node->target_node->above_median))
		reverse_rotate_both(stack_a, stack_b, cheapest_node);*/

	rotate_stack_a_and_b(stack_a, stack_b, (*stack_a)->target_node, (*stack_b)->target_node);


	finish_rotation(stack_b, cheapest_node, 'b');
	finish_rotation(stack_a, cheapest_node->target_node, 'a');
	pa(stack_a, stack_b);
}

void rush_a(struct s_stacks **stack_a, struct s_stacks **stack_b) 
{
    while (*stack_b) 
	{
		set_current_position(stack_a);
		set_current_position(stack_b);
        /*struct s_stacks *target_in_a = find_target_node(*stack_a, *stack_b);
        rotate_stack_a_to_target(stack_a, target_in_a);
        pa(stack_a, stack_b);*/
		push_cheapest_to_a(stack_a, stack_b);
		//init_nodes(*stack_a, *stack_b);
		//move_nodes(stack_a, stack_b);
    }
}

void algo_plus(struct s_stacks **stack_a, struct s_stacks **stack_b, struct s_stacks *value)
{
    //push_first(stack_a, stack_b);
	rush_b(stack_a, stack_b);
    algo_3(stack_a);
    rush_a(stack_a, stack_b);
	set_current_position(*stack_a);
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
		//algo_4(head_a);
		algo_plus(head_a, head_b, value);
	}
	else if (value->numbers_in_stack == 5)
	{
		//algo_5(head_a);
		algo_plus(head_a, head_b, value);
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
	print_stack_a(head_a);
	print_stack_b(head_b);
	//ft_printf("Check stack size : %d\n", stack_size(head_a));
	//check_sorted(&head_a);
	algorithmes(&head_a, &head_b, &stacks);
	check_sorted(&head_a);
	//ra(&head_a);
	//rr(&head_a, &head_b);
	//rra(&head_a);
	//rrb(&head_b);
	//rrr(&head_a, &head_b);
	print_stack_a(head_a);
	print_stack_b(head_b);
	//ft_printf("Check stack size : %d\n", stack_size(head_a));
	free_stack(head_a);
	free_stack(head_b);
	free_array(stacks.numbers);
	return (0);
}

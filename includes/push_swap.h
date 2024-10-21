/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonsat <lmonsat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 00:38:03 by lmonsat           #+#    #+#             */
/*   Updated: 2024/10/21 01:26:06 by lmonsat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include "../printf/ft_printf.h"
# include "../libft/libft.h"
# define STACK_SIZE 1500

struct s_stacks
{
	
	struct s_stacks	*next;
	struct s_stacks	*prev;
	struct s_stacks *target_node;
	char **numbers;
	char **split_numbers;
	int	data;
	int is_string_numbers;
	int numbers_in_stack;
	int current_position;
	int cheapest;
	int above_median;
	int push_cost;

};

int	ft_strcmp(char *s1, char *s2);
int string_numbers(char *argv[], struct s_stacks *stack, int n, int i);
void check_numbers(struct s_stacks *value);
int is_sorted(struct s_stacks **head);
int is_int(const char *str, struct s_stacks *stack);
int max_in_stack(struct s_stacks **head);
int min_in_stack(struct s_stacks **head);
int stack_size(struct s_stacks *stack);

void alloc_array(struct s_stacks *value);
void free_array(char **array);
void free_multiple_arrays(char **array1, char **array2);
void free_stack(struct s_stacks *head);

void pa(struct s_stacks **head_a, struct s_stacks **head_b);
void pb(struct s_stacks **head_a, struct s_stacks **head_b);
void sa(struct s_stacks **head, int is_ss);
void sb(struct s_stacks **head, int is_ss);
void ss(struct s_stacks **head_a, struct s_stacks **head_b);
void ra(struct s_stacks **head, int is_rr);
void rb(struct s_stacks **head, int is_rr);
void rr(struct s_stacks **head_a, struct s_stacks **head_b);
void rra(struct s_stacks **head, int is_rrr);
void rrb(struct s_stacks **head, int is_rrr);
void rrr(struct s_stacks **head_a, struct s_stacks **head_b);

void algo_2(struct s_stacks **head);
void algo_3(struct s_stacks **head);
void algo_4(struct s_stacks **head);
void algo_5(struct s_stacks **head);

void print_stack_a(struct s_stacks *current);
struct s_stacks *create_node_a(int data);
void insert_head_a(struct s_stacks **head, int new_data);
struct s_stacks *pop_last(struct s_stacks **head);
void push_last(struct s_stacks **head, struct s_stacks *last);

#endif
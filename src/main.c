/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:14:56 by manu              #+#    #+#             */
/*   Updated: 2022/06/27 20:59:51 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> //exit
#include <stdio.h>
#include <limits.h>

#include "push_swap.h"
#include "ft_printf.h"
#include "error.h"
#include "moves_push.h"
#include "stack_printing.h"
#include "moves_swap.h"
#include "moves_rotate.h"
#include "moves_reverse_rotate.h"
#include "number_validation.h"
#include "stack_sorting.h"
#include "stack_node.h"
#include "libft.h"

// push_top_a_to_top_b(&state);
// push_top_a_to_top_b(&state);
// push_top_a_to_top_b(&state);
// push_top_a_to_top_b(&state);
// push_top_a_to_top_b(&state);
// rotate_stack_a(&state);
// rotate_stack_b(&state);
// rotate_stack_a_and_b(&state);
// reverse_rotate_stack_a(&state);
// reverse_rotate_stack_b(&state);
// reverse_rotate_stack_a_and_b(&state);
// print_stack_a(&state);
// print_stack_b(&state);

int	validate_input_parameters(int argc, char *argv[])
{
	if (argc <= 1)
		return (0);
	if (!argv[0] || !argv[1])
		return (0);
	return (1);
}

t_number	*str_to_number(char *str)
{
	t_number	*number;

	if (!is_valid_number(str))
		exit_with_error();
	number = (t_number *)malloc(sizeof(t_number));
	if (!number)
		exit_with_memory_error();
	number->n = ft_atoi(str);
	if (!is_valid_int(number->n))
		exit_with_error();
	return (number);
}

int	space_separated_numbers_to_stack(char *numbers, t_list **stack)
{
	int		index;
	char	**split;

	if (!stack || !numbers)
		exit_with_error();
	split = ft_split(numbers, ' ');
	if (!split)
		return (0);
	index = 0;
	while (split[index])
	{
		ft_lstadd_back(stack, ft_lstnew(str_to_number(split[index])));
		index++;
	}
	return (1);
}

int	get_numbers_from_input(int argc, char *argv[], t_state *state)
{
	int	index;

	if (!state)
		return (0);
	index = 1;
	while (index < argc)
	{
		space_separated_numbers_to_stack(argv[index], &state->stack_a);
		index++;
	}
	return (1);
}

int	get_distance_to_sorted_position(long n, t_list *stack, int stack_size)
{
	int		distance_to_sorted_position;
	int		distance_to_max_number;
	long	max;
	long	stack_node_number;

	if (!stack_size)
		return (0);
	if (stack_size == 1)
	{
		if (n > get_node_number(stack))
			return (0);
		else
			return (1);
	}
	max = INT_MIN;
	distance_to_max_number = 0;
	distance_to_sorted_position = 0;
	while (stack)
	{
		stack_node_number = get_node_number(stack);
		if (n > stack_node_number && stack_node_number > max)
		{
			distance_to_max_number = distance_to_sorted_position;
			max = stack_node_number;
		} else if (n < stack_node_number)
			break;
		distance_to_sorted_position++;
		stack = stack->next;
	}
	if (distance_to_sorted_position == stack_size)
	{
		if (distance_to_max_number)
			return (distance_to_max_number);
		return (0);
	}
	while (stack && n < get_node_number(stack))
	{
		distance_to_sorted_position++;
		if(stack->next && (get_node_number(stack) < get_node_number(stack->next)))
			return(distance_to_sorted_position);
		stack = stack->next;
	}
	if (distance_to_sorted_position == stack_size)
		return (stack_size);
	return (distance_to_sorted_position);
}

int	main(int argc, char *argv[])
{
	t_state	state;

	if (argc <= 1)
		exit(0);
	if (!validate_input_parameters(argc, argv))
		exit_with_error();
	if (!get_numbers_from_input(argc, argv, &state))
		exit_with_error();
	if (ft_lstsize(state.stack_a) < 2)
		exit(0); // free
	if (is_stack_sorted(state.stack_a))
		exit(0);

	int size = ft_lstsize(state.stack_a);
	int i = 0;
	int	number_rotates = 0;
	while (i < size)
	{
		if(i == 0)
			push_top_a_to_top_b(&state);
		else
		{
			number_rotates = get_distance_to_sorted_position(get_node_number(state.stack_a), state.stack_b, ft_lstsize(state.stack_b));
			// printf("get_distance_to_sorted_position of number %ld is %d\n", get_node_number(state.stack_a), number_rotates);
			if (!number_rotates)
				push_top_a_to_top_b(&state);
			else if (number_rotates == 1)
			{
				push_top_a_to_top_b(&state);
				swap_stack_b_top_nodes(&state);
			}
			else if (number_rotates < (ft_lstsize(state.stack_b)/2))
			{
				rotate_stack_b_n_times(&state, number_rotates);
				push_top_a_to_top_b(&state);
			}
			else
			{
				reverse_rotate_stack_b_n_times(&state, ft_lstsize(state.stack_b) - number_rotates);
				push_top_a_to_top_b(&state);
			}
		}
		// print_stack_a(&state);
		// print_stack_b(&state);
		// if (i == 1) exit(0);
		i++;
	}

	// This is to be optmized. Decide whether we rotate normally or in reverse order. The one with less moves.
	while(!is_stack_reversed_sorted(state.stack_b))
	{
		rotate_stack_b(&state);
		// print_stack_a(&state);
		// print_stack_b(&state);
	}
	
	int n = ft_lstsize(state.stack_b);
	while(n--)
		push_top_b_to_top_a(&state);

	// print_stack_a(&state);
	// print_stack_b(&state);
	state.stack_a = NULL;
	state.stack_b = NULL;
	return (0);
}

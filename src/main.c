/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:14:56 by manu              #+#    #+#             */
/*   Updated: 2022/06/25 20:41:38 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> //exit
#include <stdio.h>

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

// int	get_distance_to_sorted_position(long int n, t_list *stack)
// {
// 	int distance_to_sorted_position;

// 	distance_to_sorted_position = 0;
// 	while (stack && n < get_node_number(stack))
// 	{
// 		distance_to_sorted_position++;
// 		stack = stack->next;
// 	}
// 	return (distance_to_sorted_position);
// }

// int	get_distance_to_sorted_position(long int n, t_list *stack, int size)
// {
// 	int distance_to_sorted_position;
// 	int index;

// 	index = 0;
// 	distance_to_sorted_position = 0;
// 	if (!size)
// 		return 0;
// 	if (size == 1)
// 	{
// 		if (n > get_node_number(stack))
// 			return (0);
// 		else
// 			return (1);
// 	}
// 	while (stack)
// 	{
// 		if (index == 0)
// 		{
// 			if (n > get_node_number(ft_lstlast(stack)) && n > get_node_number(stack))
// 				break;
// 		}
// 		else if (index == size - 1)
// 		{
// 			if (get_node_number(stack) > n && n > get_node_number(stack))
// 				break;
// 		}
// 		else
// 		{
// 			if (get_node_number(stack) > n && n > get_node_number(stack->next))
// 				break;
// 		}
// 		distance_to_sorted_position++;
// 		stack = stack->next;
// 		index++;
// 	}
// 	return (distance_to_sorted_position);
// }

int	get_distance_to_sorted_position(long int n, t_list *stack, int size)
{
	int distance_to_sorted_position;
	int index;

	index = 0;
	distance_to_sorted_position = 0;
	if (!size)
		return 0;
	if (size == 1)
	{
		if (n > get_node_number(stack))
			return (0);
		else
			return (1);
	}
	while (stack && n > get_node_number(stack))
	{
		distance_to_sorted_position++;
		stack = stack->next;
	}
	if (distance_to_sorted_position == size)
		return (0);
	index = distance_to_sorted_position;
	while (stack && n < get_node_number(stack))
	{
		distance_to_sorted_position++;
		if(stack->next && (get_node_number(stack) < get_node_number(stack->next)))
			return(distance_to_sorted_position);
		stack = stack->next;
	}
	if (distance_to_sorted_position == size)
		return (size);
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
	int max = 0;
	int stop = 0;

	while (i < size)
	{
		if (get_node_number(state.stack_a) == 1)
		{
			stop = 1;
		}
		if (max < get_node_number(state.stack_a))
			max = get_node_number(state.stack_a);
		if(i == 0)
			push_top_a_to_top_b(&state);
		else
		{
			number_rotates = get_distance_to_sorted_position(get_node_number(state.stack_a), state.stack_b, ft_lstsize(state.stack_b));
			printf("get_distance_to_sorted_position of number %ld is %d\n", get_node_number(state.stack_a), number_rotates);
			if (!number_rotates)
				push_top_a_to_top_b(&state);
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

	print_stack_a(&state);
	print_stack_b(&state);
	state.stack_a = NULL;
	state.stack_b = NULL;
	return (0);
}

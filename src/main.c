/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:14:56 by manu              #+#    #+#             */
/*   Updated: 2022/06/29 19:12:43 by manu             ###   ########.fr       */
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
#include "get_number_moves.h"
#include "stack_init.h"

int	validate_input_parameters(int argc, char *argv[])
{
	if (argc <= 1)
		return (0);
	if (!argv[0] || !argv[1])
		return (0);
	return (1);
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
	int max = INT_MIN;
	int total_moves = 0;
	while (i < size)
	{
		if (get_node_number(state.stack_a) > max)
			max = get_node_number(state.stack_a);
		if(i == 0)
			push_top_a_to_top_b(&state);
		else
		{
			number_rotates = get_distance_to_sorted_position(get_node_number(state.stack_a), state.stack_b, ft_lstsize(state.stack_b));
			// printf("\nSorting number. get_distance_to_sorted_position of number %ld is %d\n", get_node_number(state.stack_a), number_rotates);
			if (!number_rotates) {
				push_top_a_to_top_b(&state);
				total_moves++;
			}
			else if (number_rotates == 1)
			{
				push_top_a_to_top_b(&state);
				swap_stack_b_top_nodes(&state);
				total_moves+=2;
			}
			else if (number_rotates < (ft_lstsize(state.stack_b)/2))
			{
				rotate_stack_b_n_times(&state, number_rotates);
				push_top_a_to_top_b(&state);
				total_moves+=number_rotates + 1;
			}
			else
			{
				reverse_rotate_stack_b_n_times(&state, ft_lstsize(state.stack_b) - number_rotates);
				push_top_a_to_top_b(&state);
				total_moves+=ft_lstsize(state.stack_b) - number_rotates + 1;
			}
		}
		// print_stack_a(&state);
		// print_stack_b(&state);
		// if (i == 2) exit(0);
		i++;
	}

	number_rotates = get_distance_to_sorted_position(max + 1, state.stack_b, ft_lstsize(state.stack_b));
	// printf("\n\n\nSorting all B. get_distance_to_sorted_position to sort b %d is %d\n", max + 1, number_rotates);

	if (number_rotates < (ft_lstsize(state.stack_b)/2)) {
		rotate_stack_b_n_times(&state, number_rotates);
		total_moves+=number_rotates;
	}
	else
	{
		reverse_rotate_stack_b_n_times(&state, ft_lstsize(state.stack_b) - number_rotates);
		total_moves+=ft_lstsize(state.stack_b) - number_rotates;
	}
	
	// printf("\n\n\nMoving all numbers to A (%d moves)\n", ft_lstsize(state.stack_b));

	int n = ft_lstsize(state.stack_b);
	while(n--)
		push_top_b_to_top_a(&state);

	total_moves+=ft_lstsize(state.stack_a);

	// printf("TOTAL MOVES (%d moves)\n", total_moves);

	// print_stack_a(&state);
	// print_stack_b(&state);
	state.stack_a = NULL;
	state.stack_b = NULL;
	return (0);
}

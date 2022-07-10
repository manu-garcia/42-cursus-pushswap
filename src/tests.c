/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:14:56 by manu              #+#    #+#             */
/*   Updated: 2022/07/10 13:08:42 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <assert.h>

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

void	test_1(void)
{
	t_state	state;

	if (!space_separated_numbers_to_stack("30 20 10", &state.stack_a))
		exit_with_error(&state);
	assert(ft_lstsize(state.stack_a) == 3);
	assert(is_stack_reversed_sorted(state.stack_a));
	assert(get_node_number(state.stack_a) == 30);
	assert(get_node_number(state.stack_a->next->next) == 10);
	assert(get_distance_to_sorted_position(35, state.stack_a,
			ft_lstsize(state.stack_a)) == 0);
	assert(get_distance_to_sorted_position(25, state.stack_a,
			ft_lstsize(state.stack_a)) == 1);
	assert(get_distance_to_sorted_position(15, state.stack_a,
			ft_lstsize(state.stack_a)) == 2);
	assert(get_distance_to_sorted_position(0, state.stack_a,
			ft_lstsize(state.stack_a)) == 0);
}

void	test_2(void)
{
	t_state	state;

	if (!space_separated_numbers_to_stack("10 30 20", &state.stack_a))
		exit_with_error(&state);
	assert(ft_lstsize(state.stack_a) == 3);
	assert(is_stack_reversed_sorted(state.stack_a) == 0);
	assert(get_distance_to_sorted_position(35, state.stack_a,
			ft_lstsize(state.stack_a)) == 1);
	assert(get_distance_to_sorted_position(25, state.stack_a,
			ft_lstsize(state.stack_a)) == 2);
	assert(get_distance_to_sorted_position(15, state.stack_a,
			ft_lstsize(state.stack_a)) == 0);
	assert(get_distance_to_sorted_position(0, state.stack_a,
			ft_lstsize(state.stack_a)) == 1);
}

int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	test_1();
	test_2();
	return (0);
}

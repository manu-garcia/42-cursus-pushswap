/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:14:56 by manu              #+#    #+#             */
/*   Updated: 2022/07/04 21:09:05 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> //exit

#include "push_swap.h"
#include "error.h"
#include "stack_sorting.h"
#include "stack_init.h"
#include "algorithm_2_best_a_and_b_move.h"
#include "algorithm_sort_3.h"
#include "algorithm_sort_5.h"

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

	if (ft_lstsize(state.stack_a) == 3)
		algorithm_sort_3(&state);
	else if (ft_lstsize(state.stack_a) == 5)
		algorithm_sort_5(&state);
	else
		algorithm_2_best_a_and_b_move(&state);
	state.stack_a = NULL;
	state.stack_b = NULL;
	return (0);
}

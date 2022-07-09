/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:14:56 by manu              #+#    #+#             */
/*   Updated: 2022/07/09 18:55:57 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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

	ft_memset(&state, 0, sizeof(t_state));
	if (argc <= 1)
		exit_without_error(&state);
	if (!validate_input_parameters(argc, argv))
		exit_with_error(&state);
	if (!get_numbers_from_input(argc, argv, &state))
		exit_with_error(&state);
	if (ft_lstsize(state.stack_a) < 2)
		exit_without_error(&state);
	if (is_stack_sorted(state.stack_a))
		exit_without_error(&state);
	if (ft_lstsize(state.stack_a) == 3)
		algorithm_sort_3(&state);
	else if (ft_lstsize(state.stack_a) == 5)
		algorithm_sort_5(&state);
	else
		algorithm_2_best_a_and_b_move(&state);
	exit_without_error(&state);
}

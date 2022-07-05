/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:14:56 by manu              #+#    #+#             */
/*   Updated: 2022/07/05 20:50:00 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> //exit
#include <unistd.h>
#include <stdio.h>

#include "push_swap.h"
#include "error.h"
#include "stack_sorting.h"
#include "stack_printing.h"
#include "stack_init.h"
#include "algorithm_2_best_a_and_b_move.h"
#include "algorithm_sort_3.h"
#include "algorithm_sort_5.h"
#include "move.h"

#define MAX_USER_INPUT_LENGTH 4

static int	validate_input_parameters(int argc, char *argv[])
{
	if (argc <= 1)
		return (0);
	if (!argv[0] || !argv[1])
		return (0);
	return (1);
}

static t_move_type	get_move_type(char *str_move)
{
	if (!ft_strncmp("rra", str_move, 3))
		return MOVE_RRA;
	else if (!ft_strncmp("rrb", str_move, 3))
		return MOVE_RRB;
	else if (!ft_strncmp("rrr", str_move, 3))
		return MOVE_RRR;
	else if (!ft_strncmp("ra", str_move, 2))
		return MOVE_RA;
	else if (!ft_strncmp("rb", str_move, 2))
		return MOVE_RB;
	else if (!ft_strncmp("rr", str_move, 2))
		return MOVE_RR;
	else if (!ft_strncmp("sa", str_move, 2))
		return MOVE_SA;
	else if (!ft_strncmp("sb", str_move, 2))
		return MOVE_SB;
	else if (!ft_strncmp("ss", str_move, 2))
		return MOVE_SS;
	else if (!ft_strncmp("pa", str_move, 2))
		return MOVE_PA;
	else if (!ft_strncmp("pb", str_move, 2))
		return MOVE_PB;
	return MOVE_NOTHING;
}

int	main(int argc, char *argv[])
{
	t_state	state;
	char	user_input[MAX_USER_INPUT_LENGTH];

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

	int user_input_length;
    while ((user_input_length = read(STDIN_FILENO, &user_input, MAX_USER_INPUT_LENGTH)) != -1)
	{
		user_input[user_input_length - 1] = '\0';
		if (get_move_type(user_input) == MOVE_NOTHING)
			break;
		else
			apply_move(&state, get_move_type(user_input), 1);
	}

	print_stack_a(&state);
	print_stack_b(&state);

	state.stack_a = NULL;
	state.stack_b = NULL;
	return (0);
}

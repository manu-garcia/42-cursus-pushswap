/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:14:56 by manu              #+#    #+#             */
/*   Updated: 2022/07/12 19:02:50 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
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
#include "move_apply.h"
#include "ft_printf.h"

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
	if (!ft_strncmp("rra\0", str_move, 4))
		return (MOVE_RRA);
	else if (!ft_strncmp("rrb\0", str_move, 4))
		return (MOVE_RRB);
	else if (!ft_strncmp("rrr\0", str_move, 4))
		return (MOVE_RRR);
	else if (!ft_strncmp("ra\0", str_move, 3))
		return (MOVE_RA);
	else if (!ft_strncmp("rb\0", str_move, 3))
		return (MOVE_RB);
	else if (!ft_strncmp("rr\0", str_move, 3))
		return (MOVE_RR);
	else if (!ft_strncmp("sa\0", str_move, 3))
		return (MOVE_SA);
	else if (!ft_strncmp("sb\0", str_move, 3))
		return (MOVE_SB);
	else if (!ft_strncmp("ss\0", str_move, 3))
		return (MOVE_SS);
	else if (!ft_strncmp("pa\0", str_move, 3))
		return (MOVE_PA);
	else if (!ft_strncmp("pb\0", str_move, 3))
		return (MOVE_PB);
	return (MOVE_NOTHING);
}

static void	init_state(int argc, char *argv[], t_state *state)
{
	if (argc <= 1 || !validate_input_parameters(argc, argv))
		exit_without_error(state);
	if (!get_numbers_from_input(argc, argv, state))
		exit_with_error(state);
	if (ft_lstsize(state->stack_a) < 2 || is_stack_sorted(state->stack_a))
		exit_without_error(state);
}

static int	get_move(char *user_input)
{
	int	length;

	length = read(STDIN_FILENO, user_input, MAX_USER_INPUT_LENGTH);
	if (length != -1)
		user_input[length - 1] = '\0';
	return (length);
}

int	main(int argc, char *argv[])
{
	t_state	state;
	char	user_input[MAX_USER_INPUT_LENGTH];

	init_state(argc, argv, &state);
	print_stack_a(&state);
	print_stack_b(&state);
	while (get_move((char *)&user_input) != -1)
	{
		if (get_move_type(user_input) == MOVE_NOTHING)
		{
			ft_printf("Error\n");
			continue ;
		}
		apply_move(&state, get_move_type(user_input), 1, MOVE_PRINT_NOTHING);
		print_stack_a(&state);
		print_stack_b(&state);
		if (is_stack_sorted(state.stack_a))
		{
			ft_printf("OK\n");
			break ;
		}
	}
	exit_without_error(&state);
}

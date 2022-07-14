/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:14:56 by manu              #+#    #+#             */
/*   Updated: 2022/07/14 17:05:49 by manugarc         ###   ########.fr       */
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
#include "checker_split.h"

#define MAX_USER_INPUT_LENGTH 100

static int	validate_input_parameters(int argc, char *argv[])
{
	if (argc <= 1)
		return (0);
	if (!argv[0] || !argv[1])
		return (0);
	return (1);
}

static void	init_state(int argc, char *argv[], t_state *state)
{
	ft_memset(state, 0, sizeof(t_state));
	if (argc <= 1 || !validate_input_parameters(argc, argv))
		exit_without_error(state);
	if (!get_numbers_from_input(argc, argv, state))
		exit_with_error(state);
	if (ft_lstsize(state->stack_a) < 2)
		exit_without_error(state);
}

static int	get_move_list(char *user_input, t_move_type **moves, int *n_moves)
{
	int		length;
	char	**split;

	length = read(STDIN_FILENO, user_input, MAX_USER_INPUT_LENGTH);
	if (length != -1)
	{
		user_input[length - 1] = '\0';
		if (user_input[0] == '[')
		{
			split = get_split_moves(user_input, n_moves);
			(*moves) = split_to_moves(split, (*n_moves));
			free_split(split);
		}
		else
		{
			(*n_moves) = 1;
			split = (char **)ft_calloc(1, sizeof(char *) * 2);
			split[0] = ft_strdup(user_input);
			split[1] = NULL;
			(*moves) = split_to_moves(split, (*n_moves));
			free_split(split);
		}
		return (1);
	}
	return (length);
}

int	main(int argc, char *argv[])
{
	t_state		state;
	char		user_input[MAX_USER_INPUT_LENGTH];
	int			n_moves;
	t_move_type	*moves;

	init_state(argc, argv, &state);
	print_stack_a(&state);
	print_stack_b(&state);
	while (get_move_list((char *)&user_input, &moves, &n_moves) != -1)
	{
		ft_printf("\n=========================================\n");
		apply_move_list(&state, moves);
		ft_printf("KO\n");
		free(moves);
		print_stack_a(&state);
		print_stack_b(&state);
	}
}

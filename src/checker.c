/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:14:56 by manu              #+#    #+#             */
/*   Updated: 2022/07/14 16:54:29 by manugarc         ###   ########.fr       */
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

#define MAX_USER_INPUT_LENGTH 100

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
	ft_memset(state, 0, sizeof(t_state));
	if (argc <= 1 || !validate_input_parameters(argc, argv))
		exit_without_error(state);
	if (!get_numbers_from_input(argc, argv, state))
		exit_with_error(state);
	if (ft_lstsize(state->stack_a) < 2)
		exit_without_error(state);
}

static char	**get_split_moves(char *user_input, int *n_moves)
{
	char		*trimmed;
	char		*tmp;
	char		**split;

	(*n_moves) = 0;
	trimmed = ft_strtrim(user_input, "[]");
	if (!trimmed)
		return (NULL);
	split = ft_split(trimmed, ',');
	free(trimmed);
	if (!split)
		return (NULL);
	while (split[(*n_moves)])
	{
		tmp = ft_strtrim(split[(*n_moves)], " ");
		free(split[(*n_moves)]);
		split[(*n_moves)] = tmp;
		(*n_moves)++;
	}
	return (split);
}

static void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		split[i] = NULL;
	}
	free(split);
}

static t_move_type	*split_to_moves(char **split, int n_moves)
{
	int			i;
	t_move_type	*moves;

	moves = (t_move_type *)ft_calloc(1, sizeof(t_move_type) * (n_moves + 1));
	i = 0;
	while (split[i] && n_moves--)
	{
		moves[i] = get_move_type(split[i]);
		i++;
	}
	return (moves);
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

void	apply_move_list(t_state *state, t_move_type *moves)
{
	t_move_type	move;
	int			i;

	i = 0;
	while (moves[i])
	{
		move = moves[i++];
		if (move == MOVE_NOTHING)
		{
			ft_printf("Error\n");
			continue ;
		}
		apply_move(state, move, 1, MOVE_PRINT_NOTHING);
	}
	if (is_stack_sorted(state->stack_a))
	{
		print_stack_a(state);
		print_stack_b(state);
		ft_printf("OK\n");
		exit_without_error(state);
	}
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_best.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 21:09:22 by manu              #+#    #+#             */
/*   Updated: 2022/07/11 15:24:53 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "push_swap.h"
#include "stack_node.h"
#include "move.h"
#include "error.h"
#include "move_number.h"
#include "move_optimize.h"

static t_move	**get_all_moves(t_state *state)
{
	t_move	**moves;
	t_list	*stack_a;
	int		size_a;
	int		size_b;
	int		i;

	size_a = ft_lstsize(state->stack_a);
	size_b = ft_lstsize(state->stack_b);
	moves = (t_move **)ft_calloc(1, size_a * sizeof(t_move *));
	stack_a = state->stack_a;
	i = 0;
	while (stack_a)
	{
		moves[i] = (t_move *)ft_calloc(1, sizeof(t_move));
		if (!moves[i])
			exit_with_error(state);
		(moves[i])->n = get_node_number(stack_a);
		stack_a = stack_a->next;
		i++;
	}
	return (moves);
}

static void	calc_all_moves(t_state *state, t_move **moves)
{
	int		size_a;
	int		size_b;
	int		i;

	size_a = ft_lstsize(state->stack_a);
	size_b = ft_lstsize(state->stack_b);
	i = 0;
	while (i < size_a)
	{
		(moves[i])->size_a = size_a;
		(moves[i])->size_b = size_b;
		get_number_moves_to_top_a(i, moves[i]);
		get_number_moves_to_sort_in_b(state, moves[i]);
		optimize_move(moves[i]);
		i++;
	}
}

static t_move	*select_best_move(t_state *state, t_move **moves)
{
	int		size_a;
	t_move	*best_move;
	int		i;
	int		is_there_best_move;

	size_a = ft_lstsize(state->stack_a);
	best_move = (t_move *)ft_calloc(1, sizeof(t_move));
	i = 0;
	is_there_best_move = 0;
	while (i < size_a)
	{
		if (!is_there_best_move || (moves[i]->number_moves_total)
			< best_move->number_moves_total)
		{
			ft_memcpy(best_move, moves[i], sizeof(t_move));
			is_there_best_move = 1;
		}
		i++;
	}
	return (best_move);
}

t_move	*get_best_move(t_state *state)
{
	t_move	**moves;
	int		size_a;
	int		i;
	t_move	*best_move;

	moves = get_all_moves(state);
	calc_all_moves(state, moves);
	best_move = select_best_move(state, moves);
	size_a = ft_lstsize(state->stack_a);
	i = 0;
	while (i < size_a)
		free(moves[i++]);
	free(moves);
	return (best_move);
}

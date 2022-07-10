/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_2_best_a_and_b_move.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:14:56 by manu              #+#    #+#             */
/*   Updated: 2022/07/10 10:42:55 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdlib.h>

#include "push_swap.h"
#include "moves_push.h"
#include "get_number_moves.h"
#include "move.h"

static void	apply_best_move(t_state *state)
{
	t_move	*best_move;

	best_move = get_best_move(state);
	apply_move(state, best_move->move_type_both,
		best_move->number_moves_both, MOVE_PRINT_TO_SCREEN);
	apply_move(state, best_move->move_type_a,
		best_move->number_moves_a, MOVE_PRINT_TO_SCREEN);
	apply_move(state, best_move->move_type_b,
		best_move->number_moves_b, MOVE_PRINT_TO_SCREEN);
	apply_move(state, MOVE_PB, 1, MOVE_PRINT_TO_SCREEN);
	free(best_move);
}

int	algorithm_2_best_a_and_b_move(t_state *state)
{
	int		size_a;
	int		i;
	int		number_rotates;

	size_a = ft_lstsize(state->stack_a);
	i = 0;
	while (i < size_a)
	{
		apply_best_move(state);
		i++;
	}
	number_rotates = get_distance_to_sorted_position(INT_MAX, state->stack_b,
			ft_lstsize(state->stack_b));
	if (number_rotates < (ft_lstsize(state->stack_b) / 2))
		apply_move(state, MOVE_RB, number_rotates, MOVE_PRINT_TO_SCREEN);
	else
		apply_move(state, MOVE_RRB, ft_lstsize(state->stack_b) - number_rotates,
			MOVE_PRINT_TO_SCREEN);
	apply_move(state, MOVE_PA, ft_lstsize(state->stack_b),
		MOVE_PRINT_TO_SCREEN);
	return (0);
}

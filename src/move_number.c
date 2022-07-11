/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_number.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 21:09:22 by manu              #+#    #+#             */
/*   Updated: 2022/07/11 14:56:20 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "push_swap.h"
#include "moves_push.h"
#include "stack_printing.h"
#include "moves_swap.h"
#include "moves_rotate.h"
#include "moves_reverse_rotate.h"
#include "stack_node.h"
#include "get_number_moves.h"
#include "move.h"
#include "error.h"
#include "ft_min.h"

void	get_number_moves_to_top_a(int actual_index, t_move *move)
{
	move->index_in_a = actual_index;
	if (actual_index < 2)
	{
		move->number_moves_a = actual_index;
		move->move_type_a = MOVE_RA;
	}
	else if (actual_index < (move->size_a / 2))
	{
		move->number_moves_a = actual_index;
		move->move_type_a = MOVE_RA;
	}
	else
	{
		move->number_moves_a = move->size_a - actual_index;
		move->move_type_a = MOVE_RRA;
	}
	if (!move->number_moves_a)
		move->move_type_a = MOVE_NOTHING;
	else
		move->number_moves_total += move->number_moves_a;
}

void	get_number_moves_to_sort_in_b(t_state *state, t_move *move)
{
	move->number_moves_b = get_distance_to_sorted_position(move->n,
			state->stack_b, move->size_b);
	if (move->number_moves_b < 2)
		move->move_type_b = MOVE_RB;
	else if (move->number_moves_b < (move->size_b / 2))
		move->move_type_b = MOVE_RB;
	else
	{
		move->number_moves_b = move->size_b - move->number_moves_b;
		move->move_type_b = MOVE_RRB;
	}
	if (!move->number_moves_b)
		move->move_type_b = MOVE_NOTHING;
	else
		move->number_moves_total += move->number_moves_b;
}

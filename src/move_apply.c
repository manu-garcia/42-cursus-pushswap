/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_apply.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 21:09:22 by manu              #+#    #+#             */
/*   Updated: 2022/07/12 10:32:17 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "moves_push.h"
#include "moves_swap.h"
#include "moves_rotate.h"
#include "moves_rotate_times.h"
#include "moves_reverse_rotate.h"
#include "moves_reverse_rotate_times.h"
#include "move.h"

int	apply_move(t_state *state, t_move_type move_type, int n_moves,
	t_move_print_option print_option)
{
	if (move_type == MOVE_PA)
		return (push_top_b_to_top_a_n_times(state, n_moves, print_option));
	else if (move_type == MOVE_PB)
		return (push_top_a_to_top_b_n_times(state, n_moves, print_option));
	else if (move_type == MOVE_RA)
		return (rotate_stack_a_n_times(state, n_moves, print_option));
	else if (move_type == MOVE_RB)
		return (rotate_stack_b_n_times(state, n_moves, print_option));
	else if (move_type == MOVE_RR)
		return (rotate_stack_a_and_b_n_times(state, n_moves, print_option));
	else if (move_type == MOVE_RRA)
		return (reverse_rotate_stack_a_n_times(state, n_moves, print_option));
	else if (move_type == MOVE_RRB)
		return (reverse_rotate_stack_b_n_times(state, n_moves, print_option));
	else if (move_type == MOVE_RRR)
		return (reverse_rotate_stack_a_and_b_n_times(state,
				n_moves, print_option));
	else if (move_type == MOVE_SA)
		return (swap_stack_a_top_nodes(state, print_option));
	else if (move_type == MOVE_SB)
		return (swap_stack_b_top_nodes(state, print_option));
	else if (move_type == MOVE_SS)
		return (swap_stack_a_and_b_top_nodes(state, print_option));
	return (1);
}

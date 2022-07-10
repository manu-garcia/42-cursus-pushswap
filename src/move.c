/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 21:09:22 by manu              #+#    #+#             */
/*   Updated: 2022/07/10 10:12:23 by manugarc         ###   ########.fr       */
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

static void get_number_moves_to_top_a(int actual_index, t_move *move)
{
    move->index_in_a = actual_index;

    if (actual_index < 2) {
        move->number_moves_a = actual_index;
        move->move_type_a = MOVE_RA;
    }
    else if (actual_index < (move->size_a/2))
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

static void get_number_moves_to_sort_in_b(t_state *state, t_move *move)
{
    move->number_moves_b = get_distance_to_sorted_position(move->n, state->stack_b, move->size_b);
    if (move->number_moves_b < 2) {
        move->move_type_b = MOVE_RB;
    }
    else if (move->number_moves_b < (move->size_b/2))
    {
        move->move_type_b = MOVE_RB;
    }
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

static long ft_min(long a, long b)
{
    if (a < b)
        return (a);
    return (b);
}

void optimize_move(t_move *move)
{
    int min;

    if (move->move_type_a == MOVE_RA && move->move_type_b == MOVE_RB)
    {
        move->move_type_both = MOVE_RR;
    }
    else if (move->move_type_a == MOVE_RRA && move->move_type_b == MOVE_RRB) // MOVE_RRR
    {
        move->move_type_both = MOVE_RRR;
    }

    if (move->move_type_both != MOVE_NOTHING)
    {
        min = ft_min(move->number_moves_a, move->number_moves_b);
        move->number_moves_both = min;
        move->number_moves_a -= min;
        move->number_moves_b -= min;

        if (!move->number_moves_a)
            move->move_type_a = MOVE_NOTHING;

        if (!move->number_moves_b)
            move->move_type_b = MOVE_NOTHING;
    }

    move->number_moves_total = move->number_moves_a + move->number_moves_b + move->number_moves_both;
}

t_move  *get_best_move(t_state *state)
{
    t_move **moves;
	t_list	*stack_a;
	int     size_a = ft_lstsize(state->stack_a);
	int     size_b = ft_lstsize(state->stack_b);
    int     i;

    moves = (t_move **)ft_calloc(1, size_a * sizeof(t_move *));
    stack_a = state->stack_a;
    i = 0;
    while(stack_a)
    {
        moves[i] = (t_move *)ft_calloc(1, sizeof(t_move));
        if (!moves[i])
			exit_with_error(state);
        (moves[i])->n = get_node_number(stack_a);
        stack_a = stack_a->next;
        i++;
    }

    i=0;
    while(i<size_a)
    {
        (moves[i])->size_a = size_a;
        (moves[i])->size_b = size_b;
        get_number_moves_to_top_a(i, moves[i]);
        get_number_moves_to_sort_in_b(state, moves[i]);
        optimize_move(moves[i]);
        i++;
    }

    t_move  *best_move = NULL;
	int		is_there_best_move = 0;
	best_move = (t_move *)ft_calloc(1, sizeof(t_move));

    i=0;
    while(i<size_a)
    {
        if (!is_there_best_move || (moves[i]->number_moves_total) < best_move->number_moves_total){
			ft_memcpy(best_move, moves[i], sizeof(t_move));
			is_there_best_move = 1;
		}
        i++;
    }

    i=0;
    while(i<size_a)
    {
        free(moves[i]);
        i++;
    }
	free(moves);
    return best_move;
}

void    apply_move(t_state *state, t_move_type move_type, int number_moves, t_move_print_option print_option)
{
	int move_result;

    if (move_type == MOVE_PA)
        move_result = push_top_b_to_top_a_n_times(state, number_moves, print_option);
    else if (move_type == MOVE_PB)
        move_result = push_top_a_to_top_b_n_times(state, number_moves, print_option);
    else if (move_type == MOVE_RA)
        move_result = rotate_stack_a_n_times(state, number_moves, print_option);
    else if (move_type == MOVE_RB)
        move_result = rotate_stack_b_n_times(state, number_moves, print_option);
    else if (move_type == MOVE_RR)
        move_result = rotate_stack_a_and_b_n_times(state, number_moves, print_option);
    else if (move_type == MOVE_RRA)
        move_result = reverse_rotate_stack_a_n_times(state, number_moves, print_option);
    else if (move_type == MOVE_RRB)
        move_result = reverse_rotate_stack_b_n_times(state, number_moves, print_option);
    else if (move_type == MOVE_RRR)
        move_result = reverse_rotate_stack_a_and_b_n_times(state, number_moves, print_option);
    else if (move_type == MOVE_SA)
        move_result = swap_stack_a_top_nodes(state, print_option);
    else if (move_type == MOVE_SB)
        move_result = swap_stack_b_top_nodes(state, print_option);
    else if (move_type == MOVE_SS)
        move_result = swap_stack_a_and_b_top_nodes(state, print_option);
    else if (move_type != MOVE_NOTHING)
    {
    	printf("\n\n\nInternal Error applying move type (%d)\n", move_type);
        exit_with_error(state);
    }
}

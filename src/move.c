/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 21:09:22 by manu              #+#    #+#             */
/*   Updated: 2022/07/04 21:09:28 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h> // write

#include "push_swap.h"
#include "moves_push.h"
#include "stack_printing.h"
#include "moves_swap.h"
#include "moves_rotate.h"
#include "moves_reverse_rotate.h"
#include "stack_node.h"
#include "get_number_moves.h"
#include "move.h"

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
        // printf("Same movement on both. Type (RR). N moves in A (%d). N moves in B (%d)\n", move->number_moves_a, move->number_moves_b);
        move->move_type_both = MOVE_RR;
    }
    else if (move->move_type_a == MOVE_RRA && move->move_type_b == MOVE_RRB) // MOVE_RRR
    {
        // printf("Same movement on both. Type (RRR). N moves in A (%d). N moves in B (%d)\n", move->number_moves_a, move->number_moves_b);
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

    moves = (t_move **)malloc(size_a * sizeof(t_move *));
    stack_a = state->stack_a;
    i = 0;
    while(stack_a)
    {
        moves[i] = (t_move *)calloc(1, sizeof(t_move));
        // if (!ptr)
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
    i=0;
    while(i<size_a)
    {
        if (!best_move || (moves[i]->number_moves_total) < best_move->number_moves_total)
            best_move = moves[i];
        i++;
    }

    // free all moves
    // free **moves
    // malloc of a new best_move and return it. Caller should free it
    return best_move;
}

void    apply_move(t_state *state, t_move_type move_type, int number_moves)
{
    if (move_type == MOVE_PA)
    {
        push_top_b_to_top_a_n_times(state, number_moves);
    }
    else if (move_type == MOVE_PB)
    {
        push_top_a_to_top_b_n_times(state, number_moves);
    }
    else if (move_type == MOVE_RA)
    {
        rotate_stack_a_n_times(state, number_moves);
    }
    else if (move_type == MOVE_RB)
    {
        rotate_stack_b_n_times(state, number_moves);
    }
    else if (move_type == MOVE_RR)
    {
        rotate_stack_a_and_b_n_times(state, number_moves);
    }
    else if (move_type == MOVE_RRA)
    {
        reverse_rotate_stack_a_n_times(state, number_moves);
    }
    else if (move_type == MOVE_RRB)
    {
        reverse_rotate_stack_b_n_times(state, number_moves);
    }
    else if (move_type == MOVE_RRR)
    {
        reverse_rotate_stack_a_and_b_n_times(state, number_moves);
    }
    else if (move_type == MOVE_SA)
    {
        swap_stack_a_top_nodes(state);
    }
    else if (move_type == MOVE_SB)
    {
        swap_stack_b_top_nodes(state);
    }
    else if (move_type == MOVE_SS)
    {
        // Missing move fn
    	printf("\n\n\nInternal Error missing MOVE_SS implementation.\n");
        exit(0);
    }
    else if (move_type != MOVE_NOTHING)
    {
    	printf("\n\n\nInternal Error applying move type (%d)\n", move_type);
        exit(0);
    }
}

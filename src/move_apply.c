/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_apply.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 21:09:22 by manu              #+#    #+#             */
/*   Updated: 2022/07/14 17:22:21 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"
#include "moves_push.h"
#include "moves_swap.h"
#include "moves_rotate.h"
#include "moves_rotate_times.h"
#include "moves_reverse_rotate.h"
#include "moves_reverse_rotate_times.h"
#include "move.h"
#include "stack_sorting.h"
#include "stack_printing.h"
#include "error.h"

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

void	apply_move_list(t_state *state, t_move_type *moves)
{
	t_move_type	move;
	int			i;

	if (moves[0] == MOVE_NOTHING)
		ft_printf("Error\n");
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

t_move_type	get_move_type(char *str_move)
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

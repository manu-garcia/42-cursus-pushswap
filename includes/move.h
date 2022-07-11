/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:50:42 by manu              #+#    #+#             */
/*   Updated: 2022/07/11 12:08:12 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVE_H
# define MOVE_H

# include "push_swap.h"

typedef enum e_move_print_option {
	MOVE_PRINT_NOTHING = -1,
	MOVE_PRINT_TO_SCREEN = 1,
}	t_move_print_option;

typedef enum e_move_type {
	MOVE_NOTHING = 0,
	MOVE_SA,
	MOVE_SB,
	MOVE_SS,
	MOVE_PA,
	MOVE_PB,
	MOVE_RA,
	MOVE_RB,
	MOVE_RR,
	MOVE_RRA,
	MOVE_RRB,
	MOVE_RRR,
}	t_move_type;

typedef struct s_move
{
	long		n;
	int			size_a;
	int			size_b;
	int			index_in_a;
	int			number_moves_a;
	int			number_moves_b;
	int			number_moves_both;
	int			number_moves_total;
	t_move_type	move_type_a;
	t_move_type	move_type_b;
	t_move_type	move_type_both;
}	t_move;

t_move	*get_best_move(t_state *state);
int		apply_move(t_state *state, t_move_type move_type,
			int number_moves, t_move_print_option print_option);

#endif

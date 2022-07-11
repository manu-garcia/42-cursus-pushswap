/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 21:09:22 by manu              #+#    #+#             */
/*   Updated: 2022/07/11 14:58:12 by manugarc         ###   ########.fr       */
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

void	optimize_move(t_move *move)
{
	int	min;

	if (move->move_type_a == MOVE_RA && move->move_type_b == MOVE_RB)
		move->move_type_both = MOVE_RR;
	else if (move->move_type_a == MOVE_RRA && move->move_type_b == MOVE_RRB)
		move->move_type_both = MOVE_RRR;
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
	move->number_moves_total = move->number_moves_a
		+ move->number_moves_b + move->number_moves_both;
}

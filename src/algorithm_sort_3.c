/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_sort_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 21:07:19 by manu              #+#    #+#             */
/*   Updated: 2022/07/09 15:14:36 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack_node.h"
#include "move.h"

void	algorithm_sort_3(t_state *state)
{
    t_list *first_node;
    t_list *second_node;
    t_list *third_node;

    if (!state)
        return ;
    first_node = get_node_by_index(state->stack_a, 0);
    second_node = get_node_by_index(state->stack_a, 1);
    third_node = get_node_by_index(state->stack_a, 2);
    if (!first_node || !second_node || !third_node)
        return ;
    if (get_node_number(first_node) < get_node_number(second_node))
	{
		if (get_node_number(first_node) < get_node_number(third_node))
		{
            apply_move(state, MOVE_SA, 1, MOVE_PRINT_TO_SCREEN);
            apply_move(state, MOVE_RA, 1, MOVE_PRINT_TO_SCREEN);
		}
		else
            apply_move(state, MOVE_RRA, 1, MOVE_PRINT_TO_SCREEN);
	}
	else
	{
		if (get_node_number(first_node) > get_node_number(third_node))
		{
			if (get_node_number(second_node) > get_node_number(third_node))
			{
                apply_move(state, MOVE_SA, 1, MOVE_PRINT_TO_SCREEN);
                apply_move(state, MOVE_RRA, 1, MOVE_PRINT_TO_SCREEN);
			}
			else
                apply_move(state, MOVE_RA, 1, MOVE_PRINT_TO_SCREEN);
		}
		else
            apply_move(state, MOVE_SA, 1, MOVE_PRINT_TO_SCREEN);
	}
}

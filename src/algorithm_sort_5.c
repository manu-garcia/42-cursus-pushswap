/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_sort_5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 21:07:33 by manu              #+#    #+#             */
/*   Updated: 2022/07/11 15:05:50 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack_node.h"
#include "stack_sorting.h"
#include "algorithm_sort_3.h"
#include "move.h"
#include "move_apply.h"
#include "move_optimize.h"

static void	get_smallest_two_nodes(t_list *stack, t_list **smallest_node,
	t_list **second_smallest_node)
{
	if (!stack)
		return ;
	*smallest_node = NULL;
	*second_smallest_node = NULL;
	while (stack)
	{
		if (!(*smallest_node))
			(*smallest_node) = stack;
		else
		{
			if (!(*second_smallest_node))
				(*second_smallest_node) = stack;
			if (get_node_number(stack) < get_node_number((*smallest_node)))
			{
				(*second_smallest_node) = (*smallest_node);
				(*smallest_node) = stack;
			}
			else if (get_node_number(stack)
				< get_node_number((*second_smallest_node)))
				(*second_smallest_node) = stack;
		}
		stack = stack->next;
	}
}

void	algorithm_sort_5_2(t_state *state)
{
	t_list	*smallest[2];
	t_list	*aux;
	int		n_moves_to_b;
	int		n_rotates;

	get_smallest_two_nodes(state->stack_a, &smallest[0], &smallest[1]);
	n_moves_to_b = 0;
	while (n_moves_to_b < 2)
	{
		n_rotates = 0;
		aux = state->stack_a;
		while (aux)
		{
			if (get_node_number(aux) == get_node_number(smallest[0])
				|| get_node_number(aux) == get_node_number(smallest[1]))
			{
				apply_move(state, MOVE_RA, n_rotates, MOVE_PRINT_TO_SCREEN);
				apply_move(state, MOVE_PB, 1, MOVE_PRINT_TO_SCREEN);
				n_moves_to_b++;
				break ;
			}
			n_rotates++;
			aux = aux->next;
		}
	}
}

void	algorithm_sort_5(t_state *state)
{
	if (!state)
		return ;
	algorithm_sort_5_2(state);
	if (!is_stack_sorted(state->stack_a))
		algorithm_sort_3(state);
	if (get_node_number(state->stack_b) < get_node_number(state->stack_b->next))
		apply_move(state, MOVE_SB, 1, MOVE_PRINT_TO_SCREEN);
	apply_move(state, MOVE_PA, 1, MOVE_PRINT_TO_SCREEN);
	apply_move(state, MOVE_PA, 1, MOVE_PRINT_TO_SCREEN);
}

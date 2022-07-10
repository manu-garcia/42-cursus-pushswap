/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:15:35 by manu              #+#    #+#             */
/*   Updated: 2022/07/10 12:50:52 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"
#include "move.h"

static int	swap_stack_top_nodes(t_list **stack)
{
	t_list	*aux_node;

	if (!stack || !(*stack) || !(*stack)->next)
		return (0);
	aux_node = *stack;
	*stack = (*stack)->next;
	aux_node->next = (*stack)->next;
	(*stack)->next = aux_node;
	return (1);
}

int	swap_stack_a_top_nodes(t_state *state, t_move_print_option print_option)
{
	if (state && swap_stack_top_nodes(&state->stack_a))
	{
		if (print_option == MOVE_PRINT_TO_SCREEN)
			ft_printf("sa\n");
		return (1);
	}
	return (0);
}

int	swap_stack_b_top_nodes(t_state *state, t_move_print_option print_option)
{
	if (state && swap_stack_top_nodes(&state->stack_b))
	{
		if (print_option == MOVE_PRINT_TO_SCREEN)
			ft_printf("sb\n");
		return (1);
	}
	return (0);
}

int	swap_stack_a_and_b_top_nodes(t_state *state,
	t_move_print_option print_option)
{
	if (state
		&& swap_stack_top_nodes(&state->stack_a)
		&& swap_stack_top_nodes(&state->stack_b))
	{
		if (print_option == MOVE_PRINT_TO_SCREEN)
			ft_printf("ss\n");
		return (1);
	}
	return (0);
}

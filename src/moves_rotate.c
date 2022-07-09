/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:15:25 by manu              #+#    #+#             */
/*   Updated: 2022/07/09 15:10:07 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"
#include "move.h"

static int	rotate_stack(t_list **stack)
{
	t_list	*first_node;

	if (!stack || !(*stack) || ft_lstsize(*stack) < 2)
		return (0);
	first_node = *stack;
	ft_lstadd_back(stack, first_node);
	(*stack) = first_node->next;
	first_node->next = NULL;
	return (1);
}

int	rotate_stack_a(t_state *state, t_move_print_option print_option)
{
	if (state && rotate_stack(&state->stack_a))
	{
		if (print_option == MOVE_PRINT_TO_SCREEN)
			ft_printf("ra\n");
		return (1);
	}
	return (0);
}

int	rotate_stack_b(t_state *state, t_move_print_option print_option)
{
	if (state && rotate_stack(&state->stack_b))
	{
		if (print_option == MOVE_PRINT_TO_SCREEN)
			ft_printf("rb\n");
		return (1);
	}
	return (0);
}

int	rotate_stack_a_n_times(t_state *state, int n_times, t_move_print_option print_option)
{
	while (n_times--)
		if (!rotate_stack_a(state, print_option))
			return (0);
	return (1);
}

int	rotate_stack_b_n_times(t_state *state, int n_times, t_move_print_option print_option)
{
	while (n_times--)
		if (!rotate_stack_b(state, print_option))
			return (0);
	return (1);
}

int	rotate_stack_a_and_b(t_state *state, t_move_print_option print_option)
{
	if (state
		&& rotate_stack(&state->stack_a)
		&& rotate_stack(&state->stack_b))
	{
		if (print_option == MOVE_PRINT_TO_SCREEN)
			ft_printf("rr\n");
		return (1);
	}
	return (0);
}

int	rotate_stack_a_and_b_n_times(t_state *state, int n_times, t_move_print_option print_option)
{
	while (n_times--)
		if (!rotate_stack_a_and_b(state, print_option))
			return (0);
	return (1);
}

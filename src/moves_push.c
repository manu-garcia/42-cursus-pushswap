/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:12:21 by manu              #+#    #+#             */
/*   Updated: 2022/07/10 12:48:11 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"
#include "move.h"

static int	push_top(t_list **stack_from, t_list **stack_to)
{
	t_list	*first_from_node;

	if (!stack_from || !(*stack_from) || !stack_to)
		return (0);
	first_from_node = *stack_from;
	(*stack_from) = first_from_node->next;
	ft_lstadd_front(stack_to, first_from_node);
	return (1);
}

int	push_top_a_to_top_b(t_state *state, t_move_print_option print_option)
{
	if (state && push_top(&state->stack_a, &state->stack_b))
	{
		if (print_option == MOVE_PRINT_TO_SCREEN)
			ft_printf("pb\n");
		return (1);
	}
	return (0);
}

int	push_top_b_to_top_a(t_state *state, t_move_print_option print_option)
{
	if (state && push_top(&state->stack_b, &state->stack_a))
	{
		if (print_option == MOVE_PRINT_TO_SCREEN)
			ft_printf("pa\n");
		return (1);
	}
	return (0);
}

int	push_top_a_to_top_b_n_times(t_state *state, int n_times,
	t_move_print_option print_option)
{
	while (n_times--)
		if (!push_top_a_to_top_b(state, print_option))
			return (0);
	return (1);
}

int	push_top_b_to_top_a_n_times(t_state *state, int n_times,
	t_move_print_option print_option)
{
	while (n_times--)
		if (!push_top_b_to_top_a(state, print_option))
			return (0);
	return (1);
}

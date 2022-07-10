/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_reverse_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:15:16 by manu              #+#    #+#             */
/*   Updated: 2022/07/10 12:50:21 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"
#include "move.h"

static int	reverse_rotate_stack(t_list **stack)
{
	t_list	*current_node;
	t_list	*last_node;

	if (!stack || !(*stack) || ft_lstsize(*stack) < 2)
		return (0);
	last_node = ft_lstlast(*stack);
	current_node = *stack;
	while (current_node != NULL)
	{
		if (current_node->next == last_node)
		{
			ft_lstadd_front(stack, last_node);
			current_node->next = NULL;
			break ;
		}
		current_node = current_node->next;
	}
	return (1);
}

int	reverse_rotate_stack_a(t_state *state, t_move_print_option print_option)
{
	if (state && reverse_rotate_stack(&state->stack_a))
	{
		if (print_option == MOVE_PRINT_TO_SCREEN)
			ft_printf("rra\n");
		return (1);
	}
	return (0);
}

int	reverse_rotate_stack_b(t_state *state, t_move_print_option print_option)
{
	if (state && reverse_rotate_stack(&state->stack_b))
	{
		if (print_option == MOVE_PRINT_TO_SCREEN)
			ft_printf("rrb\n");
		return (1);
	}
	return (0);
}

int	reverse_rotate_stack_a_n_times(t_state *state, int n_times,
	t_move_print_option print_option)
{
	while (n_times--)
		if (!reverse_rotate_stack_a(state, print_option))
			return (0);
	return (1);
}

int	reverse_rotate_stack_b_n_times(t_state *state, int n_times,
	t_move_print_option print_option)
{
	while (n_times--)
		if (!reverse_rotate_stack_b(state, print_option))
			return (0);
	return (1);
}

int	reverse_rotate_stack_a_and_b(t_state *state,
	t_move_print_option print_option)
{
	if (state
		&& reverse_rotate_stack(&state->stack_a)
		&& reverse_rotate_stack(&state->stack_b))
	{
		if (print_option == MOVE_PRINT_TO_SCREEN)
			ft_printf("rrr\n");
		return (1);
	}
	return (0);
}

int	reverse_rotate_stack_a_and_b_n_times(t_state *state, int n_times,
	t_move_print_option print_option)
{
	while (n_times--)
		if (!reverse_rotate_stack_a_and_b(state, print_option))
			return (0);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:15:25 by manu              #+#    #+#             */
/*   Updated: 2022/06/20 19:15:27 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

static int	rotate_stack(t_list **stack)
{
	t_list	*first_node;

	if (!stack || !(*stack) || ft_lstsize(*stack) <= 2)
		return (0);
	first_node = *stack;
	ft_lstadd_back(stack, first_node);
	(*stack) = first_node->next;
	first_node->next = NULL;
	return (1);
}

int	rotate_stack_a(t_state *state)
{
	if (!state || !rotate_stack(&state->stack_a))
		return (0);
	ft_printf("ra\n");
	return (1);
}

int	rotate_stack_b(t_state *state)
{
	if (!state || !rotate_stack(&state->stack_b))
		return (0);
	ft_printf("rb\n");
	return (1);
}

int	rotate_stack_a_and_b(t_state *state)
{
	if (!state
		|| !rotate_stack(&state->stack_a)
		|| !rotate_stack(&state->stack_b))
	{
		return (0);
	}
	ft_printf("rr\n");
	return (1);
}

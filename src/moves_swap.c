/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:15:35 by manu              #+#    #+#             */
/*   Updated: 2022/06/20 19:15:36 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

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

void	swap_stack_a_top_nodes(t_state *state)
{
	if (!state)
		return ;
	if (swap_stack_top_nodes(&state->stack_a))
		ft_printf("sa\n");
}

void	swap_stack_b_top_nodes(t_state *state)
{
	if (!state)
		return ;
	if (swap_stack_top_nodes(&state->stack_b))
		ft_printf("sb\n");
}

void	swap_stack_a_and_b_top_nodes(t_state *state)
{
	if (!state)
		return ;
	if (swap_stack_top_nodes(&state->stack_a)
		&& swap_stack_top_nodes(&state->stack_b))
	{
		ft_printf("ss\n");
	}
}

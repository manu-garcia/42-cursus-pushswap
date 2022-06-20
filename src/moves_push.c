/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:12:21 by manu              #+#    #+#             */
/*   Updated: 2022/06/20 19:12:22 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

static void	push_top(t_list **stack_from, t_list **stack_to)
{
	t_list	*first_from_node;

	if (!stack_from || !stack_to)
		return ;
	first_from_node = *stack_from;
	(*stack_from) = first_from_node->next;
	ft_lstadd_front(stack_to, first_from_node);
}

void	push_top_a_to_top_b(t_state *state)
{
	if (!state)
		return ;
	push_top(&state->stack_a, &state->stack_b);
	ft_printf("pb\n");
}

void	push_top_b_to_top_a(t_state *state)
{
	if (!state)
		return ;
	push_top(&state->stack_b, &state->stack_a);
	ft_printf("pa\n");
}

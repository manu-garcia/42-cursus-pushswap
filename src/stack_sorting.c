/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 20:13:19 by manu              #+#    #+#             */
/*   Updated: 2022/06/25 16:32:26 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack_node.h"

int	is_stack_sorted(t_list *stack)
{
	while (stack && stack->next)
	{
		if (!is_valid_node(stack) || !is_valid_node(stack->next))
			return (0);
		if (get_node_number(stack) > get_node_number(stack->next))
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	is_stack_reversed_sorted(t_list *stack)
{
	while (stack && stack->next)
	{
		if (!is_valid_node(stack) || !is_valid_node(stack->next))
			return (0);
		if (get_node_number(stack) < get_node_number(stack->next))
			return (0);
		stack = stack->next;
	}
	return (1);
}

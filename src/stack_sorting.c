/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 20:13:19 by manu              #+#    #+#             */
/*   Updated: 2022/06/20 20:36:24 by manu             ###   ########.fr       */
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

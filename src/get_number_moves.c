/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_number_moves.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 21:18:20 by manu              #+#    #+#             */
/*   Updated: 2022/06/27 21:19:09 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> //exit
#include <stdio.h>
#include <limits.h>

#include "push_swap.h"
#include "ft_printf.h"
#include "error.h"
#include "moves_push.h"
#include "stack_printing.h"
#include "moves_swap.h"
#include "moves_rotate.h"
#include "moves_reverse_rotate.h"
#include "number_validation.h"
#include "stack_sorting.h"
#include "stack_node.h"
#include "libft.h"

int	get_distance_to_sorted_position(long n, t_list *stack, int stack_size)
{
	int		distance_to_sorted_position;
	int		distance_to_max_number;
	long	max;
	long	stack_node_number;

	if (!stack_size)
		return (0);
	if (stack_size == 1)
	{
		if (n > get_node_number(stack))
			return (0);
		else
			return (1);
	}
	max = INT_MIN;
	distance_to_max_number = 0;
	distance_to_sorted_position = 0;
	while (stack)
	{
		stack_node_number = get_node_number(stack);
		if (n > stack_node_number && stack_node_number > max)
		{
			distance_to_max_number = distance_to_sorted_position;
			max = stack_node_number;
		} else if (n < stack_node_number)
			break;
		distance_to_sorted_position++;
		stack = stack->next;
	}
	if (distance_to_sorted_position == stack_size)
	{
		if (distance_to_max_number)
			return (distance_to_max_number);
		return (0);
	}
	while (stack && n < get_node_number(stack))
	{
		distance_to_sorted_position++;
		if(stack->next && (get_node_number(stack) < get_node_number(stack->next)))
			return(distance_to_sorted_position);
		stack = stack->next;
	}
	if (distance_to_sorted_position == stack_size)
		return (stack_size);
	return (distance_to_sorted_position);
}

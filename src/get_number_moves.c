/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_number_moves.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 21:18:20 by manu              #+#    #+#             */
/*   Updated: 2022/07/12 12:50:42 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
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

typedef struct s_distance
{
	int		d;
	int		d_to_max;
	long	max;
	long	nbr;
	int		i;
}	t_distance;

static void	init_distance_struct(t_distance	*sd)
{
	sd->max = INT_MIN;
	sd->d_to_max = 0;
	sd->d = 0;
	sd->nbr = INT_MIN;
	sd->i = 0;
}

static int	basic_check(long n, t_list *stack, int stack_size, int *d)
{
	if (!stack_size)
	{
		(*d) = 0;
		return (1);
	}
	if (stack_size == 1)
	{
		if (n > get_node_number(stack))
		{
			(*d) = 0;
			return (1);
		}
		else
		{
			(*d) = 1;
			return (1);
		}
	}
	return (0);
}

static void	size_check(long n, t_list *stack, int stack_size, t_distance *sd)
{
	if (sd->d == stack_size && sd->d_to_max)
	{
		sd->d = sd->d_to_max;
		return ;
	}
	if (sd->d == stack_size && !sd->d_to_max)
	{
		sd->d = 0;
		return ;
	}
	while (stack && n < get_node_number(stack))
	{
		sd->d++;
		if (stack->next && (get_node_number(stack)
				< get_node_number(stack->next)))
			return ;
		stack = stack->next;
	}
	if (sd->d == stack_size)
	{
		sd->d = 0;
		return ;
	}
	return ;
}

int	get_distance_to_sorted_position(long n, t_list *stack, int stack_size)
{
	t_distance	sd;

	if (basic_check(n, stack, stack_size, &(sd.d)))
		return (sd.d);
	init_distance_struct(&sd);
	while (stack)
	{
		sd.nbr = get_node_number(stack);
		if (n < sd.nbr)
			break ;
		if (n > sd.nbr && sd.nbr > sd.max)
		{
			sd.d_to_max = sd.d;
			sd.max = sd.nbr;
		}
		sd.d++;
		stack = stack->next;
	}
	size_check(n, stack, stack_size, &sd);
	return (sd.d);
}

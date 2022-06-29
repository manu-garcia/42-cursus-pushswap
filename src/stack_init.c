/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:14:56 by manu              #+#    #+#             */
/*   Updated: 2022/06/27 21:54:15 by manu             ###   ########.fr       */
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
#include "get_number_moves.h"

static t_number	*str_to_number(char *str)
{
	t_number	*number;

	if (!is_valid_number(str))
		exit_with_error();
	number = (t_number *)malloc(sizeof(t_number));
	if (!number)
		exit_with_memory_error();
	number->n = ft_atoi(str);
	if (!is_valid_int(number->n))
		exit_with_error();
	return (number);
}

int	space_separated_numbers_to_stack(char *numbers, t_list **stack)
{
	int		index;
	char	**split;

	if (!stack || !numbers)
		exit_with_error();
	split = ft_split(numbers, ' ');
	if (!split)
		return (0);
	index = 0;
	while (split[index])
	{
		ft_lstadd_back(stack, ft_lstnew(str_to_number(split[index])));
		index++;
	}
	return (1);
}

int	get_numbers_from_input(int argc, char *argv[], t_state *state)
{
	int	index;

	if (!state)
		return (0);
	index = 1;
	while (index < argc)
	{
		space_separated_numbers_to_stack(argv[index], &state->stack_a);
		index++;
	}
	return (1);
}	

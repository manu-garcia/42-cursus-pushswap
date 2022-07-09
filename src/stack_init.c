/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:14:56 by manu              #+#    #+#             */
/*   Updated: 2022/07/09 18:56:16 by manugarc         ###   ########.fr       */
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
#include "get_number_moves.h"

static t_number	*str_to_number(char *str)
{
	t_number	*number;

	if (!is_valid_number(str))
		return NULL;
	number = (t_number *)ft_calloc(1, sizeof(t_number));
	if (!number)
		return NULL;
	number->n = ft_atoi(str);
	if (!is_valid_int(number->n))
		return NULL;
	return (number);
}

static int	is_duplicated_number(t_list *stack, t_number *number)
{
	while (stack)
	{
		if (get_node_number(stack) == number->n)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void free_split(char **split)
{
	int		index;

	if (!split)
		return ;
	index = 0;
	while (split[index])
	{
		free(split[index]);
		index++;
	}
	free(split);
}

int	space_separated_numbers_to_stack(char *numbers, t_list **stack)
{
	int		index;
	char	**split;
	t_number	*number;

	if (!stack || !numbers)
		return (0);
	split = ft_split(numbers, ' ');
	if (!split)
		return (0);
	index = 0;
	while (split[index])
	{
		number = str_to_number(split[index]);
		if (!number || is_duplicated_number(*stack, number))
		{
			free_split(split);
			return (0);
		}
		ft_lstadd_back(stack, ft_lstnew(number));
		index++;
	}
	free_split(split);
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
		if (!space_separated_numbers_to_stack(argv[index], &state->stack_a))
			exit_with_error(state);
		index++;
	}
	return (1);
}

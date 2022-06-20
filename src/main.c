/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:14:56 by manu              #+#    #+#             */
/*   Updated: 2022/06/20 19:14:57 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> //exit

#include "push_swap.h"
#include "ft_printf.h"
#include "error.h"
#include "moves_push.h"
#include "print_stack.h"
#include "moves_swap.h"
#include "moves_rotate.h"
#include "moves_reverse_rotate.h"

int	validate_input_parameters(int argc, char *argv[])
{
	if (argc <= 1)
		return (0);
	if (!argv[0] || !argv[1])
		return (0);
	return (1);
}

t_number	*str_to_number(char *str)
{
	t_number	*number;

	number = (t_number *)malloc(sizeof(t_number));
	if (!number)
		exit_with_memory_error();
	number->n = ft_atoi(str);
	return (number);
}

int	space_separated_numbers_to_stack(char *numbers, t_list **stack)
{
	int		index;
	char	**split;

	if (!stack || !numbers)
		return (0);
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

int	main(int argc, char *argv[])
{
	t_state	state;

	if (argc <= 1)
		exit(0);
	if (!validate_input_parameters(argc, argv))
		exit_with_error();
	if (!get_numbers_from_input(argc, argv, &state))
		exit_with_error();
	print_stack_a(&state);
	push_top_a_to_top_b(&state);
	push_top_a_to_top_b(&state);
	push_top_a_to_top_b(&state);
	push_top_a_to_top_b(&state);
	push_top_a_to_top_b(&state);
	// rotate_stack_a(&state);
	// rotate_stack_b(&state);
	// rotate_stack_a_and_b(&state);
	// reverse_rotate_stack_a(&state);
	// reverse_rotate_stack_b(&state);
	reverse_rotate_stack_a_and_b(&state);
	print_stack_a(&state);
	print_stack_b(&state);
	state.stack_a = NULL;
	state.stack_b = NULL;
	return (0);
}

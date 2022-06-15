/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 15:55:57 by manu              #+#    #+#             */
/*   Updated: 2022/06/15 19:50:36 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> //exit

#include "push_swap.h"
#include "ft_printf.h"
#include "error.h"

int	validate_input_parameters(int argc, char *argv[])
{
	if (argc <= 1)
		return (0);
	if (!argv[0] || !argv[1])
		return (0);
	return (1);
}

int	*str_to_number(char *str)
{
	int	*number;

	number = (int *)malloc(sizeof(int));
	(*number) = ft_atoi(str);
	return (number);
}

int	get_numbers_from_input(int argc, char *argv[], t_state *state)
{
	int	index;

	if (!state)
		return (0);
	index = 1;
	while (index < argc)
	{
		ft_lstadd_back(&state->stack_a, ft_lstnew(str_to_number(argv[index])));
		ft_printf("N = %s\n", argv[index]);
		index++;
	}
	return (1);
}

void	print_list_element_content(void *content)
{
	if (!content)
	{
		ft_printf("No content\n");
		return ;
	}
	ft_printf("Content = %d\n", *((int *)content));
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
	ft_printf("Push Swap ...\n");
	ft_lstiter(state.stack_a, print_list_element_content);
	state.stack_a = NULL;
	state.stack_b = NULL;
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 16:36:48 by manugarc          #+#    #+#             */
/*   Updated: 2022/07/09 18:55:45 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "push_swap.h"
#include "error.h"
#include "ft_printf.h"
#include "stack_free.h"

static void	exit_with_code(int code, t_state *state)
{
	free_state(state);
	exit(code);
}

void	exit_with_error_message(char *error_message, int exit_code, t_state *state)
{
	ft_printf("\n%s\n", error_message);
	exit_with_code(exit_code, state);
}

void	exit_with_internal_error(t_state *state)
{
	exit_with_error_message(
		"Internal error getting comunication state",
		ERROR_INTERNAL, state);
}

void	exit_with_memory_error(t_state *state)
{
	exit_with_error_message("Error not enough memory", ERROR_MEMORY, state);
}

void	exit_with_error(t_state *state)
{
	write(2, "Error\n", 6);
	exit_with_code(ERROR_GENERIC, state);
}

void	exit_without_error(t_state *state)
{
	exit_with_code(ERROR_NONE, state);
}

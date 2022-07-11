/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 16:36:48 by manugarc          #+#    #+#             */
/*   Updated: 2022/07/11 13:56:46 by manugarc         ###   ########.fr       */
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

int	exit_with_internal_error(t_state *state)
{
	ft_printf("\n%s\n", "Internal error getting comunication state");
	exit_with_code(ERROR_INTERNAL, state);
	return (1);
}

void	exit_with_memory_error(t_state *state)
{
	ft_printf("\n%s\n", "Error not enough memory");
	exit_with_code(ERROR_MEMORY, state);
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

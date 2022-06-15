/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 16:36:48 by manugarc          #+#    #+#             */
/*   Updated: 2022/06/15 16:40:08 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "error.h"
#include "ft_printf.h"

void	exit_with_error_message(char *error_message, int exit_code)
{
	ft_printf("\n%s\n", error_message);
	exit(exit_code);
}

void	exit_with_internal_error(void)
{
	exit_with_error_message(
		"Internal error getting comunication state",
		ERROR_INTERNAL);
}

void	exit_with_memory_error(void)
{
	exit_with_error_message(
		"Error not enough memory",
		ERROR_MEMORY);
}

void	exit_with_error(void)
{
	write(2, "Error\n", 6);
	exit(ERROR_GENERIC);
}

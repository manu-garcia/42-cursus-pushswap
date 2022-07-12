/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_reverse_rotate_times.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:15:16 by manu              #+#    #+#             */
/*   Updated: 2022/07/12 10:24:42 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"
#include "move.h"
#include "moves_reverse_rotate.h"

int	reverse_rotate_stack_a_n_times(t_state *state, int n_times,
	t_move_print_option print_option)
{
	while (n_times--)
		if (!reverse_rotate_stack_a(state, print_option))
			return (0);
	return (1);
}

int	reverse_rotate_stack_b_n_times(t_state *state, int n_times,
	t_move_print_option print_option)
{
	while (n_times--)
		if (!reverse_rotate_stack_b(state, print_option))
			return (0);
	return (1);
}

int	reverse_rotate_stack_a_and_b_n_times(t_state *state, int n_times,
	t_move_print_option print_option)
{
	while (n_times--)
		if (!reverse_rotate_stack_a_and_b(state, print_option))
			return (0);
	return (1);
}

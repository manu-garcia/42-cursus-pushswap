/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_reverse_rotate_times.h                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:12:44 by manu              #+#    #+#             */
/*   Updated: 2022/07/12 10:25:33 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVES_REVERSE_ROTATE_TIMES_H
# define MOVES_REVERSE_ROTATE_TIMES_H

# include "push_swap.h"
# include "move.h"

int	reverse_rotate_stack_a_n_times(t_state *state, int n_times,
		t_move_print_option print_option);
int	reverse_rotate_stack_b_n_times(t_state *state, int n_times,
		t_move_print_option print_option);
int	reverse_rotate_stack_a_and_b_n_times(t_state *state, int n_times,
		t_move_print_option print_option);

#endif

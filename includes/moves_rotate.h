/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_rotate.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:12:58 by manu              #+#    #+#             */
/*   Updated: 2022/07/09 14:37:36 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVES_ROTATE_H
# define MOVES_ROTATE_H

# include "push_swap.h"
# include "move.h"

int	rotate_stack_a(t_state *state, t_move_print_option print_option);
int	rotate_stack_b(t_state *state, t_move_print_option print_option);
int	rotate_stack_a_n_times(t_state *state, int n_times, t_move_print_option print_option);
int	rotate_stack_b_n_times(t_state *state, int n_times, t_move_print_option print_option);
int	rotate_stack_a_and_b(t_state *state, t_move_print_option print_option);
int	rotate_stack_a_and_b_n_times(t_state *state, int n_times, t_move_print_option print_option);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_push.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:11:55 by manu              #+#    #+#             */
/*   Updated: 2022/07/10 10:30:29 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVES_PUSH_H
# define MOVES_PUSH_H

# include "push_swap.h"
# include "move.h"

int	push_top_a_to_top_b(t_state *state, t_move_print_option print_option);
int	push_top_b_to_top_a(t_state *state, t_move_print_option print_option);
int	push_top_a_to_top_b_n_times(t_state *state, int n_times,
		t_move_print_option print_option);
int	push_top_b_to_top_a_n_times(t_state *state, int n_times,
		t_move_print_option print_option);

#endif

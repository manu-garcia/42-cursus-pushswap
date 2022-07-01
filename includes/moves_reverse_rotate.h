/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_reverse_rotate.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:12:44 by manu              #+#    #+#             */
/*   Updated: 2022/07/01 21:40:24 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVES_REVERSE_ROTATE_H
# define MOVES_REVERSE_ROTATE_H

# include "push_swap.h"

int     reverse_rotate_stack_a(t_state *state);
int     reverse_rotate_stack_b(t_state *state);
void	reverse_rotate_stack_a_n_times(t_state *state, int n_times);
void	reverse_rotate_stack_b_n_times(t_state *state, int n_times);
int     reverse_rotate_stack_a_and_b(t_state *state);
void	reverse_rotate_stack_a_and_b_n_times(t_state *state, int n_times);

#endif
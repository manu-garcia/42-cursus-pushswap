/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_rotate.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:12:58 by manu              #+#    #+#             */
/*   Updated: 2022/07/01 21:40:39 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVES_ROTATE_H
# define MOVES_ROTATE_H

# include "push_swap.h"

int		rotate_stack_a(t_state *state);
int		rotate_stack_b(t_state *state);
void	rotate_stack_a_n_times(t_state *state, int n_times);
void	rotate_stack_b_n_times(t_state *state, int n_times);
int		rotate_stack_a_and_b(t_state *state);
void	rotate_stack_a_and_b_n_times(t_state *state, int n_times);

#endif

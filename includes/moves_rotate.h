/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_rotate.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:12:58 by manu              #+#    #+#             */
/*   Updated: 2022/06/25 17:34:09 by manugarc         ###   ########.fr       */
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

#endif

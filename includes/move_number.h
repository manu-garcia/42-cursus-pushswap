/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_number.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 21:09:22 by manu              #+#    #+#             */
/*   Updated: 2022/07/11 14:57:41 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVE_NUMBER_H
# define MOVE_NUMBER_H

# include "push_swap.h"
# include "move.h"

void	get_number_moves_to_top_a(int actual_index, t_move *move);
void	get_number_moves_to_sort_in_b(t_state *state, t_move *move);

#endif

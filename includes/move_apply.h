/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_apply.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 21:09:22 by manu              #+#    #+#             */
/*   Updated: 2022/07/11 14:21:27 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVE_APPLY_H
# define MOVE_APPLY_H

# include "push_swap.h"
# include "move.h"

int	apply_move(t_state *state, t_move_type move_type, int n_moves,
		t_move_print_option print_option);

#endif

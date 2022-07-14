/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_apply.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 21:09:22 by manu              #+#    #+#             */
/*   Updated: 2022/07/14 17:07:33 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVE_APPLY_H
# define MOVE_APPLY_H

# include "push_swap.h"
# include "move.h"

t_move_type	get_move_type(char *str_move);
void		apply_move_list(t_state *state, t_move_type *moves);
int			apply_move(t_state *state, t_move_type move_type, int n_moves,
				t_move_print_option print_option);

#endif

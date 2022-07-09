/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_swap.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:13:21 by manu              #+#    #+#             */
/*   Updated: 2022/07/09 14:37:36 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVES_SWAP_H
# define MOVES_SWAP_H

# include "push_swap.h"
# include "move.h"

int	swap_stack_a_top_nodes(t_state *state, t_move_print_option print_option);
int	swap_stack_b_top_nodes(t_state *state, t_move_print_option print_option);
int	swap_stack_a_and_b_top_nodes(t_state *state, t_move_print_option print_option);

#endif

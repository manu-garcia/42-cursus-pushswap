/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_swap.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:13:21 by manu              #+#    #+#             */
/*   Updated: 2022/06/20 19:13:25 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVES_SWAP_H
# define MOVES_SWAP_H

# include "push_swap.h"

void	swap_stack_a_top_nodes(t_state *state);
void	swap_stack_b_top_nodes(t_state *state);
void	swap_stack_a_and_b_top_nodes(t_state *state);

#endif
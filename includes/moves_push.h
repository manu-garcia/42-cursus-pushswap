/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_push.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:11:55 by manu              #+#    #+#             */
/*   Updated: 2022/06/20 19:11:56 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVES_PUSH_H
# define MOVES_PUSH_H

# include "push_swap.h"

void	push_top_a_to_top_b(t_state *state);
void	push_top_b_to_top_a(t_state *state);

#endif
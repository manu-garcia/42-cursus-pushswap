/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_split.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 15:44:59 by manugarc          #+#    #+#             */
/*   Updated: 2022/07/14 17:03:33 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_SPLIT_H
# define CHECKER_SPLIT_H

# include "push_swap.h"

char		**get_split_moves(char *user_input, int *n_moves);
t_move_type	*split_to_moves(char **split, int n_moves);

#endif

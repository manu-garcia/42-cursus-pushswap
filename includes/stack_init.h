/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 21:45:22 by manu              #+#    #+#             */
/*   Updated: 2022/07/14 17:08:46 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_INIT_H
# define STACK_INIT_H

# include "push_swap.h"

int		get_numbers_from_input(int argc, char *argv[], t_state *state);
int		space_separated_numbers_to_stack(char *numbers, t_list **stack);
void	free_split(char **split);

#endif

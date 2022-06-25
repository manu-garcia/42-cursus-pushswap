/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorting.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 20:38:48 by manu              #+#    #+#             */
/*   Updated: 2022/06/25 16:33:18 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_SORTING_H
# define STACK_SORTING_H

# include "push_swap.h"

int	is_stack_sorted(t_list *stack);
int	is_stack_reversed_sorted(t_list *stack);

#endif

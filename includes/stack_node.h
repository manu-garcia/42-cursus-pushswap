/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_node.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 20:35:40 by manu              #+#    #+#             */
/*   Updated: 2022/07/10 10:31:29 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_NODE_H
# define STACK_NODE_H

# include "push_swap.h"

long	get_node_number(t_list *node);
int		is_valid_node(t_list *node);
t_list	*get_node_by_index(t_list *stack, int index);

#endif

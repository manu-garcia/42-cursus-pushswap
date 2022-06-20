/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 20:27:55 by manu              #+#    #+#             */
/*   Updated: 2022/06/20 20:28:04 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"
#include "error.h"

long	get_node_number(t_list *node)
{
	if (!node || !node->content)
	{
		ft_printf("Error getting node number\n");
		exit_with_internal_error();
	}
	return (((t_number *)node->content)->n);
}

int	is_valid_node(t_list *node)
{
	if (!node || !node->content)
	{
		ft_printf("Error invalid node\n");
		exit_with_internal_error();
		return (0);
	}
	return (1);
}

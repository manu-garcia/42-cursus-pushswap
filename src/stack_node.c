/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 20:27:55 by manu              #+#    #+#             */
/*   Updated: 2022/07/10 13:03:25 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"
#include "error.h"

long	get_node_number(t_list *node)
{
	return (((t_number *)node->content)->n);
}

int	is_valid_node(t_list *node)
{
	if (!node || !node->content)
		return (0);
	return (1);
}

t_list	*get_node_by_index(t_list *stack, int index)
{
	int	i;
	int	size;

	size = ft_lstsize(stack);
	if (index >= size)
		return (NULL);
	i = 0;
	while (stack)
	{
		if (i == index)
			return (stack);
		stack = stack->next;
		i++;
	}
	return (NULL);
}

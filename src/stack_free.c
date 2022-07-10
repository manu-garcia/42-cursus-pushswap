/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:14:56 by manu              #+#    #+#             */
/*   Updated: 2022/07/10 12:51:02 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "push_swap.h"

static void	free_node_content(void *content)
{
	if (!content)
		return ;
	free(content);
}

void	free_state(t_state *state)
{
	if (!state)
		return ;
	if (state->stack_a)
		ft_lstclear(&(state->stack_a), free_node_content);
	if (state->stack_b)
		ft_lstclear(&(state->stack_b), free_node_content);
}

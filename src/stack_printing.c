/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_printing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:15:44 by manu              #+#    #+#             */
/*   Updated: 2022/06/20 20:36:27 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

static void	print_stack_node_content(void *content)
{
	if (!content)
	{
		ft_printf("No content\n");
		return ;
	}
	ft_printf("Content = %d\n", ((t_number *)content)->n);
}

static void	print_stack(t_list *stack)
{
	if (!stack)
		ft_printf("Empty stack\n");
	ft_lstiter(stack, print_stack_node_content);
	ft_printf("\n");
}

void	print_stack_a(t_state *state)
{
	ft_printf("A stack ...\n");
	if (!state)
		ft_printf("Empty state\n");
	print_stack(state->stack_a);
}

void	print_stack_b(t_state *state)
{
	ft_printf("B stack ...\n");
	if (!state)
		ft_printf("Empty state\n");
	print_stack(state->stack_b);
}

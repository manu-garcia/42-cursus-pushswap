/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:13:50 by manu              #+#    #+#             */
/*   Updated: 2022/06/20 19:19:32 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_number
{
	long	n;
}	t_number;

typedef struct s_state
{
	t_list	*stack_a;
	t_list	*stack_b;
}	t_state;

#endif
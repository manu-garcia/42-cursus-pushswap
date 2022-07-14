/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:14:56 by manu              #+#    #+#             */
/*   Updated: 2022/07/14 17:03:23 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#include "push_swap.h"
#include "error.h"
#include "stack_sorting.h"
#include "stack_printing.h"
#include "stack_init.h"
#include "algorithm_2_best_a_and_b_move.h"
#include "algorithm_sort_3.h"
#include "algorithm_sort_5.h"
#include "move.h"
#include "move_apply.h"
#include "ft_printf.h"

char	**get_split_moves(char *user_input, int *n_moves)
{
	char		*trimmed;
	char		*tmp;
	char		**split;

	(*n_moves) = 0;
	trimmed = ft_strtrim(user_input, "[]");
	if (!trimmed)
		return (NULL);
	split = ft_split(trimmed, ',');
	free(trimmed);
	if (!split)
		return (NULL);
	while (split[(*n_moves)])
	{
		tmp = ft_strtrim(split[(*n_moves)], " ");
		free(split[(*n_moves)]);
		split[(*n_moves)] = tmp;
		(*n_moves)++;
	}
	return (split);
}

t_move_type	*split_to_moves(char **split, int n_moves)
{
	int			i;
	t_move_type	*moves;

	moves = (t_move_type *)ft_calloc(1, sizeof(t_move_type) * (n_moves + 1));
	i = 0;
	while (split[i] && n_moves--)
	{
		moves[i] = get_move_type(split[i]);
		i++;
	}
	return (moves);
}

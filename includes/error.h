/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 15:44:59 by manugarc          #+#    #+#             */
/*   Updated: 2022/07/10 10:22:11 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "push_swap.h"

# define PAUSE_SUCCESS		-1
# define FINAL_MESSAGE_CHAR	'\0'
# define ERROR_NONE			0
# define ERROR_MEMORY		1
# define ERROR_INTERNAL		2
# define ERROR_GENERIC		3

void	exit_with_error_message(char *error_message,
			int exit_code, t_state *state);
void	exit_with_internal_error(t_state *state);
void	exit_with_memory_error(t_state *state);
void	exit_with_error(t_state *state);
void	exit_without_error(t_state *state);

#endif

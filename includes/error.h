/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 15:44:59 by manugarc          #+#    #+#             */
/*   Updated: 2022/06/15 16:40:04 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define PAUSE_SUCCESS		-1
# define FINAL_MESSAGE_CHAR	'\0'
# define ERROR_MEMORY		1
# define ERROR_INTERNAL		2
# define ERROR_GENERIC		3

void	exit_with_error_message(char *error_message, int exit_code);
void	exit_with_internal_error(void);
void	exit_with_memory_error(void);
void	exit_with_error(void);

#endif

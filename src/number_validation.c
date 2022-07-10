/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_validation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 20:03:07 by manu              #+#    #+#             */
/*   Updated: 2022/07/10 12:50:58 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"

int	is_valid_number(char *number)
{
	int	len;
	int	is_valid;

	len = ft_strlen(number);
	if (!number || !len)
		return (0);
	if (*number == '-')
	{
		number += 1;
		len--;
	}
	is_valid = 0;
	while (*number)
	{
		if (!ft_isdigit(*number))
		{
			is_valid = 0;
			break ;
		}
		is_valid = 1;
		number += 1;
	}
	return (is_valid);
}

int	is_valid_int(long n)
{
	if (n > INT_MAX || n < INT_MIN)
		return (0);
	return (1);
}

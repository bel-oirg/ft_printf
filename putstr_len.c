/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:36:54 by bel-oirg          #+#    #+#             */
/*   Updated: 2023/12/07 10:35:47 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putstr_len(char *str)
{
	int	counter;

	counter = 0;
	if (!str)
		return (putstr_len("(null)"));
	while (*str)
		counter += write(1, str++, 1);
	return (counter);
}

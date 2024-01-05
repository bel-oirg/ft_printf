/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_len_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:36:50 by bel-oirg          #+#    #+#             */
/*   Updated: 2023/12/06 17:44:09 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putnbr_len_u(unsigned int lnbr, int base, int upper)
{
	int	counter;

	counter = 0;
	if (lnbr < (unsigned int)base)
	{
		if (upper)
			counter += putchar_len(HEX_UP[lnbr]);
		else
			counter += putchar_len(HEX[lnbr]);
	}
	else
	{
		counter += putnbr_len(lnbr / base, base, upper);
		return (counter + putnbr_len(lnbr % base, base, upper));
	}
	return (counter);
}

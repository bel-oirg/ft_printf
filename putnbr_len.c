/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:36:52 by bel-oirg          #+#    #+#             */
/*   Updated: 2023/12/06 17:40:54 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putnbr_len(long int lnbr, int base, int upper)
{
	int	counter;

	counter = 0;
	if (lnbr < 0)
	{
		lnbr = -lnbr;
		counter += putchar_len('-');
	}
	if (lnbr < base)
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

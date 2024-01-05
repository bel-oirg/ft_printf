/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_len_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:36:47 by bel-oirg          #+#    #+#             */
/*   Updated: 2023/12/06 23:35:54 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putnbr_len_p(unsigned long lnbr, int base, int upper)
{
	int	counter;

	counter = 0;
	if (!lnbr)
		return (putstr_len("0x0"));
	counter += putstr_len("0x");
	if (lnbr < (unsigned long)base)
		counter += putchar_len(HEX[lnbr]);
	else
	{
		counter += putnbr_len(lnbr / base, base, upper);
		return (counter + putnbr_len(lnbr % base, base, upper));
	}
	return (counter);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:47:04 by bel-oirg          #+#    #+#             */
/*   Updated: 2023/12/10 12:27:28 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_format(const char *ext, va_list ap)
{
	if (*ext == 's')
		return (putstr_len(va_arg(ap, char *)));
	else if (*ext == 'c')
		return (putchar_len(va_arg(ap, int)));
	else if (*ext == 'd' || *ext == 'i')
		return (putnbr_len(va_arg(ap, int), 10, 0));
	else if (*ext == 'u')
		return (putnbr_len_u(va_arg(ap, unsigned int), 10, 0));
	else if (*ext == 'x')
		return (putnbr_len_u(va_arg(ap, unsigned int), 16, 0));
	else if (*ext == 'X')
		return (putnbr_len_u(va_arg(ap, unsigned int), 16, 1));
	else if (*ext == 'p')
		return (putnbr_len_p(va_arg(ap, long int), 16, 0));
	else if (*ext)
		return (write(1, ext, 1));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	int			len;

	if (write(1, "", 0) < 0)
		return (-1);
	len = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
			len += check_format(++format, ap);
		else
			len += write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (len);
}

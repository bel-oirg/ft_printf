/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:46:56 by bel-oirg          #+#    #+#             */
/*   Updated: 2023/12/10 12:26:48 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# define HEX "0123456789abcdef"
# define HEX_UP "0123456789ABCDEF"

int	putchar_len(char c);
int	putstr_len(char *str);
int	putnbr_len(long int lnbr, int base, int upper);
int	putnbr_len_u(unsigned int lnbr, int base, int upper);
int	putnbr_len_p(unsigned long lnbr, int base, int upper);
int	ft_printf(const char *format, ...);

#endif

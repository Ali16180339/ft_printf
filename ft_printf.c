/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agokcek <agokcek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:52:55 by agokcek           #+#    #+#             */
/*   Updated: 2024/12/08 15:48:11 by agokcek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

stattic int	check(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int), 10, "0123456789"));
	else if (c == 'u')
		return (ft_nbrbase(va_arg(args, unsigned int), 10, "0123456789"));
	else if (c == 'p')
		return (ft_pointer(va_arg(args, void *)));
	else if (c == 'x')
		return (ft_nbrbase(va_arg(args, unsigned int), 16, "0123456789abcdef"));
	else if (c == 'X')
		return (ft_nbrbase(va_arg(args, unsigned int), 16, "0123456789ABCDEF"));
	else if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list			args;
	unsigned int	i;
	unsigned int	result;

	va_start(args, format);
	i = 0;
	result = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			result += check(format[++i], args);
			i++;
		}
		else
			result += ft_putchar(format[i++]);
	}
	va_end(args);
	return (result);
}

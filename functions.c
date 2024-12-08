/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agokcek <agokcek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:52:44 by agokcek           #+#    #+#             */
/*   Updated: 2024/12/08 15:54:00 by agokcek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	t_ull	x;

	x = 0;
	if (s == NULL)
		return (ft_putstr("(null)"));
	while (s[x] != '\0')
		write(1, &s[x++], 1);
	return (x);
}

int	ft_nbrbase(t_ull n, int base, const char *digits)
{
	int	count;

	count = 0;
	if (n >= (t_ull)base)
		count += ft_nbrbase(n / base, base, digits);
	count += ft_putchar(digits[n % base]);
	return (count);
}

int	ft_pointer(void *ptr)
{
	if (ptr == NULL)
		return (ft_putstr("(nil)"));
	return (ft_putstr("0x") + ft_nbrbase((t_ull)ptr, 16, "0123456789abcdef"));
}

int	ft_putnbr(intmax_t n, int base, const char *digits)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count += ft_putchar('-');
		return (count + ft_nbrbase(-n, base, digits));
	}
	return (count + ft_nbrbase(n, base, digits));
}

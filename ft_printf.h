/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agokcek <agokcek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:52:51 by agokcek           #+#    #+#             */
/*   Updated: 2024/12/07 17:52:53 by agokcek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

typedef unsigned long long	t_ull;

int	ft_printf(const char *format, ...);
int	ft_putchar(char c);
int ft_putstr(char *s);
int ft_pointer(void *ptr);
int	ft_putnbr(intmax_t n,int base,const char *digits);
int ft_nbrbase(t_ull n,int base, const char *digits);

#endif
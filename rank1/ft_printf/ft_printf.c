/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:53:40 by karocha-          #+#    #+#             */
/*   Updated: 2024/06/20 17:03:37 by karocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[++i])
		count += write(1, &str[i], 1);
	return (count);
}

int	parse_format(char specifier, va_list jorge)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_putchar(va_arg(jorge, int));
	else if (specifier == 's')
		count += ft_putstr(va_arg(jorge, char *));
	else if (specifier == 'p')
		count += num_unsigned((unsigned long long)va_arg(jorge, void *), 16, 0,
				specifier);
	else if (specifier == 'd' || specifier == 'i')
		count += number_base_signed((long)va_arg(jorge, int), 10, 0);
	else if (specifier == 'u')
		count += num_unsigned(va_arg(jorge, unsigned int), 10, 0, specifier);
	else if (specifier == 'x')
		count += num_unsigned((long)va_arg(jorge, unsigned int), 16, 0,
				specifier);
	else if (specifier == 'X')
		count += num_unsigned((long)va_arg(jorge, unsigned int), 16, 1,
				specifier);
	else if (specifier == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	jorge;
	int		i;
	int		count;

	i = -1;
	count = 0;
	va_start(jorge, s);
	while (s[++i])
	{
		if (s[i] == '%')
		{
			if (!s[i + 1])
				return (-1);
			count += parse_format(s[++i], jorge);
		}
		else
			count += write(1, &s[i], 1);
	}
	va_end(jorge);
	return (count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:52:10 by karocha-          #+#    #+#             */
/*   Updated: 2024/06/18 18:34:16 by karocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *s, ...);
int	number_base_signed(long nbr, int base, int upperbase);
int	num_unsigned(unsigned long long nbr, unsigned int base,
		int upperbase, char specifier);
#endif
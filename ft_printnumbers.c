/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnumbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpavon-g <lpavon-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 23:24:12 by lpavon-g          #+#    #+#             */
/*   Updated: 2023/02/22 17:57:27 by lpavon-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// %d: Print a decimal number
// %i: Print an integer in base 10
void	ft_number(int number, int *len)
{
	if (number < 0)
	{
		if (number == -2147483648)
			ft_putstring("-2147483648", len);
		else
		{
			number *= -1;
			ft_putchar('-', len);
		}
	}
	if (number > 9)
	{
		ft_number(number / 10, len);
		ft_number(number % 10, len);
	}
	else if (number <= 9 && number >= 0)
		ft_putchar(number +48, len);
}

// %u: Print an unsigned decimal number
void	ft_unsigned_int(unsigned int u, int *len)
{
	if (u > 9)
	{
		ft_unsigned_int(u / 10, len);
		ft_unsigned_int(u % 10, len);
	}
	else if (u <= 9)
		ft_putchar(u +48, len);
}

// %x: Print a number in hexadecimal [lowercase]
// %X: Print a number in hexadecimal [uppercase]
void	ft_hexadecimal(unsigned long n, int *len, char x)
{
	if (n >= 16)
	{
		ft_hexadecimal(n / 16, len, x);
		ft_hexadecimal(n % 16, len, x);
	}
	if (n < 16)
	{
		if (n < 10)
			ft_putchar(n +48, len);
		else
		{
			if (x == 'x')
				ft_putchar(n +87, len);
			if (x == 'X')
				ft_putchar(n +55, len);
		}
	}
}

// %p: Print a pointer address
void	ft_pointer(void *n, int *len)
{
	ft_putstring("0x", len);
	ft_hexadecimal((unsigned long long)n, len, 'x');
}

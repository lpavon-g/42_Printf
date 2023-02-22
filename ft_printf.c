/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpavon-g <lpavon-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:45:36 by lpavon-g          #+#    #+#             */
/*   Updated: 2023/02/22 18:01:30 by lpavon-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// The acepted format specifiers are:
// %c: Print a single character.
// %s: Print a string of characters.
// %d: Print a decimal number.
// %i: Print an integer in base 10.
// %u: Print an unsigned decimal number.
// %p: Print a pointer address.
// %x: Print a number in hexadecimal [lowercase].
// %X: Print a number in hexadecimal [uppercase].
// %%: Print a percent sign.
void	ft_checker(char s, int *len, va_list arg)
{
	if (s == 'c')
		ft_putchar(va_arg(arg, int), len);
	else if (s == 's')
		ft_putstring(va_arg(arg, char *), len);
	else if (s == 'd' || s == 'i')
		ft_number(va_arg(arg, int), len);
	else if (s == 'u')
		ft_unsigned_int(va_arg(arg, unsigned int), len);
	else if (s == 'p')
		ft_pointer(va_arg(arg, void *), len);
	else if (s == 'x')
		ft_hexadecimal(va_arg(arg, unsigned int), len, 'x');
	else if (s == 'X')
		ft_hexadecimal(va_arg(arg, unsigned int), len, 'X');
	else if (s == '%')
		ft_putchar('%', len);
}

int	ft_printf(const char *string, ...)
{
	va_list	arg;
	int		i;
	int		len;

	va_start(arg, string);
	i = 0;
	len = 0;
	while (string[i] != '\0')
	{
		if (string[i] == '%')
		{
			i++;
			ft_checker(string[i], &len, arg);
		}
		else
			ft_putchar((char)string[i], &len);
		i++;
	}
	va_end(arg);
	return (len);
}

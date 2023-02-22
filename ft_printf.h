/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpavon-g <lpavon-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:58:04 by lpavon-g          #+#    #+#             */
/*   Updated: 2023/02/22 17:39:45 by lpavon-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Standard C Libraries
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

// Protoypes
int		ft_printf(const char *string, ...);
void	ft_checker(char s, int *len, va_list arg);

void	ft_putchar(char s, int *len);
void	ft_putstring(char *s, int *len);

void	ft_number(int n, int *len);
void	ft_unsigned_int(unsigned int u, int *len);
void	ft_pointer(void *n, int *len);
void	ft_hexadecimal(unsigned long n, int *len, char x);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpavon-g <lpavon-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 20:40:22 by lpavon-g          #+#    #+#             */
/*   Updated: 2023/02/22 17:54:53 by lpavon-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//'%c' print a single character
void	ft_putchar(char s, int *len)
{
	write (1, &s, 1);
	(*len)++;
}

//'%s' print a string
void	ft_putstring(char *s, int *len)
{
	int	i;

	i = 0;
	if (!s)
		ft_putstring("(null)", len);
	else
	{
		while (s[i])
		{
			ft_putchar(s[i], len);
			i++;
		}
	}
}

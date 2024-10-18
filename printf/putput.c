/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putput.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonsat <lmonsat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 23:33:14 by lmonsat           #+#    #+#             */
/*   Updated: 2024/03/10 23:37:34 by lmonsat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int nb)
{
	long int	n;
	int			len;

	len = 0;
	n = nb;
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
		len++;
	}
	if (n < 10)
	{
		ft_putchar(n + '0');
		len++;
	}
	else
	{
		len += ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
		len++;
	}
	return (len);
}

int	ft_putnbr_unsigned(unsigned int nb)
{
	int	result;
	int	len;

	len = 0;
	result = 0;
	if (nb < 10)
	{
		ft_putchar(nb + '0');
		len = 1;
	}
	else
	{
		result = (nb / 10);
		len = ft_putnbr_unsigned(result);
		ft_putchar(nb % 10 + '0');
		len++;
	}
	return (len);
}

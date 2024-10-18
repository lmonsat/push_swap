/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converto.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonsat <lmonsat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 23:35:01 by lmonsat           #+#    #+#             */
/*   Updated: 2024/03/11 00:08:47 by lmonsat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_itohex(unsigned long int nb)
{
	unsigned long int	n;
	char				result;
	int					len;

	len = 0;
	n = 0;
	if (nb >= 16)
		len += ft_itohex(nb / 16);
	n = nb % 16;
	if (n < 10)
		result = '0' + n;
	else
		result = 'a' + n - 10;
	ft_putchar(result);
	len++;
	return (len);
}

int	ft_itohex_but_in_majuscule(unsigned long int nb)
{
	unsigned long int	n;
	char				result;
	int					len;

	len = 0;
	n = 0;
	if (nb >= 16)
	{
		len += ft_itohex_but_in_majuscule(nb / 16);
	}
	n = nb % 16;
	if (n < 10)
	{
		result = '0' + n;
	}
	else
	{
		result = 'A' + n - 10;
	}
	ft_putchar(result);
	len++;
	return (len);
}

int	ft_ptrtohex(void *ptr)
{
	uintptr_t	convert_ptr;
	int			len;

	len = 0;
	if (ptr == 0)
		return (ft_putstr("(nil)"));
	convert_ptr = (uintptr_t)ptr;
	ft_putstr("0x");
	len += 2;
	len += ft_itohex(convert_ptr);
	return (len);
}

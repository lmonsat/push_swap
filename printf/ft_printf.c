/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonsat <lmonsat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:41:27 by lmonsat           #+#    #+#             */
/*   Updated: 2024/03/11 00:04:52 by lmonsat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_spec_char(const char *str, int i, va_list args)
{
	char	ch;
	int		str_len;

	str_len = 0;
	ch = str[i];
	if (ch == 'c')
		str_len = ft_putchar(va_arg(args, int));
	else if (ch == '%')
		str_len = ft_putchar('%');
	else if (ch == 's')
		str_len = ft_putstr(va_arg(args, char *));
	else if (ch == 'p')
		str_len = ft_ptrtohex(va_arg(args, void *));
	else if (ch == 'd' || ch == 'i')
		str_len = ft_putnbr(va_arg(args, int));
	else if (ch == 'u')
		str_len = ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (ch == 'x')
		str_len = ft_itohex(va_arg(args, unsigned int));
	else if (ch == 'X')
		str_len = ft_itohex_but_in_majuscule(va_arg(args, unsigned int));
	return (str_len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;
	int		i;
	int		str_len;

	va_start(args, str);
	i = 0;
	len = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			str_len = ft_spec_char(str, i, args);
			len += str_len;
		}
		else
		{
			write(1, &str[i], 1);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}

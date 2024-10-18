/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonsat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 01:56:48 by lmonsat           #+#    #+#             */
/*   Updated: 2024/03/02 02:11:03 by lmonsat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_atoi(const char *str)
{
	int	n;
	int	is_negative;
	int	i;

	n = 0;
	is_negative = 0;
	i = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || (str[i] == ' ')
		|| (str[i] == '\n') || (str[i] == '\v') || (str[i] == '\f'))
		i++;
	if (str[i] == '-')
	{
		is_negative = 1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		n = n * 10 + str[i++] - '0';
	if (is_negative)
		return (-n);
	else
		return (n);
}
/*#include <stdio.h>
int main()
{
    const char *string = " \v-125698";

    printf("value (ft_atoi) : %d\n", ft_atoi(string));
    printf("value (std atoi): %d\n", atoi(string));
}*/

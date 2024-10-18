/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonsat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 02:58:38 by lmonsat           #+#    #+#             */
/*   Updated: 2024/03/02 02:59:20 by lmonsat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
/*#include <ctype.h>
#include <stdio.h>
int main ()
{
    int test = 'A';
    printf("case 1, is ascii :\n");
    printf("value : %d\n", ft_isascii(test));
    printf("value (isascii) : %d\n\n", isascii(test));

    int test2 = 128;
    printf("case 2, non ascii :\n");
    printf("value : %d\n", ft_isascii(test2));
    printf("value (isascii) : %d", isascii(test2));
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonsat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 03:00:05 by lmonsat           #+#    #+#             */
/*   Updated: 2024/03/02 03:00:44 by lmonsat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
/*#include <ctype.h>
#include <stdio.h>
int main ()
{
    int test = 'A';
    printf("case 1, is printable :\n");
    printf("value : %d\n", ft_isprint(test));
    printf("value (isprint) : %d\n\n", isprint(test));

    int test2 = '\n';
    printf("case 2, non printable :\n");
    printf("value : %d\n", ft_isprint(test2));
    printf("value (isprint) : %d\n\n", isprint(test2));

    int test3 = 9;
    printf("case 3, non printable :\n");
    printf("value : %d\n", ft_isprint(test3));
    printf("value (isprint) : %d", isprint(test3));
}*/

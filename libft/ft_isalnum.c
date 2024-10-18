/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonsat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 02:13:29 by lmonsat           #+#    #+#             */
/*   Updated: 2024/03/02 02:14:35 by lmonsat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isalnum(int c)
{
	if (((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		|| (c >= '0' && c <= '9'))
		return (1);
	return (0);
}
/*#include <ctype.h>
#include <stdio.h>
int main ()
{
    int test = 'A';
    printf("case 1, is alpha :\n");
    printf("value : %d\n", ft_isalnum(test));
    printf("value (isalnum) : %d\n\n", isalnum(test));

    test = '9';
    printf("case 2, is num :\n");
    printf("value : %d\n", ft_isalnum(test));
    printf("value (isalnum) : %d\n\n", isalnum(test));

    test = '\t';
    printf("case 3, non alphanumeric :\n");
    printf("value : %d\n", ft_isalnum(test));
    printf("value (isalnum) : %d\n", isalnum(test));

}*/

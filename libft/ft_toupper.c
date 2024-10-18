/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonsat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 02:01:38 by lmonsat           #+#    #+#             */
/*   Updated: 2024/03/04 02:02:03 by lmonsat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
/*#include <ctype.h>
#include <stdio.h>
int main ()
{
    int test = 'a';
    printf("case 1, is alpha & lower :\n");
    printf("value : %d\n", ft_toupper(test));
    printf("value (toupper) : %d\n", toupper(test));
    test = toupper(test);
    printf("upper character : %c\n\n", (char)test);

    int test2 = '\t';
    printf("case 2, non alpha :\n");
    printf("value : %d\n", ft_toupper(test2));
    printf("value (toupper) : %d", toupper(test2));
}*/

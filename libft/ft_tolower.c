/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonsat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 02:01:07 by lmonsat           #+#    #+#             */
/*   Updated: 2024/03/04 02:02:43 by lmonsat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}
/*#include <ctype.h>
#include <stdio.h>
int main ()
{
    int test = 'A';
    printf("case 1, is alpha & upper :\n");
    printf("value : %d\n", ft_tolower(test));
    printf("value (tolower) : %d\n", tolower(test));
    test = tolower(test);
    printf("lower character : %c\n\n", (char)test);

    int test2 = '\t';
    printf("case 2, non alpha :\n");
    printf("value : %d\n", ft_tolower(test2));
    printf("value (tolower) : %d", tolower(test2));
}*/

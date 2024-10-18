/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonsat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 04:11:26 by lmonsat           #+#    #+#             */
/*   Updated: 2024/03/02 04:19:16 by lmonsat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;

	p = s;
	while (n != 0)
	{
		*p++ = (unsigned char)c;
		n--;
	}
	return (s);
}
/*
#include <stdio.h>
int main() {
    char test[10];

    memset(test, 'A', sizeof(test));
    printf("Using standard memset: %s\n", test);

    ft_memset(test, 'B', sizeof(test));
    printf("Using custom memset: %s\n", test);

    return 0;
}*/

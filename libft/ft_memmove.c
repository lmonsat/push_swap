/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonsat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 04:08:43 by lmonsat           #+#    #+#             */
/*   Updated: 2024/03/04 12:21:31 by lmonsat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*destm;
	const char	*srcm;

	destm = dest;
	srcm = src;
	if (destm < srcm)
	{
		while (n > 0)
		{
			*destm++ = *srcm++;
			n--;
		}
	}
	else if (destm > srcm)
	{
		destm += n;
		srcm += n;
		while (n > 0)
		{
			*--destm = *--srcm;
			n--;
		}
	}
	return (dest);
}
/*#include <stdio.h>
int main()
{
    // Test 1: Les zones ne se chevauchent pas
    char source1[] = "ceci est un test";
    char destination1[20];
    size_t n1 = sizeof(source1);

    ft_memmove(destination1, source1, n1);
    printf("Test 1:\n");
    printf("Source: %s\n", source1);
    printf("Destination: %s\n", destination1);
    printf("\n");

    // Test 2: Les zones se chevauchent
    char source2[] = "ceci est un test";
    char destination2[20];
    size_t n2 = 6;  // Sélectionne une partie de la chaîne
    ft_memmove(destination2, source2 + 5, n2);
    printf("Test 2:\n");
    printf("Source: %s\n", source2);
    printf("Destination: %s\n", destination2);
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonsat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 01:22:07 by lmonsat           #+#    #+#             */
/*   Updated: 2024/03/04 01:34:16 by lmonsat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;

	dest_len = 0;
	while (dst[dest_len] && dest_len < size)
		dest_len++;
	src_len = ft_strlen(src);
	i = 0;
	while (src[i] && dest_len + i + 1 < size)
	{
		dst[dest_len + i] = src[i];
		i++;
	}
	if (dest_len < size)
		dst[dest_len + i] = '\0';
	return (dest_len + src_len);
}
/*#include <stdio.h>
int main() 
{
    char dest1[20] = "Hello, ";
    char source1[] = "World!";

    printf("dest1: %s\n", dest1);
    printf("source1: %s\n", source1);
    size_t result1 = ft_strlcat(dest1, source1, sizeof(dest1));
    printf("concatenate value (avec ft_strlcat): %ld\n", result1);
    printf("new dest1: %s\n", dest1);
    printf("source1: %s\n\n", source1);

    char dest2[20] = "Hello, ";
    char source2[] = "World!";

    printf("dest2: %s\n", dest2);
    printf("source2: %s\n", source2);
    size_t result2 = strlcat(dest2, source2, sizeof(dest2));
    printf("concatenate value (avec strlcat): %ld\n", result2);
    printf("new dest2: %s\n", dest2);
    printf("source2: %s\n", source2);

    if (strcmp(dest1, dest2) == 0 && result1 == result2)
    {
        printf("Results match!\n");

    }
    else
    {
        printf("Results differ.\n");
    }
 

    return 0;
}*/

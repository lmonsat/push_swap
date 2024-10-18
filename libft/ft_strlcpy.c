/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonsat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:27:04 by lmonsat           #+#    #+#             */
/*   Updated: 2024/03/04 01:50:39 by lmonsat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	i = 0;
	while (i + 1 < size && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	if (size > 0)
		dst[i] = '\0';
	return (src_len);
}
/*#include <stdio.h>
int main() {
    char source[] = "Hello, World!";
    char destination[20];

    printf("Source: %s\n", source);
    printf(" lenght : %ld\n", ft_strlcpy(destination, source, 10));
    printf("Destination (copie avec ft_strlcpy): %s\n", destination);

    char source2[] = "Hello, World!";
    char destination2[20];
    printf("Source: %s\n", source);
    printf(" lenght : %ld\n", strlcpy(destination2, source2, 10));
    printf("Destination (copie avec strcpy): %s\n", destination);

    return 0;
}*/

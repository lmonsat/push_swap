/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonsat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 01:47:46 by lmonsat           #+#    #+#             */
/*   Updated: 2024/03/04 01:48:34 by lmonsat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0') && i < n - 1)
		i++;
	if (n == 0)
		return (0);
	else
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*#include <stdio.h>
int main()
{
    char *string1 = "Hello, World!";
    char *string2 = "World!";
    size_t n = 6;

    printf("Case 1, string1 > string2 :\n");
    printf("value : %d\n", ft_strncmp(string1, string2, n));
    printf("value : %d\n\n", strncmp(string1, string2, n));

    string1 = "World!";
    string2 = "Hello, World!";

    printf("Case 2, string1 < string2 :\n");
    printf("value : %d\n", ft_strncmp(string1, string2, n));
    printf("value : %d\n\n", strncmp(string1, string2, n));

    string1 = "Hello, World!";
    string2 = "Hello, World!";

    printf("Case 3, string1 = string2 :\n");
    printf("value : %d\n", ft_strncmp(string1, string2, n));
    printf("value : %d\n", strncmp(string1, string2, n));
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonsat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 01:01:26 by lmonsat           #+#    #+#             */
/*   Updated: 2024/03/04 01:09:59 by lmonsat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		if ((char)c == s[i])
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
/*#include <stdio.h>
int main()
{
    char src[] = "test";
    char src2[] = "dest";
    char src3[] = "set";

    printf("character : %p\n", ft_strchr(src, 'e'));
    printf("character : %p\n", strchr(src2, 'e'));
    printf("character : %p\n", strchr(src, 'e'));
}*/

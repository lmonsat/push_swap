/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonsat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 01:55:47 by lmonsat           #+#    #+#             */
/*   Updated: 2024/03/04 01:56:56 by lmonsat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	if (s == NULL)
		return (NULL);
	i = ft_strlen(s);
	if ((char)c == '\0')
		return ((char *)&s[i]);
	while (i > 0)
	{
		i--;
		if ((char)c == s[i])
			return ((char *)&s[i]);
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
    //char src3[] = "set";

    printf("character : %p\n", ft_strrchr(src, 'e'));
    printf("character : %p\n", strrchr(src2, 'e'));
    printf("character : %p\n", strrchr(src, 'e'));
}*/

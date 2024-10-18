/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonsat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 01:16:42 by lmonsat           #+#    #+#             */
/*   Updated: 2024/03/04 01:36:44 by lmonsat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*copy;
	int		i;
	size_t	len;

	len = ft_strlen(s);
	copy = (char *) malloc((len + 1) * sizeof(char));
	i = 0;
	if (copy == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
/*#include <stdio.h>
int main()
{
    char source1[] = "hello";
    printf("Source1: %s\n", source1);
    char *test1 = ft_strdup(source1);
    printf("returned value1: %s\n", test1);
    free(test1);

    char source2[] = "world";
    printf("Source2: %s\n", source2);
    char *test2 = strdup(source2);
    printf("returned value2: %s\n", test2);
    free(test2);
}*/

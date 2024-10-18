/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonsat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 01:39:17 by lmonsat           #+#    #+#             */
/*   Updated: 2024/03/04 01:52:43 by lmonsat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new_string;
	unsigned int	i;

	i = 0;
	new_string = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (new_string == NULL)
		return (NULL);
	ft_strcpy(new_string, s);
	while (new_string[i])
	{
		new_string[i] = f(i, new_string[i]);
		i++;
	}
	return (new_string);
}
/*#include <stdio.h>
int main()
{
    const char string[] = "Hello, World!";
    printf("original string : %s\n", string);

    char *result = ft_strmapi(string, &ft_strupcase);
    printf("result : %s\n", result);

    free(result);

    return 0;
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shawn <shawn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 12:32:02 by shapetit          #+#    #+#             */
/*   Updated: 2025/11/11 17:43:54 by shawn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == '\0' && c == '\0')
		return ((char *) &s[i]);
	return (NULL);
}

// #include <stdio.h>
// int main()
// {
// 	char a[] = "hello";
// 	printf("%s\n", ft_strchr(a, 108));
// }
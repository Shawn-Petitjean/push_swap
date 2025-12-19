/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shapetit <shapetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:52:25 by shapetit          #+#    #+#             */
/*   Updated: 2025/11/10 15:33:43 by shapetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	len_s;
	size_t	len_d;
	size_t	i;
	int		y;

	len_s = ft_strlen(src);
	len_d = ft_strlen(dest);
	i = len_d;
	y = -1;
	if (len_d >= n)
		return (len_s + n);
	while (i < n - 1 && src[++y])
	{
		dest[i] = src[y];
		i++;
	}
	dest[i] = '\0';
	return (len_s + len_d);
}

// #include <stdio.h>
// int main()
// {
// 	char a[] = "salut";
// 	char b[] = "co";
// 	printf("%ld\n", ft_strlcat(a, b, 4));
// 	printf("%s\n", a);
// }
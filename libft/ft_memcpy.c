/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shapetit <shapetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 09:25:52 by shapetit          #+#    #+#             */
/*   Updated: 2025/11/06 11:53:40 by shapetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t					i;
	const unsigned char		*tempsrc;
	unsigned char			*tempdest;

	i = 0;
	tempsrc = src;
	tempdest = dest;
	while (i < n)
	{
		tempdest[i] = tempsrc[i];
		i++;
	}
	return ((void *)dest);
}
// #include <stdio.h>
// #include <string.h>
// int	main()
// {
// 	char a[] = "salut";
// 	char b[] = "coucou";
// 	char c[] = "salut";
// 	char d[] = "coucou";
// 	printf("%s\n", (char *)ft_memcpy(d, c , 4));
// 	printf("%s\n", (char *)memcpy(b, a , 4));
// }
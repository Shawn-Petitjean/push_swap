/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shapetit <shapetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:27:29 by shapetit          #+#    #+#             */
/*   Updated: 2025/11/13 16:09:50 by shapetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, void *src, size_t n)
{
	char	*temp_dest;
	char	*temp_src;

	temp_dest = dest;
	temp_src = src;
	if (dest < src)
		return ((void *)ft_memcpy((char *)dest, (char *)src, n));
	while (n > 0)
	{
		temp_dest[n -1] = temp_src[n -1];
		n--;
	}
	return ((void *) dest);
}

// #include <stdio.h>
// #include <string.h>
// int	main()
// {
// 	char a[] = "salut";
// 	char *b = &a[2];
// 	char c[] = "salut";
// 	char *d = &c[2];
// 	printf("%s\n", (char *)ft_memmove(b, a, 3));
// 	printf("%s\n",  (char *)memmove(d, c, 3));
// }
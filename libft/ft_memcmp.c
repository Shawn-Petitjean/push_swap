/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shapetit <shapetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:35:04 by shapetit          #+#    #+#             */
/*   Updated: 2025/11/12 11:07:54 by shapetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	unsigned char		*t1;
	unsigned char		*t2;

	i = 0;
	t1 = (unsigned char *)s1;
	t2 = (unsigned char *)s2;
	while (i < n)
	{
		if (t1[i] != t2[i])
			return (t1[i] - t2[i]);
		i++;
	}
	return (0);
}

// #include <stdio.h>
// #include <stdlib.h>
// int    main(int arc, char **arv)
// {
//     if (arc < 2)
//     {
//         printf("please take two arguments\n");
//         return (0);
//     }
//     printf("result or : %d\nmy result : %d\n", 
// memcmp((char *)arv[1],(char *) arv[2], (size_t)atoi(arv[3])), 
// ft_memcmp((char *)arv[1],(char *) arv[2], (size_t)atoi(arv[3])));
//     return (0);
// }
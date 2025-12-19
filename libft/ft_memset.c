/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shapetit <shapetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:54:14 by shapetit          #+#    #+#             */
/*   Updated: 2025/11/07 18:36:38 by shapetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	int		i;
	char	*temp;

	i = 0;
	temp = (char *)s;
	while (n != 0)
	{
		temp[i] = c;
		i++;
		n--;
	}
	return ((void *)s);
}

// #include <stdio.h>
// int	main()
// {
// 	char a[] = "salut";
// 	printf("%s", (char*)ft_memset( a, 66, 2));
// }

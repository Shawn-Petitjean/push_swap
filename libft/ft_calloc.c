/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shapetit <shapetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 10:15:38 by shapetit          #+#    #+#             */
/*   Updated: 2025/11/20 10:53:51 by shapetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc( size_t n, size_t l)
{
	unsigned char	*a;

	if (n == 0 || l == 0)
		return (a = malloc(0), a);
	if (n > 2147483647 || l > 2147483647)
		return (NULL);
	a = malloc(n * l);
	if (!a)
		return (NULL);
	ft_bzero(a, (n * l));
	return (a);
}

// int main()
// {
// 	printf("%s\n", (char *)ft_calloc(4, 4));
// }
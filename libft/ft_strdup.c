/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shapetit <shapetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 18:34:33 by shapetit          #+#    #+#             */
/*   Updated: 2025/11/12 11:15:34 by shapetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	char	*dest;

	i = 0;
	while (src[i])
		i++;
	dest = malloc((1 + i) * sizeof(char));
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

// int    main(int arc, char **arv)
// {
//     if (arc < 2)
//     {
//         printf("please take tow arguments\n");
//         return (0);
//     }
//     char *test1 = strdup(arv[1]);
//     char *test2 = ft_strdup(arv[1]);
//     printf("result or : %s\n", test1);
//     printf("result me : %s\n", test2);
//     free(test1);
//     free(test2);
//     return (0);
// }

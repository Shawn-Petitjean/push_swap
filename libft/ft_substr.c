/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shawn <shawn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:01:11 by shapetit          #+#    #+#             */
/*   Updated: 2025/11/11 20:14:38 by shawn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*a;
	size_t	i;
	size_t	y;

	y = start;
	i = 0;
	if ((start >= ft_strlen(s)) || len == 0)
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	a = ft_calloc((len + 1), sizeof(char));
	if (!a)
		return (NULL);
	while (i < len && s[y] != '\0')
	{
		a[i] = s[y];
		i++;
		y++;
	}
	a[i] = '\0';
	return (a);
}

// int    main(int arc, char **arv)
// {
//     if (arc < 2)
//     {
//         printf("please take tow arguments\n");
//         return (0);
//     }
//     char *test2 = ft_substr(arv[1], atoi(arv[2]), atoi(arv[3]));
//     printf("result me : %s\n", test2);
//     free(test2);
//     return (0);
// }
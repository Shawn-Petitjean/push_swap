/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shawn <shawn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:31:33 by shapetit          #+#    #+#             */
/*   Updated: 2025/11/11 17:44:09 by shawn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*res;

	i = 0;
	res = NULL;
	while (s[i])
	{
		if (s[i] == (char)c)
			res = (char *) &s[i];
		i++;
	}
	if (c == '\0')
		return ((char *) &s[i]);
	return (res);
}

// #include <stdio.h>
// int    main(int arc, char **arv)
// {
//     char    *dest;
//     char    *dest2;

//     if (arc < 2)
//     {
//         printf("please take two arguments\n");
//         return (0);
//     }
//     dest = strrchr(arv[1], arv[2][0]);
//     dest2 = ft_strrchr(arv[1], arv[2][0]);
//     printf("result or : %s\nmy result : %s\n", dest, dest2);
//     return (0);
// }
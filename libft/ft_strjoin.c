/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shawn <shawn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 08:48:33 by shapetit          #+#    #+#             */
/*   Updated: 2025/11/11 20:19:06 by shawn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		y;
	char	*a;

	i = 0;
	y = 0;
	if (!s1 || !s2)
		return (NULL);
	a = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!a)
		return (NULL);
	while (s1[y] != '\0')
	{
		a[y] = s1[y];
		y++;
	}
	while (s2[i] != '\0')
	{
		a[y + i] = s2[i];
		i++;
	}
	a[y + i] = '\0';
	return (a);
}

// int    main(int arc, char **arv)
// {
//     if (arc < 2)
//     {
//         printf("please take tow arguments\n");
//         return (0);
//     }
//     char *test2 = ft_strjoin(arv[1], arv[2]);
//     printf("result me : %s\n", test2);
//     free (test2);
//     return (0);
// }
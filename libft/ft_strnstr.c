/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shawn <shawn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:46:37 by shapetit          #+#    #+#             */
/*   Updated: 2025/11/11 18:19:54 by shawn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	if (little[0] == 0)
		return ((char *)big);
	i = 0;
	while (i < len && big[i])
	{
		if (little[0] == big[i])
		{
			if (ft_strlen(little) > len - i)
				return (NULL);
			if (!ft_strncmp(little, &big[i], ft_strlen(little)))
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <bsd/string.h>
// // int main()
// // {
// // 	printf("le resultat est %s\n", ft_strnstr("hello world", "ll", 5));
// // }
// int    main(int arc, char **arv)
// {
//     if (arc < 2)
//     {
//         printf("please take tow arguments\n");
//         return (0);
//     }
//     printf("result or : %s\n", strnstr(arv[1], arv[2], atoi(arv[3])));
//     printf("result me : %s\n", ft_strnstr(arv[1], arv[2], atoi(arv[3])));
//     return (0);
// }
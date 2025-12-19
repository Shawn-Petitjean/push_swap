/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shawn <shawn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 15:49:19 by shapetit          #+#    #+#             */
/*   Updated: 2025/11/11 19:37:26 by shawn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*a;

	i = 0;
	a = ft_calloc((ft_strlen(s) + 1), sizeof (char));
	if (!a)
		return (NULL);
	while (s[i])
	{
		a[i] = (f)((unsigned int) i, s[i]);
		i++;
	}
	return (a);
}
// #include <stdio.h>
// char    uppercase(unsigned int i, char c)
// {
//     (void)i;
//     return ((char)ft_toupper(c));
// }

// int    check_err(int e, char *p)
// {
//     if (e == 1)
//         fprintf(stderr, "Usage: %s <string>\n", p);
//     if (e == 2)
//         perror("Error");
//     return (e);
// }

// int    main(int ac, char **av)
// {
//     char    *res;

//     if (ac != 2)
//         return (check_err(1, av[0]), 1);
//     res = ft_strmapi(av[1], uppercase);
//     if (!res)
//         return (check_err(1, av[0]), 1);
//     printf("Original:\t%s\n", av[1]);
//     printf("Mapped:\t%s\n", res);
//     free(res);
//     return (0);
// }
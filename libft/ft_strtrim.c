/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shawn <shawn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:13:33 by shapetit          #+#    #+#             */
/*   Updated: 2025/11/11 20:34:31 by shawn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_contains(const char *str, const char c)
{
	int	i;

	if (!c)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*string;
	size_t	size;
	int		start;
	int		end;
	int		i;

	size = ft_strlen(s1);
	i = 0;
	while (s1[i] && ft_contains(set, s1[i]))
		i++;
	start = i;
	i = size - 1;
	while (s1[i] && ft_contains(set, s1[i]))
		i--;
	end = i + 1;
	string = ft_substr(s1, start, end - start);
	return (string);
}

// int	main()
// {
//     char *test2 = NULL;
// 	test2 = ft_strtrim(" jawdbn dauwbda awbd abdad ", " ");
// 	printf ("%s\n", test2);
//     free(test2);
//     return (0);
// }
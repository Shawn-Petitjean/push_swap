/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shawn <shawn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 11:50:40 by shapetit          #+#    #+#             */
/*   Updated: 2025/11/11 17:48:56 by shawn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		res;

	i = 0;
	while ((s1[i] != '\0' && s2[i] != '\0') && s1[i] == s2[i] && i < n)
		i++;
	if (i == n)
		return (0);
	return (res = s1[i] - s2[i]);
}

// #include <stdio.h>
// int	main()
// {
// 	const char	s1[] = "wdwa";
// 	const char	s2[] = "w546";
// 	unsigned	int	n = 2;
// 	int		rep1;
// 	rep1 = ft_strncmp(s2, s1, n);
// 	printf("%d\n%s\n%s\n%d\n", rep1, s1, s2, n);
// }
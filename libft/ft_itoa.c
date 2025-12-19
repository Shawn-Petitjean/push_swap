/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shapetit <shapetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 14:48:25 by shapetit          #+#    #+#             */
/*   Updated: 2025/11/10 11:54:28 by shapetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lenint(long int n)
{
	int	c;

	c = 1;
	if (n == 0)
		return (2);
	while (n)
	{
		c += 1;
		n = (n / 10);
	}
	return (c);
}

static char	*ft_print_itoa(char *s, long int i, long int res, long int m)
{
	while (res >= 10)
	{
		s[i - 1 + m] = '0' + (res % 10);
		res = res / 10;
		i--;
	}
	s[i -1 + m] = '0' + (res % 10);
	res = res / 10;
	return (s);
}

char	*ft_itoa(int n)
{
	char			*s;
	long int		i;
	long int		m;
	long int		res;

	res = n;
	m = 0;
	if (res < 0)
	{
		res = -res;
		m = 1;
	}
	i = ft_lenint(res);
	s = malloc((m + i) * sizeof (char));
	s[(i + m) - 1] = '\0';
	i--;
	if (m == 1)
		s[0] = '-';
	return (ft_print_itoa(s, i, res, m));
}

// int	main()
// {
// 	char *a;
// 	a = ft_itoa(456);
// 	printf("%s\n", a);
// 	free (a);
// }
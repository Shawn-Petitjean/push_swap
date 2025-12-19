/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_allnbr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shapetit <shapetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:59:02 by shapetit          #+#    #+#             */
/*   Updated: 2025/12/09 16:30:07 by shapetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len_unint(unsigned int n)
{
	int	i;

	i = 1;
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	ft_print_unbr(unsigned int n)
{
	char	res;
	int		size;

	size = ft_len_unint(n);
	if (n < 0)
	{
		n = -n;
		write (1, "-", 1);
	}
	if (n >= 10)
		ft_print_nbr(n / 10);
	res = (n % 10) + 48;
	write (1, &res, 1);
	return (size);
}

int	ft_print_nbr(int n)
{
	char	res;
	int		size;

	size = ft_len_int(n);
	if (n == -2147483648)
	{
		write (1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		n = -n;
		write (1, "-", 1);
	}
	if (n >= 10)
		ft_print_nbr(n / 10);
	res = (n % 10) + 48;
	write (1, &res, 1);
	return (size);
}

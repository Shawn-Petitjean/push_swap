/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shapetit <shapetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:10:51 by shapetit          #+#    #+#             */
/*   Updated: 2025/12/09 11:08:50 by shapetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_hexa_len(unsigned int n)
{
	int	i;

	i = 1;
	while (n >= 16)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

static void	ft_convert_lohexa(unsigned int n)
{
	char		*hex;
	char		res;

	hex = "0123456789abcdef";
	if (n > 16)
		ft_convert_lohexa(n / 16);
	res = hex[n % 16];
	write (1, &res, 1);
}

static void	ft_convert_uphexa(unsigned int n)
{
	char		*hex;
	char		res;

	hex = "0123456789ABCDEF";
	if (n > 16)
		ft_print_uphexa(n / 16);
	res = hex[n % 16];
	write (1, &res, 1);
}

int	ft_print_lohexa(unsigned int n)
{
	ft_convert_lohexa(n);
	return (ft_hexa_len(n));
}

int	ft_print_uphexa(unsigned int n)
{
	ft_convert_uphexa(n);
	return (ft_hexa_len(n));
}

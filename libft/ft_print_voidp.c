/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_voidp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shapetit <shapetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 11:41:26 by shapetit          #+#    #+#             */
/*   Updated: 2025/12/09 11:08:56 by shapetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_hexa_len(long int n)
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

static void	ft_print_hexp(long int n)
{
	char		*hex;
	char		res;

	hex = "0123456789abcdef";
	if (n > 16)
		ft_print_hexp(n / 16);
	res = hex[n % 16];
	write (1, &res, 1);
}

int	ft_print_voidp(long int n)
{
	if (!n)
		return (write (1, "(nil)", 5), 3);
	write (1, "0x", 2);
	ft_print_hexp(n);
	return (ft_hexa_len(n + 2));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shapetit <shapetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 18:11:29 by shapetit          #+#    #+#             */
/*   Updated: 2025/12/09 11:08:53 by shapetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_str(char *ap)
{
	int	i;

	i = 0;
	if (!ap)
		return (write(1, "(null)", 6), 6);
	while (ap[i])
	{
		write(1, &ap[i], 1);
		i++;
	}
	return (i);
}

int	ft_print_c(int c)
{
	write (1, &c, 1);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shapetit <shapetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 15:49:27 by shapetit          #+#    #+#             */
/*   Updated: 2026/01/06 14:58:19 by shapetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	i_parsing(long int *tab, int len)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (tab[0] == tab[1])
		return (0);
	while (j < len -1 || i < len)
	{
		if (tab[j] == tab[i])
			return (0);
		if (!tab[i] || i == len)
		{
			j++;
			i = j + 1;
			if (tab[j] == tab[i] && i <= len)
				return (0);
		}
		i++;
	}
	return (1);
}

int	int_lim(long int *tab, int len)
{
	len--;
	while (len >= 0)
	{
		if (tab[len] > 2147483647 || tab[len] < -2147483648)
			return (0);
		len--;
	}
	return (1);
}

static int	is_int(char *str)
{
	int	i;

	i = 0;
	while ((str[i] == '-' || str[i] == '+' )
		|| (str[i] >= '0' && str[i] <= '9') || str[i] == ' ')
	{
		if (ft_strlen(str) == 1 && (str[0] == '+' || str[0] == '-'))
			return (0);
		i++;
		if (str[i] == '\0')
			return (1);
		if (i > 11)
			return (0);
		if ((str[i] == '-' || str[i] == '+') && i > 0)
			return (0);
	}
	return (0);
}

int	parsing(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (!is_int(tab[i]))
			break ;
		i++;
		if (!tab[i])
			return (1);
	}
	return (0);
}

int	len_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL && tab)
		i++;
	return (i);
}

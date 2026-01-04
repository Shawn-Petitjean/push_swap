/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_tab_pars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shawn <shawn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 10:46:47 by shapetit          #+#    #+#             */
/*   Updated: 2026/01/04 09:31:20 by shawn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static long int	ft_atol(char *str)
{
	long int	sign;
	int			i;
	long int	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] == 32) || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (res * sign);
}

static char	*ft_strjoin_swap(char *s1, char *s2)
{
	int		i;
	int		y;
	char	*a;

	i = 0;
	y = 0;
	a = ft_calloc(sizeof(char), (ft_strlen(s1) + ft_strlen(s2) + 3));
	if (!a)
		return (NULL);
	while (s1[y] != '\0' && s1)
	{
		a[y] = s1[y];
		y++;
	}
	a[y] = ' ';
	y++;
	while (s2[i] != '\0' && s2)
	{
		a[y + i] = s2[i];
		i++;
	}
	a[y + i] = ' ';
	a[++y + i] = '\0';
	free (s1);
	return (a);
}

long int	*fill_i_tab(char **c_tab)
{
	long int	*i_tab;
	int			j;

	j = 0;
	while (c_tab[j])
		j++;
	i_tab = ft_calloc(sizeof(long int), (j));
	j = 0;
	while (c_tab[j])
	{
		i_tab[j] = ft_atol(c_tab[j]);
		free (c_tab[j]);
		j++;
	}
	free (c_tab[j]);
	free (c_tab);
	if (!i_parsing(i_tab, j -1) || !int_lim(i_tab, j))
		return (free(i_tab), NULL);
	return (i_tab);
}

char	**fill_c_tab(char **tab)
{
	int		j;
	char	**c_tab;
	char	*str;

	j = 0;
	str = ft_calloc(sizeof(char), 1);
	while (tab[j])
	{
		str = ft_strjoin_swap(str, tab[j]);
		j++;
	}
	c_tab = ft_split(str, ' ');
	free(str);
	if (!parsing(c_tab))
		return (free_str(c_tab), NULL);
	return (c_tab);
}

int	where_is_lis(t_stack *stack)
{
	int	i;
	int	y;
	int	count;
	int	temp_count;

	y = 0;
	i = stack->top;
	count = 0;
	temp_count = 0;
	while (i > 0)
	{
		while ((stack->array[i] < stack->array[i -1]) && i > 1)
		{
			y++;
			i--;
		}
		if (y > temp_count)
		{
			count = i;
			temp_count = y;
		}
		y = 0;
		i--;
	}
	return (count);
}

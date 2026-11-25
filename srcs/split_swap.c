/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shapetit <shapetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 09:00:46 by shapetit          #+#    #+#             */
/*   Updated: 2026/01/07 09:19:26 by shapetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static int	ft_strclen(char const *s, char c)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (s[y] == '0')
		y++;
	i = y;
	while (s[i] != '\0' && s[i] != c)
		i++;
	if (y == i)
		return (1);
	return (i - y);
}

static int	ft_count_n_word(char const *s, char c)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			n += 1;
		while (s[i] != c && s[i])
			i++;
	}
	return (n);
}

static char	*ft_strcdup(char const *src, char c)
{
	int		i;
	char	*dest;
	int		y;

	i = 0;
	y = 0;
	dest = malloc((ft_strclen(src, c) + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	while (src[i] == '0' && src[i] != c)
		i++;
	if (src[i] == '\0' || src[i] == c)
		dest[y++] = '0';
	while (src[i] != '\0' && src[i] != c)
	{
		dest[y++] = src[i];
		i++;
	}
	dest[y] = '\0';
	return (dest);
}

static char	**ft_remove(char **tab, int y)
{
	int	i;

	i = 0;
	while (i < y)
	{
		free (tab[i]);
		i++;
	}
	return (tab);
}

char	**split_swap(char const *s, char c)
{
	char	**tab;
	int		i;
	int		y;

	y = 0;
	i = 0;
	tab = malloc((ft_count_n_word(s, c) + 1) * sizeof (char *));
	if (!tab)
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			tab[y] = ft_strcdup(&s[i], c);
			if (!tab)
				return (free (ft_remove(tab, y)), NULL);
			y++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	tab[y] = NULL;
	return (tab);
}

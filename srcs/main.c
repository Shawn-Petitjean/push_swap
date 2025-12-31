/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shapetit <shapetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 11:21:40 by shapetit          #+#    #+#             */
/*   Updated: 2025/12/30 15:17:12 by shapetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	sort_3(t_stack *a)
{
	if (where_is_min(a) == 0)
		rra(a);
	if (where_is_min(a) == 1 && a->len == 3)
		sa(a);
	if (where_is_max(a) == 1)
	{
		rra(a);
		sa(a);
	}
	return ;
}

void	sort_5(t_stack *a, t_stack *b)
{
	while (where_is_min(a) != a->top)
	{
		if (where_is_min(a) < a->top / 2)
			while (where_is_min(a) != a->top)
				rra(a);
		else
			while (where_is_min(a) != a->top)
				ra(a);
	}
	pb(a, b);
	while (where_is_min(a) != a->top)
	{
		if (where_is_min(a) < a->top / 2)
			while (where_is_min(a) != a->top)
				rra(a);
		else
			while (where_is_min(a) != a->top)
				ra(a);
	}
	pb(a, b);
	sort_3(a);
	pa(a, b);
	pa(a, b);
}

void	free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free (str[i]);
		i++;
	}
	free(str);
}

int	main(int arc, char **arv)
{
	long int	*tab;
	int			len;

	if (arc < 2)
		return (0);
	arv[arc] = NULL;
	arv = fill_c_tab(&arv[1]);
	if (!arv)
		return (free_str(arv), ft_printf("Error\n"), 1);
	len = len_tab(arv);
	tab = fill_i_tab(arv);
	if (!tab)
		return (free(tab), ft_printf("Error\n"), 1);
	init_swap(tab, len);
	return (0);
}

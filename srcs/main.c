/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shapetit <shapetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 11:21:40 by shapetit          #+#    #+#             */
/*   Updated: 2025/12/19 12:56:20 by shapetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	main(int arc, char **arv)
{
	long int	*tab;
	int			len;

	if (arc < 2)
		return (ft_printf("ERROR\n"), 0);
	arv[arc] = NULL;
	arv = fill_c_tab(&arv[1]);
	if (!arv)
		return (free(arv), ft_printf("ERROR\n"), 0);
	len = len_tab(arv);
	tab = fill_i_tab(arv);
	if (!tab)
		return (free(tab), ft_printf("ERROR\n"), 0);
	// push_swap(tab, len);
	init_swap(tab, len);
	return (1);
}

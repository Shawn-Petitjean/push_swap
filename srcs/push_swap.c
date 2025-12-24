/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shapetit <shapetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:17:58 by shapetit          #+#    #+#             */
/*   Updated: 2025/12/24 10:52:01 by shapetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	sort_lis(t_stack *a, t_stack *b, t_info *info)
{
	int	count;

	count = info->s_lis - info->e_lis;
	while (info->s_lis < a->top)
		pb(a, b);
	while (count > 0)
	{
		ra(a);
		count--;
	}
	count = info->s_lis - info->e_lis;
	count = a->top - count;
	while (count >= 0)
	{
		pb(a, b);
		count--;
	}
}

void	half_sort(t_stack *a, t_stack *b, t_info *info)
{
	sort_lis(a, b, info);
	return ;
}

void	push_swap(t_stack *a, t_stack *b, t_info *info)
{
	int	i;

	i = 0;
	half_sort(a, b, info);
	return ;
}

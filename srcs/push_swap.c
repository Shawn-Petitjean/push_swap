/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shawn <shawn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:17:58 by shapetit          #+#    #+#             */
/*   Updated: 2025/12/27 11:17:40 by shawn            ###   ########.fr       */
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

void	swap_sort(t_stack *a, t_stack *b)
{
	int	good;

	good = good_n(a, b);
	while (is_sort(a) && !stack_is_full(a))
	{
		if (good > 0)
			move(a, b, good);
		else
			pre_move(a, b, n_pos(a, b->array[b->top]), good);
		good = good_n(a, b);
	}
}

void	push_swap(t_stack *a, t_stack *b, t_info *info)
{
	sort_lis(a, b, info);
	swap_sort(a, b);
	return ;
}
//654 231 5 0 14 800 11 215 1587 3854 2314
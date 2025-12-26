/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shapetit <shapetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:17:58 by shapetit          #+#    #+#             */
/*   Updated: 2025/12/26 10:02:58 by shapetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	move(t_stack *a, t_stack *b, int pos)
{
	int	i;

	i = a->top;
	if (pos < a->top /2)
	{
		pa(a, b);
		while (i != pos)
			ra(a);
	}
	else
	{
		while (pos != a->top)
		{
			pos++;
			rra;
		}
		pa(a, b);
	}
	return ;
}

void	sort_lis(t_stack *a, t_stack *b, t_info *info)
{
	int	count;

	count = info->s_lis - info->e_lis;
	while (info->s_lis < a->top)
		pb(a, b);
	while (count >= 0)
	{
		ra(a);
		count--;
	}
	count = info->s_lis - info->e_lis;
	count = a->top - count;
	while (count > 0)
	{
		pb(a, b);
		count--;
	}
}

int	n_pos(t_stack *a, int n)
{
	int	i;

	i = a->top;
	while (n > a->array[i] && i > 0)
		i--;
	return (i);
}

int	good_n(t_stack *a, t_stack *b)
{
	int	pos;

	pos = n_pos(a, b->array[b->top]);
	if (pos = a->top)
		pa(a, b);
	if (pos < 2 || pos > a->top -2)
		move(a, b, pos);
	pos = n_pos(a, b->array[b->top -1]);
	if (pos = a->top)
		pa(a, b);
	if (pos < 2 || pos > a->top -2)
		move(a, b, pos);
	pos = n_pos(a, b->array[0]);	
	if (pos = a->top)
	pa(a, b);
	if (pos < 2 || pos > a->top -2)
		move(a, b, pos);
}

void	swap_sort(t_stack *a, t_stack *b, t_info *info)
{
	int	pos;

	while (!is_sort(a), a->top = a->len -1)
	{
		pos = n_pos(a, b->array[b->top]);
		if (pos = a->top)
			pa(a, b);
		if (pos < 2 || pos > a->top -2)
			move(a, b, pos);
		pos = n_pos(a, b->array[b->top -1]);
		if (pos = a->top)
			pa(a, b);
		if (pos < 2 || pos > a->top -2)
			move(a, b, pos);
		pos = n_pos(a, b->array[0]);	
		if (pos = a->top)
			pa(a, b);
		if (pos < 2 || pos > a->top -2)
			move(a, b, pos);
	}
	return ;
	
}

void	push_swap(t_stack *a, t_stack *b, t_info *info)
{
	int	i;

	i = 0;
	sort_lis(a, b, info);
	swap_sort(a, b, info);
	return ;
}

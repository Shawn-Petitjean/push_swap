/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shapetit <shapetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:17:58 by shapetit          #+#    #+#             */
/*   Updated: 2025/12/19 09:49:42 by shapetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	first_sort(t_stack *a, t_stack *b, t_info *info)
{
	int	i;

	i = 0;
	while (i < a->len -1)
	{
		if(a->array[a->top] > info->ave)
			pb(a, b);
		i++;
		sa(a);
	}
	where_is_max(a);
	return ;
}

void	min_ave_sort(t_stack *a, t_stack *b)
{
	while (!stack_is_empty(a))
	{
		if(where_is_max(a) <= a->top / 2)
		{
			while(where_is_max(a) != a->top)
				rra(a);
		}
		else
		{
			while(where_is_max(a) != a->top)
				ra(a);
		}
		pb(a, b);	
	}
	return ;
}

void	end_sort(t_stack *a, t_stack *b)
{
	while (!stack_is_empty(b))
	{
		if(where_is_max(b) <= b->top / 2)
		{
			while(where_is_max(b) != b->top )
				rrb(b);
		}
		else
		{
			while(where_is_max(b) != b->top)
				rb(b);
		}
		pa(b, a);
	}
	return ;
}

void	push_swap(t_stack *a, t_stack *b, t_info *info)
{
	int	i;

	i = 0;
	first_sort(a, b, info);
	min_ave_sort(a, b);
	end_sort(a, b);
	return ;
}

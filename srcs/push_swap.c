/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shapetit <shapetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:17:58 by shapetit          #+#    #+#             */
/*   Updated: 2025/12/23 16:12:52 by shapetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	up_lis(t_stack *a, t_stack *b, int s_lis, int e_lis)
{
	while (s_lis != a->top)
	{
		if (a->array[a->top] < a->array[s_lis])
		{
			if (a->array[a->top] > a->array[a->top -1])
				sa(a);
			ra(a);
		}
		else
			pb(a, b);
		if(a->array[s_lis + 1] < a->array[s_lis])
			s_lis++;
		e_lis--;
	}
}

void	half_sort(t_stack *a, t_stack *b, t_info info)
{
	int	s_lis;
	int	e_lis;

	e_lis = where_is_lis(a);
	s_lis = e_lis;
	while (a->array[s_lis] > a->array[s_lis + 1])
		s_lis++;
	up_lis(a, b, s_lis, e_lis);
	print_stack(a);
	printf("\n");
	print_stack(b);
	if (info.ave)	
		return ;
	return ;
}

	// while (s_lis != a->top)
	// {
	// 	if(a->array[a->top] < a->array[s_lis] || a->array[a->top] > a->array[e_lis])
	// 		ra(a);
	// 	else
	// 		pb(a, b);
	// 	if(a->array[s_lis + 1] < a->array[s_lis])
	// 		s_lis++;
	// }
	// 
	// while (e_lis != 0)
	// {
	// 	rra(a);
	// 	if(a->array[a->top] < s_lis || a->array[a->top] > e_lis)
	// 		rra(a);
	// 	pb(a, b);
	// 	e_lis--;
	// 	s_lis--;
	// }

void	push_swap(t_stack *a, t_stack *b, t_info info)
{
	int	i;

	i = 0;
	half_sort(a, b, info);
	return ;
}
	// int	i;

	// i = 0;
	// while (i++ < a->top / 2)
	// {
	// 	if (where_is_ave(a, info) <= a->top / 2)
	// 	{
	// 		while (where_is_ave(a, info) != a->top)
	// 			rra(a);
	// 	}
	// 	else
	// 	{
	// 		while (where_is_ave(a, info) != a->top)
	// 			ra(a);
	// 	}
	// 	pb(a, b);
	// }
	// return ;
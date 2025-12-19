/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shapetit <shapetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 14:24:39 by shapetit          #+#    #+#             */
/*   Updated: 2025/12/19 12:55:54 by shapetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	sa(t_stack *a)
{
	stack_swap(a);
	ft_printf("%s\n", "sa");
	return ;
}

void	sb(t_stack *b)
{
	stack_swap(b);
	ft_printf("%s\n", "sb");
	return ;
}

void	ss(t_stack *a, t_stack *b)
{
	stack_swap(a);
	stack_swap(b);
	ft_printf("%s\n", "ss");
	return ;
}

void	pa(t_stack *b, t_stack *a)
{
	stack_push(a, b->array[b->top]);
	stack_pop(b);
	ft_printf("%s\n", "pa");
	return ;
}

void	pb(t_stack *a, t_stack *b)
{
	stack_push(b, a->array[a->top]);
	stack_pop(a);
	ft_printf("%s\n", "pb");
	return ;
}

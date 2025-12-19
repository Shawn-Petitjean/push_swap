/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shapetit <shapetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 14:24:39 by shapetit          #+#    #+#             */
/*   Updated: 2025/12/19 09:46:44 by shapetit         ###   ########.fr       */
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

void	sb(t_stack *b_stack)
{
	stack_swap(b_stack);
	ft_printf("%s\n", "sb");
	return ;
}

void	ss(t_stack *a_stack, t_stack *b_stack)
{
	stack_swap(a_stack);
	stack_swap(b_stack);
	ft_printf("%s\n", "ss");
	return ;
}

void	pa(t_stack *a_stack, t_stack *b_stack)
{
	stack_push(a_stack, b_stack->array[b_stack->top]);
	stack_pop(b_stack, 0);
	ft_printf("%s\n", "pa");
	return ;
}

void	pb(t_stack *a, t_stack *b)
{
	stack_push(b, a->array[b->top]);
	stack_pop(a, 0);
	ft_printf("%s\n", "pb");
	return ;
}

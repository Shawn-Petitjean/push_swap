/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_next.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shapetit <shapetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 14:26:59 by shapetit          #+#    #+#             */
/*   Updated: 2025/12/19 09:47:27 by shapetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ra(t_stack *a)
{
	stack_rotate(a);
	ft_printf("%s\n", "ra");
	return ;
}

void	rb(t_stack *b)
{
	stack_rotate(b);
	ft_printf("%s\n", "rb");
	return ;
}

void	rr(t_stack *a, t_stack *b)
{
	stack_rotate(a);
	stack_rotate(b);
	ft_printf("%s\n", "rr");
	return ;
}

void	rra(t_stack *a)
{
	stack_rev_rotate(a);
	ft_printf("%s\n", "rra");
	return ;
}

void	rrb(t_stack *b)
{
	stack_rev_rotate(b);
	ft_printf("%s\n", "rrb");
	return ;
}

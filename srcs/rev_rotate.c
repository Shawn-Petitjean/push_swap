/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shapetit <shapetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 14:28:13 by shapetit          #+#    #+#             */
/*   Updated: 2025/12/18 14:59:09 by shapetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	rrr(t_stack *a_stack, t_stack *b_stack)
{
	stack_rev_rotate(a_stack);
	stack_rev_rotate(b_stack);
	ft_printf("%s\n", "rrr");
	return ;
}

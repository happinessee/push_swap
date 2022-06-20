/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 17:49:17 by hyojeong          #+#    #+#             */
/*   Updated: 2022/06/20 16:53:08 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <unistd.h>

void	rra(t_stack *stack)
{
	if (stack->a_size < 2)
		return ;
	stack->a_top = stack->a_top->prev;
	stack->a_bot = stack->a_bot->prev;
	write(1, "rra\n", 4);
}

void	rrb(t_stack *stack)
{
	if (stack->b_size < 2)
		return ;
	stack->b_top = stack->b_top->prev;
	stack->b_bot = stack->b_bot->prev;
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *stack)
{
	if (stack->a_size < 2)
		return ;
	stack->a_top = stack->a_top->prev;
	stack->a_bot = stack->a_bot->prev;
	if (stack->b_size < 2)
		return ;
	stack->b_top = stack->b_top->prev;
	stack->b_bot = stack->b_bot->prev;
	write(1, "rrr\n", 4);
}

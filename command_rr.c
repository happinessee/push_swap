/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_rr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 16:47:47 by hyojeong          #+#    #+#             */
/*   Updated: 2022/06/20 16:50:55 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <unistd.h>

void	ra(t_stack *stack)
{	
	if (stack->a_size < 2)
		return ;
	stack->a_top = stack->a_top->next;
	stack->a_bot = stack->a_bot->next;
	write(1, "ra\n", 3);
}

void	rb(t_stack *stack)
{
	if (stack->b_size < 2)
		return ;
	stack->b_top = stack->b_top->next;
	stack->b_bot = stack->b_bot->next;
	write(1, "rb\n", 3);
}

void	rr(t_stack *stack)
{
	if (stack->a_size < 2)
		return ;
	stack->a_top = stack->a_top->next;
	stack->a_bot = stack->a_bot->next;
	if (stack->b_size < 2)
		return ;
	stack->b_top = stack->b_top->next;
	stack->b_bot = stack->b_bot->next;
	write(1, "rr\n", 3);
}

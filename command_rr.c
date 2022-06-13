/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_rr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 16:47:47 by hyojeong          #+#    #+#             */
/*   Updated: 2022/06/13 19:48:14 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <unistd.h>

void	ra(t_stack *stack)
{	
	t_list	*tmp;

	if (stack->a_size < 2)
		return ;
	tmp = stack->a_top;
	stack->a_top = stack->a_top->next;
	stack->a_bot->next = tmp;
	stack->a_bot = tmp;
	stack->a_bot->next = 0;
	write(1, "ra\n", 3);
}

void	rb(t_stack *stack)
{
	t_list	*tmp;

	if (stack->b_size < 2)
		return ;
	tmp = stack->b_top;
	stack->b_top = stack->b_top->next;
	stack->b_bot->next = tmp;
	stack->b_bot = tmp;
	stack->b_bot->next = 0;
	write(1, "rb\n", 3);
}

void	rr(t_stack *stack)
{
	t_list	*tmp;

	if (stack->a_size < 2)
		return ;
	tmp = stack->a_top;
	stack->a_top = stack->a_top->next;
	stack->a_bot->next = tmp;
	stack->a_bot = tmp;
	stack->b_bot->next = 0;
	if (stack->b_size < 2)
		return ;
	tmp = stack->b_top;
	stack->b_top = stack->b_top->next;
	stack->b_bot->next = tmp;
	stack->b_bot = tmp;
	stack->b_bot->next = 0;
	write(1, "rr\n", 3);
}

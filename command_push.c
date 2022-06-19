/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:50:04 by hyojeong          #+#    #+#             */
/*   Updated: 2022/06/19 21:04:15 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <unistd.h>

void	pa(t_stack *stack)
{
	t_list	*tmp;

	if (stack->b_size < 1)
		return ;
	tmp = stack->b_top;
	if (stack->b_size > 1)
	{
		printf("%p\n", tmp->next);
		printf("%p\n", tmp->prev);
		stack->b_top = stack->b_top->next;
		stack->b_top->prev = 0;
	}
	if (stack->a_size == 0)
	{
		tmp->next = 0;
		stack->a_top = tmp;
		stack->a_bot = tmp;
	}
	else
	{
		tmp->next = stack->a_top;
		stack->a_top->prev = tmp;
		stack->a_top = tmp;
	}
	stack->a_size += 1;
	stack->b_size -= 1;
	write(1, "pa\n", 3);
}

void	pb(t_stack *stack)
{
	t_list	*tmp;

	if (stack->a_size < 1)
		return ;
	tmp = stack->a_top;
	if (stack->a_size > 1)
	{
		stack->a_top = stack->a_top->next;
		stack->a_top->prev = 0;
	}
	if (stack->b_size == 0)
	{
		tmp->next = 0;
		stack->b_top = tmp;
		stack->b_bot = tmp;
	}
	else
	{
		tmp->next = stack->b_top;
		stack->b_top->prev = tmp;
		stack->b_top = tmp;
	}
	stack->b_size += 1;
	stack->a_size -= 1;
	write(1, "pb\n", 3);
}

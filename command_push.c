/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:50:04 by hyojeong          #+#    #+#             */
/*   Updated: 2022/06/20 17:56:32 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <unistd.h>

void	size_zero(t_list *tmp, t_list **lst_top, t_list **lst_bot)
{
	(void)lst_top;
	(void)lst_bot;
	tmp->next = 0;
	tmp->prev = 0;
	*lst_top = tmp;
	*lst_bot = tmp;
}

void	pa(t_stack *stack)
{
	t_list	*tmp;

	if (stack->b_size < 1)
		return ;
	tmp = stack->b_top;
	if (stack->b_size > 1)
	{
		stack->b_top = stack->b_top->next;
		stack->b_top->prev = stack->b_bot;
		stack->b_bot->next = stack->b_top;
	}
	if (stack->a_size == 0)
		size_zero(tmp, &stack->a_top, &stack->a_bot);
	else
	{
		tmp->next = stack->a_top;
		stack->a_top->prev = tmp;
		stack->a_top = tmp;
		stack->a_top->prev = stack->a_bot;
		stack->a_bot->next = stack->a_top;
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
		stack->a_top->prev = stack->a_bot;
		stack->a_bot->next = stack->a_top;
	}
	if (stack->b_size == 0)
		size_zero(tmp, &stack->b_top, &stack->b_bot);
	else
	{
		tmp->next = stack->b_top;
		stack->b_top->prev = tmp;
		stack->b_top = tmp;
		stack->b_top->prev = stack->b_bot;
		stack->b_bot->next = stack->b_top;
	}
	stack->b_size += 1;
	stack->a_size -= 1;
	write(1, "pb\n", 3);
}

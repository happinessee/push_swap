/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 17:49:17 by hyojeong          #+#    #+#             */
/*   Updated: 2022/06/19 21:14:53 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <unistd.h>

void	rra(t_stack *stack)
{
	t_list	*tmp;
	printf("1rra, b, next point : %p\n", stack->b_top->next);
	if (stack->a_size < 2)
		return ;
	tmp = stack->a_bot;
	printf("2rra b, next point : %p\n", stack->b_top->next);
	stack->a_bot = stack->a_bot->prev;
	printf("3rra b, next point : %p\n", stack->b_top->next);
	stack->a_bot->next = 0;
	printf("4rra b, next point : %p\n", stack->b_top->next);
	stack->a_top->prev = tmp;
	printf("5rra b, next point : %p\n", stack->b_top->next);
	tmp->next = stack->a_top;
	printf("6 rra b, next point : %p\n", stack->b_top->next);
	stack->a_top = tmp;
	printf("7rra b, next point : %p\n", stack->b_top->next);
	stack->a_top->prev = 0;
	write(1, "rra\n", 4);
	printf("8rra b, next point : %p\n", stack->b_top->next);
}

void	rrb(t_stack *stack)
{
	t_list	*tmp;

	if (stack->b_size < 2)
		return ;
	tmp = stack->b_bot;
	stack->b_bot = stack->b_bot->prev;
	stack->b_bot->next = 0;
	stack->b_top->prev = tmp;
	tmp->next = stack->b_top;
	stack->b_top = tmp;
	stack->b_top->prev = 0;
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *stack)
{
	t_list	*tmp;

	if (stack->a_size < 2)
		return ;
	tmp = stack->a_bot;
	stack->a_bot = stack->a_bot->prev;
	stack->a_bot->next = 0;
	stack->a_top->prev = tmp;
	tmp->next = stack->a_top;
	stack->a_top = tmp;
	stack->a_top->prev = 0;
	if (stack->b_size < 2)
		return ;
	tmp = stack->b_bot;
	stack->b_bot = stack->b_bot->prev;
	stack->b_bot->next = 0;
	stack->b_top->prev = tmp;
	tmp->next = stack->b_top;
	stack->b_top = tmp;
	stack->b_top->prev = 0;
	write(1, "rrr\n", 4);
}

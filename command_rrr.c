/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 17:49:17 by hyojeong          #+#    #+#             */
/*   Updated: 2022/06/15 18:50:56 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <unistd.h>

void	rra(t_stack *stack)
{
	t_list	*tmp;
	t_list	*tmp2;
	int		idx;

	idx = 0;
	if (stack->a_size < 2)
		return ;
	tmp = stack->a_bot;
	tmp2 = stack->a_top;
	while (++idx < stack->a_size)
		tmp2 = tmp2->next;
	stack->a_bot = tmp2;
	stack->a_bot->next = 0;
	tmp->next = stack->a_top;
	stack->a_top = tmp;
	write(1, "rra\n", 4);
}

void	rrb(t_stack *stack)
{
	t_list	*tmp;
	t_list	*tmp2;
	int		idx;

	idx = 0;
	if (stack->b_size < 2)
		return ;
	tmp = stack->b_bot;
	tmp2 = stack->b_top;
	while (++idx < stack->b_size)
		tmp2 = tmp2->next;
	stack->b_bot = tmp2;
	stack->b_bot->next = 0;
	tmp->next = stack->b_top;
	stack->b_top = tmp;
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *stack)
{
	t_list	*tmp;
	int		idx;

	idx = 0;
	if (stack->a_size < 2)
		return ;
	tmp = stack->a_bot;
	while (++idx < stack->a_size)
		stack->a_bot = stack->a_bot->next;
	stack->a_bot->next = 0;
	tmp->next = stack->a_top;
	stack->a_top = tmp;
	idx = 0;
	if (stack->b_size < 2)
		return ;
	tmp = stack->b_bot;
	while (++idx < stack->b_size)
		stack->b_bot = stack->b_bot->next;
	stack->b_bot->next = 0;
	tmp->next = stack->b_top;
	stack->b_top = tmp;
	write(1, "rrr\n", 4);
}

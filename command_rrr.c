/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 17:49:17 by hyojeong          #+#    #+#             */
/*   Updated: 2022/06/13 17:48:02 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <unistd.h>

void	rra(t_stack *stack)
{
	t_list	*tmp;
	int		idx;

	idx = 0;
	if (stack->a_size < 2)
		return ;
	tmp = stack->a_bot;
	tmp->next = stack->a_top;
	stack->a_top = tmp;
	tmp = stack->a_top;
	while (++idx < stack->a_size)
		tmp = tmp->next;
	tmp->next = 0;
	stack->a_bot = tmp;
	write(1, "rra\n", 4);
}

void	rrb(t_stack *stack)
{
	t_list	*tmp;
	int		idx;

	idx = 0;
	if (stack->b_size < 2)
		return ;
	tmp = stack->b_bot;
	tmp->next = stack->b_top;
	stack->b_top = tmp;
	tmp = stack->b_top;
	while (++idx < stack->b_size)
		tmp = tmp->next;
	tmp->next = 0;
	stack->b_bot = tmp;
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
	tmp->next = stack->a_top;
	stack->a_top = tmp;
	tmp = stack->a_top;
	while (++idx < stack->a_size)
		tmp = tmp->next;
	tmp->next = 0;
	stack->a_bot = tmp;
	if (stack->b_size < 2)
		return ;
	tmp = stack->b_bot;
	tmp->next = stack->b_top;
	stack->b_top = tmp;
	tmp = stack->b_top;
	while (++idx < stack->b_size + stack->a_size)
		tmp = tmp->next;
	tmp->next = 0;
	stack->b_bot = tmp;
	write(1, "rrr\n", 4);
}

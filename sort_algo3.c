/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:31:15 by hyojeong          #+#    #+#             */
/*   Updated: 2022/06/10 17:24:15 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_min_commands(t_stack *stack)
{
	int		idx;
	t_list	*b;
	int		tmp;
	int		a_loca;
	int		b_loca;
	
	idx = 0;
	b = stack->b_top;
	while (idx < stack->b_size)
	{
		tmp = b->content;
		a_loca = set_loca(tmp, stack);
		if (idx >= (stack->b_size + 1) / 2)
			b_loca = (stack->b_size - idx) * -1;
		else
			b_loca = idx;
		if (idx == 0 || )
		{
			
		}
		b = b->next;
		idx++;
	}
}

int	set_loca(int num, t_stack *stack)
{
	int	res;

	if (num < get_stack_min(stack->a_top))
	{
		res = set_loca_bot(stack);
	}
	else if (num > get_stack_max(stack->a_top))
	{
		res = set_loca_top(stack);
	}
	else
	{
		res = set_loca_mid(stack);
	}
	return (res);
}

int	set_loca_bot(t_stack *stack)
{
	int		idx;
	int		tmp;
	int		min;
	t_list	*a;

	idx = 0;
	a = stack->a_top;
	min = get_stack_min(a);
	while (a)
	{
		tmp = a->content;
		if (tmp == min)
		{
			break;
		}
		a = a->next;
		idx++;
	}
	make_idx_best(idx, stack);
	return (idx);
}

int	set_loca_top(t_stack *stack)
{
	int		idx;
	int		tmp;
	int		max;
	t_list	*a;

	idx = 0;
	a = stack->a_top;
	max = get_stack_max(a);
	while (a)
	{
		tmp = a->content;
		if (tmp == max)
		{
			break;
		}
		a = a->next;
		idx++;
	}
	make_idx_best(idx, stack);
	return (idx);
}

int	set_loca_mid(int num, t_stack *stack)
{
	t_list	*a;
	int		idx;

	idx = 0;
	a = stack->a_top;
	while (a->next)
	{
		if (num > a->content && num < a->next->content)
			break;
		idx++;
		a = a->next;
	}
	make_idx_best(idx, stack);
	return (idx);
}

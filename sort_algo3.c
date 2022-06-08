/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:31:15 by hyojeong          #+#    #+#             */
/*   Updated: 2022/06/08 16:58:59 by hyojeong         ###   ########.fr       */
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
		a_loca = 
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
	int		ret;
	int		tmp;
	int		min;
	t_list	*a;

	ret = 0;
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
		ret++;
	}
	if ()
}

int	set_loca_top(t_stack *stack)
{

}

int	set_loca_mid(t_stack *stack)
{

}

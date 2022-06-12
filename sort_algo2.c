/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 18:36:17 by hyojeong          #+#    #+#             */
/*   Updated: 2022/06/12 14:42:13 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	make_idx_best(int idx, t_stack *stack)
{
	if (idx >= (stack->a_size + 1 / 2))
		idx = (stack->a_size - idx) * -1;
	return (idx);
}

int	get_stack_min(t_list *lst)
{
	int		min;

	min = 2147483647;
	while (lst)
	{
		if (lst->content < min)
		{
			min = lst->content;
		}
		lst = lst->next;
	}
	return (min);
}

int	get_stack_max(t_list *lst)
{
	int		max;

	max = -1;
	while (lst)
	{
		if (lst->content > max)
		{
			max = lst->content;
		}
		lst = lst->next;
	}
	return (max);
}

int	find_moveless_idx(int tmp, t_stack *stack)
{
	int		idx;
	t_list	*a;

	idx = 0;
	a = stack->a_top;
	while (a)
	{
		if (a->content == tmp)
			break;
		a = a->next;
		idx++;
	}
	idx = make_idx_best(idx, stack);
	return (idx);
}

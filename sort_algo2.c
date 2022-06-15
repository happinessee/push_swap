/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 18:36:17 by hyojeong          #+#    #+#             */
/*   Updated: 2022/06/15 17:58:20 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	make_idx_best(int idx, t_stack *stack)
{
	if (idx >= (stack->a_size + 1) / 2)
		idx = (stack->a_size - idx) * -1;
	return (idx);
}

int	get_stack_min(t_list *lst)
{
	int		min;

	min = lst->content;
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

	max = lst->content;
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
			break ;
		a = a->next;
		idx++;
	}
	return (make_idx_best(idx, stack));
}

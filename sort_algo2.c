/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 18:36:17 by hyojeong          #+#    #+#             */
/*   Updated: 2022/06/08 17:14:45 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	make_idx_best(int idx, t_stack *stack)
{
	if (idx >= (stack->a_size + 1 / 2))
		idx = (stack->a_size - idx) * -1;
	return (idx);
}

t_list	*get_stack_min(t_list *lst)
{
	int		idx;
	int		min;

	idx = 0;
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

t_list	*get_stack_max(t_list *lst)
{
	int		idx;
	int		max;

	idx = 0;
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

// tmp는  min, max 값
int	find_moveless_idx(int num, int tmp, t_stack *stack)
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

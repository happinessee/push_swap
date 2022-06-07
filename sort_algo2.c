/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 18:36:17 by hyojeong          #+#    #+#             */
/*   Updated: 2022/06/07 18:39:12 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*get_stack_min(t_list *lst)
{
	t_list	*min;
	int		idx;
	int		tmp;

	idx = 0;
	tmp = 2147483647;
	while (lst)
	{
		if (lst->content < tmp)
		{
			tmp = lst->content;
			min = lst;
		}
		lst = lst->next;
	}
	return (min);
}

t_list	*get_stack_max(t_list *lst)
{
	t_list	*max;
	int		idx;
	int		tmp;

	idx = 0;
	tmp = -1;
	while (lst)
	{
		if (lst->content > tmp)
		{
			tmp = lst->content;
			max = lst;
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
	if ((idx >= stack->a_size + 1) / 2)
		idx = (stack->a_size - idx) * -1;
	return (idx);
}


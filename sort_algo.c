/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:30:18 by hyojeong          #+#    #+#             */
/*   Updated: 2022/06/10 15:27:42 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort(t_stack *stack)
{
	int		a;
	int		b;
	
}

void	sort_basic2(t_stack *stack)
{
	t_list	*tmp;

	tmp = stack->a_top->next;
	if (tmp->content < stack->a_top->content)
		sa(stack);
}

void	sort_basic3(t_stack *stack)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = stack->a_top->next;
	tmp2 = tmp->next;
	if (stack->a_top->content > tmp->content && tmp->content > tmp2->content)
	{
		sa(stack);
		rra(stack);
	}
	else if (stack->a_top->content > tmp->content && tmp->content < tmp2->content)
		rra(stack);
	else if (stack->a_top->content < tmp->content && tmp->content > tmp2->content)
	{
		sa(stack);
		ra(stack);
	}
	else if (stack->a_top->content < tmp->content && tmp->content > tmp2->content)
		rra(stack);
	else if (stack->a_top->content > tmp->content && tmp->content < tmp2->content)
		sa(stack);
}

void	devide_init(t_stack *stack)
{
	const int	p1 = stack->a_size / 3;
	const int	p2 = stack->a_size / 3 * 2;
	int			idx;
	t_list		*tmp;

	idx = 0;
	tmp = stack->a_top;
	while (idx < (stack->a_size / 3))
	{
		if (tmp->content < p2)
		{
			pb(stack);
		}
		else if (tmp->content < p1)
		{
			rb(stack);
		}
		tmp = tmp->next;
		idx++;
	}
}

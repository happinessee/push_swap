/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:30:18 by hyojeong          #+#    #+#             */
/*   Updated: 2022/06/12 14:29:37 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	sort_big(t_stack *stack)
{
	int	a_idx;
	int	b_idx;
	
	devide_init(stack);
	while (stack->a_size > 3)
		pb(stack);
	if (stack->a_size == 3)
		sort_basic3(stack);
	if (stack->a_size == 2)
		sort_basic2(stack);
	while (stack->b_size)
	{
		a_idx = 0;
		b_idx = 0;
		get_min_commands(stack, &a_idx, &b_idx);
		rotate_equal(stack, &a_idx, &b_idx);
		ratate_a(stack, a_idx);
		rotate_b(stack, b_idx);
		pa(stack);
	}
	
}

void	sort(t_stack *stack)
{
	if (stack->a_size == 2)
		sort_basic2(stack);
	else if (stack->a_size == 3)
		sort_basic3(stack);
	else
		sort_big(stack);
}

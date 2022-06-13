/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:30:18 by hyojeong          #+#    #+#             */
/*   Updated: 2022/06/13 19:34:31 by hyojeong         ###   ########.fr       */
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
	int	content1;
	int	content2;
	int	content3;

	content1 = stack->a_top->content;
	content2 = stack->a_top->next->content;
	content3 = stack->a_top->next->next->content;
	if (content1 < content2 && content2 > content3 && content1 < content3)
	{
		sa(stack);
		ra(stack);
	}
	else if (content1 > content2 && content2 < content3 && content1 < content3)
		sa(stack);
	else if (content1 < content2 && content2 > content3 && content1 > content3)
		rra(stack);
	else if (content1 > content2 && content2 < content3 && content1 > content3)
		ra(stack);
	else if (content1 > content2 && content2 > content3 && content1 > content3)
	{
		sa(stack);
		rra(stack);
	}
}

void	devide_init(t_stack *stack)
{
	const int	p1 = stack->num_arr[stack->a_size / 3];
	const int	p2 = stack->num_arr[stack->a_size * 2 / 3];
	int			idx;

	idx = 0;
	while (idx < stack->a_size)
	{
		if (stack->a_top->content < p1)
		{
			pb(stack);
			rb(stack);
		}
		else if (stack->a_top->content < p2)
		{
			pb(stack);
		}
		else
			ra(stack);
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
		rotate_a(stack, a_idx);
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

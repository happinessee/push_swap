/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 17:23:17 by hyojeong          #+#    #+#             */
/*   Updated: 2022/06/13 18:00:13 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_and_switch(int a, int b, int a_loca, int b_loca)
{
	if (a < 0)
		a = a * -1;
	if (b < 0)
		b = b * -1;
	if (a_loca < 0)
		a_loca = a_loca * -1;
	if (b_loca < 0)
		b_loca = b_loca * -1;
	if (a + b > a_loca + b_loca)
		return (1);
	else
		return (0);
}

void	rotate_equal(t_stack *stack, int *a_idx, int *b_idx)
{
	while (*a_idx > 0 && *b_idx > 0)
	{
		rr(stack);
		*a_idx = *a_idx - 1;
		*b_idx = *b_idx - 1;
	}
	while (*a_idx < 0 && *b_idx < 0)
	{
		rrr(stack);
		*a_idx = *a_idx + 1;
		*b_idx = *b_idx + 1;
	}
}

void	rotate_a(t_stack *stack, int a_idx)
{
	while (a_idx)
	{
		if (a_idx > 0)
		{
			ra(stack);
			a_idx -= 1;
		}
		else
		{
			rra(stack);
			a_idx += 1;
		}
	}
}

void	rotate_b(t_stack *stack, int b_idx)
{
	while (b_idx)
	{
		if (b_idx > 0)
		{
			rb(stack);
			b_idx -= 1;
		}
		else
		{
			rrb(stack);
			b_idx += 1;
		}
	}
}

void	sort_last(t_stack *stack)
{
	int	idx0;
	int	min;

	min = get_stack_min(stack->a_top);
	idx0 = find_moveless_idx(min, stack);
	while (idx0)
	{
		if (idx0 > 0)
		{
			ra(stack);
			idx0 -= 1;
		}
		else
		{
			rra(stack);
			idx0 += 1;
		}
	}
}

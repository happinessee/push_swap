/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 17:23:17 by hyojeong          #+#    #+#             */
/*   Updated: 2022/06/21 18:24:47 by hyojeong         ###   ########.fr       */
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
	while (*a_idx && *b_idx && *a_idx > 0 && *b_idx > 0)
	{
		rr(stack, 1);
		*a_idx = *a_idx - 1;
		*b_idx = *b_idx - 1;
	}
	while (*a_idx && *b_idx && *a_idx < 0 && *b_idx < 0)
	{
		rrr(stack, 1);
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
			ra(stack, 1);
			a_idx--;
		}
		else
		{
			rra(stack, 1);
			a_idx++;
		}
	}
}

void	rotate_b(t_stack *stack, int b_idx)
{
	while (b_idx)
	{
		if (b_idx > 0)
		{
			rb(stack, 1);
			b_idx--;
		}
		else
		{
			rrb(stack, 1);
			b_idx++;
		}
	}
}

void	sort_last(t_stack *stack)
{
	int	idx0;

	idx0 = set_loca_bot(stack);
	while (idx0)
	{
		if (idx0 > 0)
		{
			ra(stack, 1);
			idx0 -= 1;
		}
		else
		{
			rra(stack, 1);
			idx0 += 1;
		}
	}
}

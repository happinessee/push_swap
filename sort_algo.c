/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:30:18 by hyojeong          #+#    #+#             */
/*   Updated: 2022/06/06 16:04:59 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stack *stack)
{
	
}

void	devide(t_stack *stack)
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
		idx++;
	}
}
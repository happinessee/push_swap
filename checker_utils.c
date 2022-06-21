/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:31:58 by hyojeong          #+#    #+#             */
/*   Updated: 2022/06/21 18:19:19 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_check(t_stack *stack)
{
	int		idx;
	int		val;
	t_list	*tmp;

	idx = 0;
	val = stack->a_top->content;
	tmp = stack->a_top->next;
	if (stack->b_size > 0)
		error();
	while (idx < stack->a_size - 1)
	{
		if (tmp->content > val)
		{
			val = tmp->content;
			tmp = tmp->next;
		}
		else
			return (0);
		idx++;
	}
	return (1);
}

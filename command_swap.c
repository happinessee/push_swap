/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 20:18:19 by hyojeong          #+#    #+#             */
/*   Updated: 2022/06/21 18:22:09 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <unistd.h>

void	sa(t_stack *stack, int flag)
{
	int	tmp;

	if (stack->a_size < 2)
		return ;
	tmp = stack->a_top->next->content;
	stack->a_top->next->content = stack->a_top->content;
	stack->a_top->content = tmp;
	if (flag)
		write(1, "sa\n", 3);
}

void	sb(t_stack *stack, int flag)
{
	int	tmp;

	if (stack->b_size < 2)
		return ;
	tmp = stack->b_top->next->content;
	stack->b_top->next->content = stack->b_top->content;
	stack->b_top->content = tmp;
	if (flag)
		write(1, "sb\n", 3);
}

void	ss(t_stack *stack, int flag)
{
	int	tmp;

	if (stack->a_size < 2)
		return ;
	tmp = stack->a_top->next->content;
	stack->a_top->next->content = stack->a_top->content;
	stack->a_top->content = tmp;
	if (stack->b_size < 2)
		return ;
	tmp = stack->b_top->next->content;
	stack->b_top->next->content = stack->b_top->content;
	stack->b_top->content = tmp;
	if (flag)
		write(1, "ss\n", 3);
}

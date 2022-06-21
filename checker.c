/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:31:48 by hyojeong          #+#    #+#             */
/*   Updated: 2022/06/21 18:56:33 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <unistd.h>
#include <stdlib.h>

void	check_command_execute(t_stack *stack, char *com)
{
	const int	com_size = ft_strlen(com);

	if (com_size == 3)
	{
		if (com[0] == 's' && com[1] == 'a' && com[2] == '\n')
			sa(stack, 0);
		else if (com[0] == 's' && com[1] == 'b' && com[2] == '\n')
			sb(stack, 0);
		else if (com[0] == 's' && com[1] == 's' && com[2] == '\n')
			ss(stack, 0);
		else if (com[0] == 'p' && com[1] == 'a' && com[2] == '\n')
			pa(stack, 0);
		else if (com[0] == 'p' && com[1] == 'b' && com[2] == '\n')
			pb(stack, 0);
		else if (com[0] == 'r' && com[1] == 'a' && com[2] == '\n')
			ra(stack, 0);
		else if (com[0] == 'r' && com[1] == 'b' && com[2] == '\n')
			rb(stack, 0);
		else if (com[0] == 'r' && com[1] == 'r' && com[2] == '\n')
			rr(stack, 0);
		else
			error();
	}
	else
		check_command_execute2(stack, com, com_size);
}

void	check_command_execute2(t_stack *stack, char *com, int size)
{
	if (size == 4)
	{
		if (com[0] == 'r' && com[1] == 'r' && com[2] == 'a' && com[3] == '\n')
			rra(stack, 0);
		else if (com[0] == 'r' && com[1] == 'r' && \
				com[2] == 'b' && com[3] == '\n')
			rrb(stack, 0);
		else if (com[0] == 'r' && com[1] == 'r' && \
				com[2] == 'r' && com[3] == '\n')
			rrr(stack, 0);
		else
			error();
	}
	else
		error();
}

void	calc(t_stack *stack)
{
	if (sort_check(stack))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

void	receive_and_check(t_stack *stack)
{
	char	*str_set;
	int		idx;

	idx = 0;
	str_set = malloc(sizeof(char) * 5);
	if (str_set == 0)
		return ;
	str_set = get_next_line(0);
	while (str_set)
	{
		check_command_execute(stack, str_set);
		free(str_set);
		str_set = get_next_line(0);
	}
}

int	main(int argc, char **argv)
{
	t_stack	stack;
	int		*num_arr;
	int		size;
	int		idx;

	idx = 0;
	size = get_size(argc, argv);
	if (argc < 2)
		return (0);
	num_arr = malloc(sizeof(int) * (size + 1));
	if (num_arr == 0)
		return (0);
	num_arr = make_num_arr(num_arr, size, argv);
	check_overlap_arr(num_arr);
	is_sorted(num_arr, size);
	stack = init_stack(get_list(num_arr, size), num_arr, size);
	receive_and_check(&stack);
	calc(&stack);
	return (0);
}

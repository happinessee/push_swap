/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:50:55 by hyojeong          #+#    #+#             */
/*   Updated: 2022/06/15 17:02:28 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_stack	stack;
	int		*num_arr;
	int		size;

	size = get_size(argc, argv);
	if (argc < 2)
		return (0);
	check_wrd(argv);
	num_arr = malloc(sizeof(int) * (size + 1));
	if (num_arr == 0)
		return (0);
	num_arr = make_num_arr(num_arr, size, argv);
	check_overlap_arr(num_arr);
	is_sorted(num_arr, size);
	stack = init_stack(get_list(num_arr, size), num_arr, size);
	sort(&stack);
	ft_lstclear(stack.a_top);
	free(num_arr);
	return (0);
}

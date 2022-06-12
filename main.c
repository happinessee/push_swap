/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:50:55 by hyojeong          #+#    #+#             */
/*   Updated: 2022/06/12 13:42:27 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_stack	*stack;
	int		*num_arr;
	int		size;

	size = get_size(argc, argv);
	if (argc < 2)
		return (0);
	num_arr = malloc(sizeof(int) * (get_size(argc, argv) + 1));
	if (num_arr)
		return (0);
	num_arr = make_num_arr(num_arr, size, argv);
	check_arr(num_arr);
	num_arr = pre_process(num_arr);
	is_sorted(num_arr, size);
	stack = init_stack(get_list(num_arr, size), size);
	sort(stack);
	return (0);
}
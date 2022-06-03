/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_init2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 18:23:17 by hyojeong          #+#    #+#             */
/*   Updated: 2022/06/03 18:36:27 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <unistd.h>

void	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	check_arr(int *num_arr)
{
	int	idx;
	int	idx2;

	idx = 0;
	while (num_arr[idx + 1])
	{
		idx2 = idx + 1;
		if (!(ft_isdigit(num_arr[idx])))
			error();
		while (num_arr[idx2])
		{
			if (num_arr[idx] == num_arr[idx2])
				error();
			idx2++;
		}
		idx++;
	}
}

void	is_sorted(int *num_arr, int size)
{
	int	idx;
	int	max;
	int	tmp;
	int	cnt;

	idx = 0;
	max = 0;
	cnt = 0;
	while (num_arr[idx])
	{
		tmp = num_arr[idx];
		if (tmp > max)
		{
			max = tmp;
			cnt += 1;
		}
		else
			return ;
		idx++;
	}
	if (cnt == size)
		exit(0);
}

int	*pre_process(int *num_arr, int size)
{
	int	i;
	int	j;
	int	min;

	i = 0;
	j = 0;
	min = 0;
	while (num_arr[i])
	{
		while (num_arr[j])
		{
			
		}
	}
}
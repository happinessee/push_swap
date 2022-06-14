/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_init2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 18:23:17 by hyojeong          #+#    #+#             */
/*   Updated: 2022/06/14 14:26:47 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <unistd.h>
#include <stdlib.h>

void	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	check_overlap_arr(int *num_arr)
{
	int	idx;
	int	idx2;

	idx = 0;
	while (num_arr[idx + 1])
	{
		idx2 = idx + 1;
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

void	check_wrd(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!(ft_isdigit(argv[i][j]) || argv[i][j] == ' '\
				|| argv[i][j] == '+' || argv[i][j] == '-'))
				error();
			j++;
		}
		i++;
	}
}

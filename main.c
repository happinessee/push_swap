/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:50:55 by hyojeong          #+#    #+#             */
/*   Updated: 2022/05/31 19:33:57 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <unistd.h>
#include <stdlib.h>

/* for check */
#include <stdio.h>

void	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	get_size(int argc, char **argv)
{
	int		cnt;
	int		idx;

	cnt = 0;
	idx = 1;
	while (idx < argc)
	{
		if (ft_strlen(argv[idx]) > 1)
			cnt += count_words(argv[idx], '\n');
		else
			cnt += 1;
		idx++;
	}
	return (cnt);
}

int	*make_num_arr(int *num_arr, int size, char **argv)
{
	int		idx;
	int		cnt;
	int		i;
	char	**tmp_str;

	idx = 0;
	cnt = 0;
	while (++idx <= size)
	{
		if (ft_strlen(argv[idx]) > 1)
		{
			i = -1;
			tmp_str = ft_split(argv[idx], '\n');
			while (tmp_str[++i])
			{
				num_arr[cnt] = ft_atoi(tmp_str[i]);
				cnt++;
			}
		}
		else
			num_arr[cnt] = ft_atoi(argv[idx]);
		cnt++;
	}
	return (num_arr);
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
		idx++;
	}
	if (cnt == size)
		exit(0);
}

int	main(int argc, char **argv)
{
	int		*num_arr;
	int		size;

	size = get_size(argc, argv);

	if (argc < 2)
		error();
	num_arr = malloc(sizeof(int) * (get_size(argc, argv) + 1));
	num_arr = make_num_arr(num_arr, size, argv);
	check_arr(num_arr);
	is_sorted(num_arr, size);
	
	return (0);
}
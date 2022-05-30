/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:50:55 by hyojeong          #+#    #+#             */
/*   Updated: 2022/05/30 16:37:06 by hyojeong         ###   ########.fr       */
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

int	get_size(int argc, char **argv)
{
	int		cnt;
	int		idx;

	cnt = 0;
	idx = 1;
	while (idx < argc - 1)
	{
		if (ft_strlen(argv[idx]) > 1)
		{
			cnt += 1;
		}
		else
		{
			cnt += count_words(argv[idx], '\n');
		}
		idx++;
	}
	return (cnt);
}

int	*make_num_arr(int *num_arr, int size, char **argv)
{
	int		idx;
	int		cnt;
	char	**tmp_str;

	idx = 1;
	cnt = 0;
	while (idx < size)
	{
		if (ft_strlen(argv[idx]) > 1)
		{

		}
		else
		{
			num_arr[cnt] = ft_atoi(argv[idx]);
		}
	}
}

int	main(int argc, char **argv)
{
	int		*num_arr;
	int		size;

	size = get_size(argc, argv);

	if (argc < 2)
		error();
	num_arr = malloc(sizeof(int) * (get_size(argc, argv) + 1));
	
}
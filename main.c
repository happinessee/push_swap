/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:50:55 by hyojeong          #+#    #+#             */
/*   Updated: 2022/05/30 15:13:11 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <unistd.h>
#include <stdlib.h>

void	error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

int	main(int argc, char **argv)
{
	int		*num_arr;
	char	**tmp_str;
	int		idx;

	idx = 1;
	if (argc < 2)
		error();
	while (1)
	{
		if (ft_strlen(argv[idx]) > 1)
		{
			tmp_str = ft_split(ft_strlen(argv[idx]), ' ');
		}
		else
		{
			num_arr = ft_atoi(argv[idx]);
		}
	}
}
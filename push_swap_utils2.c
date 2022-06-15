/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 16:25:09 by hyojeong          #+#    #+#             */
/*   Updated: 2022/06/15 17:06:12 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*sort_num_arr(int *num_arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	tmp = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (num_arr[j] > num_arr[j + 1])
			{
				tmp = num_arr[j];
				num_arr[j] = num_arr[j + 1];
				num_arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	return (num_arr);
}
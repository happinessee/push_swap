/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 14:01:56 by hyojeong          #+#    #+#             */
/*   Updated: 2022/05/30 14:27:56 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stddef.h>

size_t	ft_strlen(const char *s)
{
	size_t	cnt;

	cnt = 0;
	while (s[cnt])
		cnt++;
	return (cnt);
}

static int	is_space(int c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int		idx;
	int		sign;
	int		result;

	result = 0;
	idx = 0;
	sign = 1;
	while (str[idx] && is_space(str[idx]))
		idx++;
	if (str[idx] == '+' || str[idx] == '-')
	{
		if (str[idx] == '-')
			sign *= -1;
		idx++;
	}
	while (str[idx] && ft_isdigit(str[idx]))
	{
		result = result * 10 + str[idx] - '0';
		idx++;
	}
	return (result * sign);
}

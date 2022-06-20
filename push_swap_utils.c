/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 14:01:56 by hyojeong          #+#    #+#             */
/*   Updated: 2022/06/20 17:30:16 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stddef.h>
#include <stdlib.h>

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
	int			idx;
	int			sign;
	long long	result;

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
	if (result * sign < -2147483648 || result * sign > 2147483647)
		error();
	return (result * sign);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

void	ft_lstclear(t_list *lst, int size)
{
	t_list	*tmp;
	int		idx;

	idx = 0;
	tmp = lst;
	while (idx < size - 3)
	{
		tmp = (lst)->next;
		free(lst);
		lst = tmp;
	}
	printf("lstclear ok\n");
	lst = 0;
}

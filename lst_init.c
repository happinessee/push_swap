/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 18:19:59 by hyojeong          #+#    #+#             */
/*   Updated: 2022/06/21 17:05:53 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdlib.h>

int	get_size(int argc, char **argv)
{
	int		cnt;
	int		idx;

	cnt = 0;
	idx = 1;
	while (idx < argc)
	{
		if (ft_strlen(argv[idx]) > 1)
		{
			if (count_words(argv[idx], ' ') > 0)
				cnt += count_words(argv[idx], ' ');
			else
				error();
		}
		else
			cnt += 1;
		idx++;
	}
	return (cnt);
}

void	clear(char **str)
{
	size_t	idx;

	idx = 0;
	while (str[idx])
	{
		free(str[idx]);
		str[idx] = 0;
		idx++;
	}
	free(str);
	str = 0;
}

int	*make_num_arr(int *num_arr, int size, char **argv)
{
	int		idx;
	int		cnt;
	int		i;
	char	**tmp_str;

	idx = 1;
	cnt = 0;
	while (cnt < size)
	{
		if (ft_strlen(argv[idx]) > 1)
		{
			i = -1;
			tmp_str = ft_split(argv[idx], ' ');
			while (tmp_str[++i])
				num_arr[cnt++] = ft_atoi(tmp_str[i]);
			clear(tmp_str);
		}
		else
			num_arr[cnt++] = ft_atoi(argv[idx]);
		idx++;
	}
	return (num_arr);
}

t_list	*get_list(int *num_arr, int size)
{
	t_list	*list;
	t_list	*tmp;
	t_list	*tmp2;
	int		idx;

	idx = 1;
	list = (t_list *)malloc(sizeof(t_list));
	list->content = num_arr[0];
	list->prev = 0;
	tmp = list;
	while (idx < size)
	{
		tmp2 = (t_list *)malloc(sizeof(t_list));
		tmp2->content = num_arr[idx];
		tmp2->prev = list;
		list->next = tmp2;
		list = list->next;
		idx++;
	}
	list->next = tmp;
	tmp = list;
	list->next->prev = tmp;
	list = list->next;
	return (list);
}

t_stack	init_stack(t_list *list, int *num_arr, int size)
{
	t_stack	stack;

	stack.num_arr = sort_num_arr(num_arr, size);
	stack.a_top = list;
	stack.a_size = size;
	stack.a_bot = list->prev;
	stack.b_bot = 0;
	stack.b_top = 0;
	stack.b_size = 0;
	return (stack);
}

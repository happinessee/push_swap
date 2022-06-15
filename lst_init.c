/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 18:19:59 by hyojeong          #+#    #+#             */
/*   Updated: 2022/06/15 17:03:59 by hyojeong         ###   ########.fr       */
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
			cnt += count_words(argv[idx], ' ');
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
	int		idx;

	idx = 1;
	list = (t_list *)malloc(sizeof(t_list));
	list->content = num_arr[0];
	tmp = list;
	while (idx < size)
	{
		list->next = (t_list *)malloc(sizeof(t_list));
		list = list->next;
		list->content = num_arr[idx];
		idx++;
	}
	list->next = 0;
	return (tmp);
}

t_stack	init_stack(t_list *list, int *num_arr, int size)
{
	t_stack	stack;

	stack.num_arr = sort_num_arr(num_arr, size);
	stack.a_top = list;
	stack.a_size = size;
	while (list->next)
		list = list->next;
	stack.a_bot = list;
	stack.b_bot = 0;
	stack.b_top = 0;
	stack.b_size = 0;
	return (stack);
}

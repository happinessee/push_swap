/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:50:55 by hyojeong          #+#    #+#             */
/*   Updated: 2022/05/30 14:18:15 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <unistd.h>
#include <stdlib.h>

void	error(char *err_msg)
{
	write(1, err_msg, ft_strlen(err_msg));
	exit(1);
}

int	main(int argc, char **argv)
{
	int	*num_arr;

	if (argc < 2)
		error("There must be at least three parameters.\n");
	
}
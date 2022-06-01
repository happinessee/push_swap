/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:49:09 by hyojeong          #+#    #+#             */
/*   Updated: 2022/06/01 16:05:13 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>

typedef struct s_list
{
	struct s_list	*next;
	int				content;
}	t_list;

typedef struct s_stack
{
	t_list	*a_top;
	t_list	*a_bot;
	int		a_size;
	
	t_list	*b_top;
	t_list	*b_bot;
	int		b_size;
}	t_stack;

/* commands */


/* utils */
void	error(void);
size_t	count_words(char *str, char c);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:49:09 by hyojeong          #+#    #+#             */
/*   Updated: 2022/06/08 16:31:05 by hyojeong         ###   ########.fr       */
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
void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stack);
void	pa(t_stack *stack);
void	pb(t_stack *stack);
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *stack);
void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rrr(t_stack *stack);

/* sort */
void	devide_init(t_stack *stack);
void	sort_basic3(t_stack *stack);
void	sort_basic2(t_stack *stack);
t_list	*get_stack_min(t_list *lst);
t_list	*get_stack_max(t_list *lst);
int		find_moveless_idx(int num, int tmp, t_stack *stack);

/* check */
void	is_sorted(int *num_arr, int size);
void	check_arr(int *num_arr);
int		get_size(int argc, char **argv);
void	clear(char **str);

int		*make_num_arr(int *num_arr, int size, char **argv);
t_list	*get_list(int *num_arr, int size);
t_stack	*init_stack(t_list *list, int size);
int		*pre_process(int *num_arr);

/* utils */
void	error(void);
size_t	count_words(char *str, char c);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);

#endif
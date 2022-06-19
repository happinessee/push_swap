/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojeong <hyojeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:49:09 by hyojeong          #+#    #+#             */
/*   Updated: 2022/06/19 16:43:49 by hyojeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>

/* need del */
# include <stdio.h>

typedef struct s_list
{
	struct s_list	*next;
	struct s_list	*prev;
	int				content;
}	t_list;

typedef struct s_stack
{
	int		*num_arr;

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
void	sort(t_stack *stack);
void	sort_last(t_stack *stack);
void	devide_init(t_stack *stack);
void	sort_basic3(t_stack *stack);
void	sort_basic2(t_stack *stack);
int		get_stack_min(t_list *lst);
int		get_stack_max(t_list *lst);
int		find_moveless_idx(int tmp, t_stack *stack);
int		check_and_switch(int a, int b, int a_loca, int b_loca);
void	get_min_commands(t_stack *stack, int *a_idx, int *b_idx);
void	rotate_equal(t_stack *stack, int *a_idx, int *b_idx);
void	rotate_a(t_stack *stack, int a_idx);
void	rotate_b(t_stack *stack, int b_idx);
int		set_loca(int num, t_stack *stack);
int		set_loca_bot(t_stack *stack);
int		set_loca_mid(int num, t_stack *stack);
int		set_loca_top(t_stack *stack);
int		make_idx_best(int idx, t_stack *stack);

/* check */
void	is_sorted(int *num_arr, int size);
void	check_overlap_arr(int *num_arr);
int		get_size(int argc, char **argv);
void	clear(char **str);

int		*make_num_arr(int *num_arr, int size, char **argv);
t_list	*get_list(int *num_arr, int size);
t_stack	init_stack(t_list *list, int *num_arr, int size);

/* utils */
void	error(void);
void	check_wrd(char **argv);
size_t	count_words(char *str, char c);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
void	ft_lstclear(t_list *lst);
int		*sort_num_arr(int *num_arr, int size);
#endif
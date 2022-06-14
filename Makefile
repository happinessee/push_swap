NAME = push_swap
NAME_BONUS = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRCS =	main.c \
		ft_split.c \
		push_swap_utils.c \
		command_push.c \
		command_rr.c \
		command_rrr.c \
		command_swap.c \
		lst_init.c \
		lst_init2.c \
		sort_algo.c \
		sort_algo2.c \
		sort_algo3.c \
		sort_algo4.c

SRCS_BNS =	checker.c \
			checker_utils.c

INCS = push_swap.h

OBJS = $(SRCS:%.c=%.o)

OBJS_BNS = $(SRCS_BNS:%.c=%.o)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I .

$(NAME) : $(OBJS)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJS) 

$(NAME_BONUS) : $(OBJS_BNS)

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re :
	make fclean
	make all

bonus : $(NAME_BONUS)

.PHONY : all clean re bonus fclean

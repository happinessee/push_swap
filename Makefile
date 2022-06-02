NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS =	main.c \
		ft_split.c \
		push_swap_utils.c \
		command_push.c \
		command_rr.c \
		command_rrr.c \
		command_swap.c \
		

INCS = push_swap.h

OBJS = $(SRCS:%.c=%.o)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I .

$(NAME) : $(OBJS)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJS)

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re :
	make fclean
	make all

bonus : $(NAME)

.PHONY : all clean re bonus fclean

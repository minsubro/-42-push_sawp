CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = mandatory/command.c			\
	   mandatory/indexing.c			\
	   mandatory/make_stack.c		\
	   mandatory/memory_cont.c		\
	   mandatory/push_swap_main.c	\
	   mandatory/quick_sort.c		\
	   mandatory/split.c			\
	   mandatory/a_to_b.c			\
	   mandatory/exception_case.c	\
	   mandatory/find_idx.c			\
	   mandatory/greed.c			\
	   mandatory/make_stack_util.c	\
	   mandatory/stack_rotate.c		\
	   mandatory/command2.c

NAME = push_swap
OBJS = $(SRCS:.c=.o)
RM = rm -rf


all : $(NAME)

$(NAME) :
	$(CC) $(SRCS) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re :
	make fclean
	make all

bonus : $(NAME)

.PHONY: all clean fclean re
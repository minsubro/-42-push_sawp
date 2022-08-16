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

BONUS_SRC = bonus/command_bonus.c				\
			bonus/command2_bonus.c				\
			bonus/checker_main_bonus.c			\
			bonus/command_input_bonus.c			\
			bonus/make_stack_bonus.c			\
			bonus/make_stack_util_bonus.c		\
			bonus/memory_bonus.c				\
			bonus/split_bonus.c					\
			bonus/get_next_line_bonus.c			\
			bonus/get_next_line_utils_bonus.c	

NAME = push_swap
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRC:.c=.o)
BONUS_NAME = checker

RM = rm -f


all : $(NAME)

bonus : $(BONUS_NAME)

$(NAME) : $(OBJS) 
	$(CC) $^ -o $(NAME)

$(BONUS_NAME) : $(BONUS_OBJS)
	$(CC) $^ -o $(BONUS_NAME)
 
%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean :
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean : clean
	$(RM) $(NAME) $(BONUS_NAME)

re :
	make fclean
	make all

.PHONY: all clean fclean re bonus
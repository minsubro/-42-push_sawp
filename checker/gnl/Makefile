CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = get_next_line_bonus.c		\
	   get_next_line_utils_bonus.c	\

HEADER = get_next_line_bonus.h
NAME = libgnl.a
OBJS = $(SRCS:.c=.o)
RM = rm -rf

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $^

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re :
	make fclean
	make all

bonus : $(NAME)

.PHONY: all clean fclean re
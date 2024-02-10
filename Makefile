CC = cc

CFLAGS = -g -Wall -Wextra -Werror

NAME = push_swap

FUNC =	push_swap.c push_swap_utils.c list.c list2.c utils/checkerror.c utils/printf_utils.c utils/printf.c utils/split.c utils/split_utils.c \
		sort/banes_sort.c sort/quick_sort.c sort/sort_utils.c instructions/push.c instructions/reverse.c instructions/rotate.c instructions/swap.c

OBJS = ${FUNC:.c=.o} 

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}
	chmod +x ${NAME}

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: 	${NAME}

clean:	
		rm -f ${OBJS}

fclean:	clean
		rm -f ${NAME}

re:	fclean all

.PHONY: all clean fclean re
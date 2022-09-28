NAME = philo
SRC =	philo.c \
		events.c \
		routine.c \
		utils.c \
		time.c \
		actions.c \

OBJS = ${SRC:.c=.o}

%.o: %.c
	$(CC) $(CFLAGS) -g -c $< -o ${<:.c=.o}

CC		= gcc
RM		= rm -f
CFLAGS = -Wall -Wextra -Werror

$(NAME): ${OBJS}
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re:		fclean all

.PHONY: clean fclean re bonus
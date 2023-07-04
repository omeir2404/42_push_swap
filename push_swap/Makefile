NAME = push_swap
SOURCES = push_swap.c srcs/check_input.c srcs/swap.c srcs/push.c srcs/rotate.c \
			srcs/reverse_rotate.c srcs/checks.c srcs/array.c srcs/ft_atoi.c\
			srcs/sort_2_3.c srcs/to_b.c srcs/sort_4_5.c srcs/utils2.c srcs/utils.c \
			srcs/put_back.c srcs/radix_try.c srcs/put_back_utils.c srcs/put_back_utils2.c \
			srcs/ft_lstsize.c srcs/ft_lstlast.c srcs/ft_lstadd_back.c \
			srcs/lstnew_ps.c srcs/ft_split.c

OBJECTS	=	$(SOURCES:.c=.o)
CC	=	gcc
CFLAGS = -Wall -Wextra -Werror -g
all:		$(NAME)


$(NAME):	$(OBJECTS)
			$(CC) $(OBJECTS) -o $(NAME)

clean:		
			rm -f $(OBJECTS)

$(LIBFT):

fclean:		clean
			rm -f $(NAME)

re:			fclean $(NAME)

.PHONY:	all clean fclean re

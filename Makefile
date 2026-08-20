NAME		=	[lay]
CC			=	nasm
FLAGS		=	-felf64 -g

SRCS		=	play.s
OBJS		=	$(SRCS:%.s=%.o)

all:	$(NAME)

$(NAME): $(SRCS)
	$(CC) $(SRCS) $(FLAGS) $(LIBS) && ld play.o

clean:
	@ rm -rf $(OBJS)

fclean: clean
	@ rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
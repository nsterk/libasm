NAME		=	libasm.a
HEADER		=	libasm.h
CC			=	nasm
FLAGS		=	-felf64 -g
OPTIONS		=	ar rcs

SRCS		:=	ft_strlen.s

OBJS		=	$(SRCS:%.s=%.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		$(OPTIONS) $(NAME) $(OBJS)

%.o: %.s	$(HEADER)
	@$(CC) $(FLAGS) -o $@ $<

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re %.o


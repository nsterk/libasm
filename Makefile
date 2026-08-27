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

test:	$(NAME)
	@gcc main.c -g -L. -lasm -o test
	@./test

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: @fclean all

.PHONY: all clean fclean re %.o


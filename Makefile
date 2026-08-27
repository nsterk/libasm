NAME		=	libasm.a
HEADER		=	libasm.h
CC			=	nasm
FLAGS		=	-felf64 -g
OPTIONS		=	ar rcs

SRCS		:=	ft_strlen.s ft_write.s
TEST_SRC	:=	main.c

OBJS		=	$(SRCS:%.s=%.o)

all:		$(NAME)

$(NAME):	$(OBJS)
	$(OPTIONS) $(NAME) $(OBJS)

%.o: %.s	$(HEADER)
	@$(CC) $(FLAGS) -o $@ $<

test:	$(TEST_SRC) $(NAME) 
	@gcc main.c -g -fsanitize=address -L. -lasm -o test
	@./test

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: @fclean all

.PHONY: all clean fclean re %.o


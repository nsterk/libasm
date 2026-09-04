NAME		:=	test
CFLAGS		=	-g
IFLAGS		:=	-I lib/inc
LIBASM_A	:= 	lib/libasm.a

SRCS		:=	main.c \
				tests/test_strlen.c \
				tests/test_write.c \
				tests/test_read.c \
				tests/test_strdup.c \
				tests/test_strcmp.c \
				tests/test_strcpy.c

OBJS		=	$(SRCS:%.c=%.o)

all:	$(LIBASM_A) $(NAME)

$(NAME): $(LIBASM_A) $(OBJS)
	@gcc $(OBJS) $(LIBASM_A) $(CFLAGS) $(IFLAGS) -o $(NAME)

%.o: %.c
	@gcc $(CFLAGS) -c $< $(IFLAGS) -o $@

run:	

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: @fclean all

.PHONY: clean fclean re


NAME		:=	test

CFLAGS		=	-g
IFLAGS		:=	-I lib/libasm/inc
LIBASM_A	:= 	lib/libasm/libasm.a

SRCS		:=	main.c

OBJS		=	$(SRCS:%.c=%.o)

all:	$(LIBASM_A) $(NAME)

$(NAME): $(LIBASM_A) $(OBJS)
	@gcc $(OBJS) $(LIBASM_A) $(CFLAGS) $(IFLAGS) -o $(NAME)

%.o: %.c
	@gcc $(CFLAGS) -c $< $(IFLAGS) -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: @fclean all

.PHONY: clean fclean re %.o


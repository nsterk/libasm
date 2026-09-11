NAME				:=	test
NAME_BONUS	:=	test_bonus
CFLAGS			:=	-g
IFLAGS			:=	-I lib/inc
LIBASM_A		:= 	lib/libasm.a

VPATH 			:= tests

SRCS	:=	main.c \
			tests/test_strlen.c \
			tests/test_write.c \
			tests/test_read.c \
			tests/test_strdup.c \
			tests/test_strcmp.c \
			tests/test_strcpy.c \

BONUS_SRCS := main_bonus.c \
			tests/test_list_size.c \
			tests/test_list_push_front.c

OBJS					:=	$(SRCS:%.c=%.o)
BONUS_OBJS		:=	$(BONUS_SRCS:%.c=%.o)

all: $(NAME) $(LIBASM_A)

$(NAME): $(OBJS)
	@gcc $(OBJS) $(LIBASM_A) $(CFLAGS) $(IFLAGS) -o $(NAME)

%.o: %.c
	@gcc $(CFLAGS) -c $< $(IFLAGS) -o $@

$(LIBASM_A):
	$(MAKE) -C lib

bonus: $(LIBASM_A) $(NAME_BONUS)

$(NAME_BONUS): $(BONUS_OBJS)
	@gcc $(BONUS_OBJS) $(LIBASM_A) $(CFLAGS) $(IFLAGS) -o $(NAME_BONUS)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re


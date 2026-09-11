NAME		=	libasm.a
HEADER		=	inc/libasm.h
CC			=	nasm
FLAGS		=	-felf64 -g
OPTIONS		=	ar rcs

SRCS :=	src/ft_strlen.s \
		src/ft_write.s \
		src/ft_read.s \
		src/ft_strcmp.s \
		src/ft_strcpy.s \
		src/ft_strdup.s 

BONUS_SRCS	:=	src/ft_list_size.s \
				src/ft_list_push_front.s \
				src/ft_atoi_base.s

OBJS				:=	$(SRCS:%.s=%.o)
BONUS_OBJS	:=	$(BONUS_SRCS:%.s=%.o)

all:		$(NAME)

$(NAME):	$(OBJS)
	$(OPTIONS) $(NAME) $(OBJS)

%.o: %.s	$(HEADER)
	@$(CC) $(FLAGS) -o $@ $<

bonus:	$(OBJS) $(BONUS_OBJS)
	$(OPTIONS) $(NAME) ${OBJS} $(BONUS_OBJS)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re %.o


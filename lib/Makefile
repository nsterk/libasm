NAME		=	libasm.a
HEADER		=	inc/libasm.h
CC			=	nasm
FLAGS		=	-felf64 -g
OPTIONS		=	ar rcs

SRCS		=	src/ft_strlen.s \
				src/ft_write.s \
				src/ft_read.s \
				src/ft_strcmp.s \
				src/ft_strcpy.s \
				src/ft_strdup.s

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


NAME		=	libasm.a
HEADER		=	libasm.h
CC			=	nasm
FLAGS		=	-felf64 -g
OPTIONS		=	ar rcs


SRCS		:=	srcs/ft_strlen.s

OBJS		=	$(SRCS:%.s=%.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		$(OPTIONS) $(NAME) $(OBJS)

%.o: %.s	$(HEADER)
	@printf "Creating Libasm objects... %-33.33s\r" $@
	@$(CC) -c $(FLAGS) -o $@ $<


clean:
	@ -rm f $(OBJS)

fclean: clean
	@ -rm f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus %.o

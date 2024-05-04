.PHONY: all $(NAME) bonus clean fclean re

NAME := libftprintf.a

CC := cc

AR := ar rcs

CFLAGS := -Wall -Wextra -Werror -g

LIBFT := libft

SRCS := ft_printf.c ft_printf_utils.c \

OBJS := $(SRCS:.c=.o)

# SRCS_BONUS := 

# OBJS_BONUS := $(SRCS_BONUS:.c=.o)

all:	$(NAME)

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -c $*.c -o $@

# $(OBJS_BONUS): $(SRCS_BONUS)
# 	$(CC) $(CFLAGS) -c $*.c -o $@

$(NAME): $(OBJS)
	make all -C $(LIBFT)
	cp $(LIBFT)/*.o .
	ar rcs $(NAME) *.o

# bonus: all

clean:
	make clean -C $(LIBFT)
	rm -f ./*.o

fclean:	clean
	make fclean -C $(LIBFT)
	rm -f ./*.a

re:	fclean all

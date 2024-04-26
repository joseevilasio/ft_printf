.PHONY: all $(NAME) bonus clean fclean re

NAME := libftprintf.a

CC := cc

AR := ar rcs

CFLAGS := -Wall -Wextra -Werror -g

LIBFT := libft

SRCS := ft_printf.c ft_putchar.c ft_putnbr.c ft_putnbrhex.c \
	ft_putpointer.c ft_putstr.c ft_putunsignednbr.c \

OBJS := $(SRCS:.c=.o)

SRCS_BONUS := ft_isflag_bonus.c ft_length_flags_bonus.c ft_parserflag_bonus.c \
	ft_printf_bonus.c ft_putchar_bonus.c ft_putnbr_bonus.c \
	ft_putnbrhex_bonus.c ft_putnchar_bonus.c ft_putpointer_bonus.c \
	ft_putstr_bonus.c ft_putunsignednbr_bonus.c \

OBJS_BONUS := $(SRCS_BONUS:.c=.o)

all:	$(NAME)

$(OBJS):	$(SRCS)

$(OBJS_BONUS):	$(SRCS_BONUS)

$(NAME): $(OBJS)
	make all -C $(LIBFT)
	mv $(LIBFT)/*.o .
	ar rcs $(NAME) *.o

bonus: $(OBJS_BONUS) all
	rm -f ft_printf.o
	rm -f libftprintf.a
	ar rcs $(NAME) *.o

clean:
	make clean -C $(LIBFT)
	rm -f ./*.o

fclean:	clean
	make fclean -C $(LIBFT)
	rm -f ./*.a

re:	fclean all

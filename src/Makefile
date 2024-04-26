.PHONY: all $(NAME) bonus clean fclean re libft

NAME := libftprintf.a

CC := cc

AR := ar rcs

CFLAGS := -Wall -Wextra -Werror -g

LIBFT := libft

SRCS := ft_printf.c ft_putchar.c ft_putnbr.c ft_putnbrhex.c \
	ft_putpointer.c ft_putstr.c ft_putunsignednbr.c \

OBJS := $(SRCS:.c=.o)

SRCS_BONUS := bonus/ft_isflag_bonus.c bonus/ft_length_flags_bonus.c \
	bonus/ft_parserflag_bonus.c bonus/ft_printf_bonus.c \
	bonus/ft_putchar_bonus.c bonus/ft_putnbr_bonus.c bonus/ft_putnbrhex_bonus.c \
	bonus/ft_putnchar_bonus.c bonus/ft_putpointer_bonus.c bonus/ft_putstr_bonus.c \
	bonus/ft_putunsignednbr_bonus.c \

OBJS_BONUS := $(SRCS_BONUS:.c=.o)


$(OBJS):	$(SRCS)

$(OBJS_BONUS):	$(SRCS_BONUS)

all:	$(NAME)

$(NAME): $(OBJS)
	make bonus -C $(LIBFT)
	mv $(LIBFT)/*.o .
	ar rcs $(NAME) *.o

bonus: $(OBJS_BONUS) all
	rm -f ft_printf.o
	# mv bonus/*.o .
	# ar rcs $(NAME) *.o

clean:
	make clean -C $(LIBFT)
	rm -f ./*.o
	rm -f ./bonus/*.o

fclean:	clean
	make fclean -C $(LIBFT)
	rm -f ./*.a

re:	fclean all

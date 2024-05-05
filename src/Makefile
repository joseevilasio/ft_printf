.PHONY: all $(NAME) bonus clean fclean re

NAME := libftprintf.a

CC := cc

AR := ar rcs

CFLAGS := -Wall -Wextra -Werror -g

LIBFT := libft

SRCS := ft_printf.c ft_uitoa_hex.c ft_ptoa.c ft_uitoa.c  ft_printf_utils.c \

OBJS := $(SRCS:.c=.o)

# SRCS_BONUS := _bonus/ft_isflag_bonus.c _bonus/ft_length_flags_bonus.c \
# 	_bonus/ft_parserflag_bonus.c _bonus/ft_printf_bonus.c \
# 	_bonus/ft_printf_bonus.h _bonus/ft_putchar_bonus.c \
# 	_bonus/ft_putnbr_bonus.c _bonus/ft_putnbrhex_bonus.c \
# 	_bonus/ft_putnchar_bonus.c _bonus/ft_putpointer_bonus.c \
# 	_bonus/ft_putstr_bonus.c _bonus/ft_putunsignednbr_bonus.c \

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

# bonus: $(OBJS_BONUS)
# 	rm -f $(OBJS)
# 	cp $(LIBFT)/*.o .
# 	cp _bonus/*.o .
# 	ar rcs $(NAME) ./*.o

clean:
	make clean -C $(LIBFT)
	rm -f ./*.o

fclean:	clean
	make fclean -C $(LIBFT)
	rm -f ./*.a

re:	fclean all

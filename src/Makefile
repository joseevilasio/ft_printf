.PHONY: all obj_files.o $(NAME) clean fclean re libft

NAME := libftprintf.a

all:	$(NAME)

obj_files.o:
	@for file_source in ./*.c; do \
		file_obj="./$$(basename $${file_source%.c}).o"; \
		cc -Wall -Wextra -Werror -g -c "$${file_source}" -o "$${file_obj}"; \
	done

$(NAME):	libft obj_files.o
	@ar x ./libft/libft.a
	@ar rcs ./$(NAME) ./*.o

clean:
	@find ./ -name '*.o' -exec rm -f {} \;

fclean:	clean
	@find ./ -name '*.out' -exec rm -f {} \;
	@find ./ -name '*.a' -exec rm -f {} \;
	@find ./ -name '$(NAME)' -exec rm -f {} \;	

re:	fclean all

libft:
	@for file_source in ./libft/*.c; do \
		file_obj="./libft/$$(basename $${file_source%.c}).o"; \
		cc -Wall -Wextra -Werror -g -c "$${file_source}" -o "$${file_obj}"; \
	done
	@ar rcs ./libft/libft.a ./libft/*.o
	@make clean

libftprintf_bonus:
	@for file_source in ./bonus/*.c; do \
		file_obj="./bonus/$$(basename $${file_source%.c}).o"; \
		cc -Wall -Wextra -Werror -g -c "$${file_source}" -o "$${file_obj}"; \
	done
	@ar rcs ./bonus/libftprintf_bonus.a ./bonus/*.o
	@make clean

bonus: libft libftprintf_bonus obj_files.o
	@ar x ./libft/libft.a
	@ar x ./bonus/libftprintf_bonus.a
	@rm ft_printf.o
	@ar rcs ./$(NAME) ./*.o

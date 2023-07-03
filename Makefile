# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ozozdemi <ozozdemi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/25 13:36:27 by ozozdemi          #+#    #+#              #
#    Updated: 2023/07/03 13:43:35 by ozozdemi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		push_swap
CC =		@cc
CFLAGS =	-Wall -Wextra -Werror -g3
OBJ =		$(patsubst src%, obj%, $(SRC:.c=.o))
SRC =		src/push_swap.c \
		src/lst.c \
		src/parsing.c \
		src/instructions.c \
		src/utils.c \
		src/radix_sort.c \
		src/sort_few.c \

all:		obj ${NAME}

${NAME}:	${OBJ}
		@echo "\033[0;33m\nCOMPILING LIBFT"
		@make -sC libft/
		@echo "\033[1;32mLIBFT COMPILED\n"
		@echo "\033[0;33mCOMPILING PUSH_SWAP"
		${CC} -o ${NAME} ${OBJ} libft/libft.a
		@echo "\033[1;32mPUSH_SWAP COMPILED\n"

obj:
			@mkdir -p obj

obj/%.o:	src/%.c
			$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
		@echo "\033[0;31m\nDELETING OBJ FILES IN LIBFT"
		@make clean -sC libft/
		@rm -rf ${OBJ} obj
		@echo "\033[1;32mDONE\n"

fclean:		clean
		@echo "\033[0;31mDELETING PUSH_SWAP EXECUTABLE"
		@rm -rf ${NAME}
		@make fclean -sC libft/
		@echo "\033[1;32mDONE\n"

re:		fclean all

.PHONY:		all clean fclean re
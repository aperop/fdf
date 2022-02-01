# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/14 17:59:45 by dhawkgir          #+#    #+#              #
#    Updated: 2022/02/01 18:42:45 by dhawkgir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc

FLAGS = -g -Wall -Wextra -Werror

PATH_SRCS = sources/
PATH_INCLS = includes/

SRCS =	$(wildcard $(PATH_SRCS)*.c)

OBJ = $(SRCS:.c=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
		@ar rcs $(NAME) $?
		@printf "\t\e[1m\e[32m>>>>>>>>>>\t$(NAME) created\t<<<<<<<<<<\e[0m\n"
%.o: %.c ${PATH_INCLS}/libft.h
		@$(CC) $(FLAGS) -I ${PATH_INCLS} -c $< -o $@

bonus: $(NAME)

clean:
		@$(RM) $(OBJ)

fclean: clean
		@$(RM) $(NAME)

re: fclean all

norm:
	norminette $(PATH_SRCS) ${PATH_INCLS}

.PHONY: all bonus clean fclean re norm

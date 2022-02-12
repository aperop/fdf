# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/23 20:47:45 by dhawkgir          #+#    #+#              #
#    Updated: 2022/02/13 02:02:00 by dhawkgir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fdf

SPATH	=	src
OPATH	=	.obj
FT		=	libft
INC		=	include

SRCS	=	$(SPATH)/fdf.c		$(SPATH)/parse.c\
			$(SPATH)/utils.c	$(SPATH)/draw.c

HEADS	=	${INC}/fdf.h

FLAGS	=	-g -Wall -Wextra -Werror

OBJS	=	${SRCS:${SPATH}/%.c=${OPATH}/%.o}

all:		${NAME}

${NAME}:	${OBJS} ${FT}
				make -s -C ${FT}
				cc -I ${INC} ${OBJS} -l ft -L ${FT} -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o ${NAME}
				@printf "\t\e[5m\e[1m\e[32m>>>>>>>>>>\t${NAME} created\t<<<<<<<<<<\e[0m\n"

${OPATH}/%.o:	${SPATH}/%.c ${HEADS} | ${OPATH}
				cc ${FLAGS} -I ${INC} -I/usr/include -Imlx_linux -c $< -o $@

${OPATH}:
				@mkdir -p $@

clean:
				make -s clean -C ${FT}
				rm -rf ${OPATH}

fclean:		clean
				make -s fclean -C ${FT}
				rm -f ${NAME}
				@printf "\t\e[1m\e[31m>>>>>>>>>>\tCleaned\t<<<<<<<<<<\e[0m\n\n"

re:			fclean all

bonus:		${NAME}

norm:
				norminette ${SPATH} ${INC} ${FT}

.PHONY: all clean fclean norm re bonus

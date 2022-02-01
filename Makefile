# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/23 20:47:45 by dhawkgir          #+#    #+#              #
#    Updated: 2022/02/01 18:42:28 by dhawkgir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fdf
# NAME_B	=	checker

SPATH	=	src
OPATH	=	.obj
FT		=	libft
INC		=	include

SRCS	=	$(SPATH)/fdf.c

# SRCS_B	=	${SPATH}/checker_bonus.c	\
# 			${SPATH}/list_lib_utils.c	\
# 			${SPATH}/list_utils.c		\
# 			${SPATH}/operation_r_.c		\
# 			${SPATH}/operation_s_p_.c	\
# 			${SPATH}/parse.c

HEADS	=	${INC}/fdf.h

FLAGS	=	-g -Wall -Wextra -Werror

OBJS	=	${SRCS:${SPATH}/%.c=${OPATH}/%.o}

# OBJS_B	=	${SRCS_B:${SPATH}/%.c=${OPATH}/%.o}

all:		${NAME}

${NAME}:	${OBJS} ${FT}
				make -s -C ${FT}
				cc -I ${INC} ${OBJS} -l ft -L ${FT} -o ${NAME}
				@printf "\t\e[5m\e[1m\e[32m>>>>>>>>>>\t${NAME} created\t<<<<<<<<<<\e[0m\n"

${OPATH}/%.o:	${SPATH}/%.c ${HEADS} | ${OPATH}
				cc ${FLAGS} -I ${INC} -c $< -o $@

${OPATH}:
				@mkdir -p $@

# ${NAME_B}:	${OBJS_B} ${FT}
# 				make -s -C ${FT}
# 				cc -I ${INC} ${OBJS_B} -l ft -L ${FT} -o ${NAME_B}
# 				@printf "\t\e[5m\e[1m\e[32m>>>>>>>>>>\t${NAME_B} created\t<<<<<<<<<<\e[0m\n"


clean:
				make -s clean -C ${FT}
				rm -rf ${OPATH}

fclean:		clean
				make -s fclean -C ${FT}
				rm -f ${NAME}
				@printf "\t\e[1m\e[31m>>>>>>>>>>\tCleaned\t<<<<<<<<<<\e[0m\n\n"

re:			fclean all

# bonus:		${NAME_B}

norm:
				norminette ${SPATH} ${INC} ${FT}

.PHONY: all clean fclean norm re bonus

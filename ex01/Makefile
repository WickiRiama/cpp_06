# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makfile                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mriant <mriant@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/13 14:09:34 by mriant            #+#    #+#              #
#    Updated: 2023/01/13 14:56:57 by mriant           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = serializer

SRCS = ${addprefix srcs/, \
		 serialize.cpp}

OBJS = ${SRCS:srcs/%.cpp=build/%.o}
DEPS = ${SRCS:srcs/%.cpp=build/%.d}

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g
LFLAGS = 
IFLAGS = -I./includes -MMD

${NAME}: ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o ${NAME} ${LFLAGS}

build/%.o: srcs/%.cpp
	mkdir -p build
	${CXX} ${CXXFLAGS} -c $< -o $@ ${IFLAGS}

.PHONY: all
all: ${NAME}

.PHONY: clean
clean: 
	rm -rf build

.PHONY: fclean
fclean: clean
	rm -rf ${NAME}

.PHONY: re
re: fclean
	make -C .

-include ${DEPS}
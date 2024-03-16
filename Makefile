# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abalhamm <abalhamm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/12 18:38:57 by smuhamma          #+#    #+#              #
#    Updated: 2024/01/26 16:11:34 by abalhamm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ircserv

SRCS = Server.cpp main.cpp User_Commands.cpp Utils.cpp Channel.cpp Command.cpp

CXX = c++

OBJS = $(SRCS:.cpp=.o)

CXXFLAGS = -std=c++98 -Wall -Wextra -Werror -g3

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
	
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/18 18:20:05 by tnakas            #+#    #+#              #
#    Updated: 2025/02/20 21:52:15 by tnakas           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME        = obj/convert
SRC_DIR     = src
OBJ_DIR     = obj

SRC         = $(SRC_DIR)/main.cpp \
              $(SRC_DIR)/ScalarConverter/ScalarConverter.cpp

OBJ         = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

CC          = c++
RM          = rm -rf
STD         = c++17
CPPFLAGS    = -Wall -Wextra -Werror -std=$(STD)

all: $(NAME)

$(NAME): $(OBJ)
	mkdir -p obj
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
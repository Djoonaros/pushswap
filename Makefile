# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: djoonaros <djoonaros@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/09 03:20:20 by djoonaros         #+#    #+#              #
#    Updated: 2023/05/09 03:30:38 by djoonaros        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C		= gcc
CFLAGS	= -Wall -Werror -Wextra
NAME	= push_swap

SRC_PATH = src/
OBJ_PATH = obj/

SRC		= main.c \
		input_check.c input_check_utility.c \
		first_things.c \
		stack_functions.c \
		swap.c push.c rotate.c reverse_rotate.c \
		sort.c \
		position.c cost.c moves.c \
		utility.c
SRCS	= $(addprefix $(SRC_PATH), $(SRC))
OBJ		= $(SRC:.c=.o)
OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))
INCS	= -I ./includes/

all: $(OBJ_PATH) $(NAME) 

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 
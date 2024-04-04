# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/03 15:46:09 by rkrechun          #+#    #+#              #
#    Updated: 2024/04/04 16:08:16 by rkrechun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long


INCLUDES = -I/opt/X11/include -Imlx

GAME	= so_long.c
GAMEPATH= $(GAME)
OBJ		= $(GAMEPATH:.c=.o)

 
%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

 $(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all: $(NAME)

clean:
		@$(RM) $(OBJ)

fclean:
		@$(RM) $(NAME)
		@$(RM) $(OBJ)

.PHONY: all clean fclean
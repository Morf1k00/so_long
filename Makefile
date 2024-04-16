# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/03 15:46:09 by rkrechun          #+#    #+#              #
#    Updated: 2024/04/16 14:48:24 by rkrechun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long



GAME		= so_long.c
GAMEPATH	= $(GAME)
OBJ			= $(GAMEPATH:.c=.o)

FUNC_SRCS	= maps.c
# FUNC_DIR	
FUNC		= $(addprefix $(FUNC_SRCS))
OBJ_F		=$(OBJ_F:.c=.o)

GNL_SRCS	= gnl/get_next_line.c gnl/get_next_line_utils.c
GNL			= $(addprefix $(GNL_SRCS))
GNL_F		= $(GNL_F:.c=.o)
 
%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

 $(NAME): $(OBJ) 
	$(CC) $(OBJ) $(OBJ_F) $(GNL_F) -fsanitize=address -fno-omit-frame-pointer -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all: $(NAME)

clean:
		@$(RM) $(OBJ)

fclean:
		@$(RM) $(NAME)
		@$(RM) $(OBJ)
		@$

.PHONY: all clean fclean
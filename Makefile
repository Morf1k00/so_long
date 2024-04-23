# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/16 15:22:19 by rkrechun          #+#    #+#              #
#    Updated: 2024/04/23 13:32:28 by rkrechun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC		= gcc -g -fsanitize=address
FLAGS	= -Wall -Wextra -Werror -Imlx  #-framework OpenGL -framework AppKit
RM		= rm -rf

HEADER_SRCS	= so_long.h
HEADER_DIR	= include/
HEADER		= $(addprefix $(HEADER_DIR), $(HEADER_SRCS))

MPATH_SRCS	= map.c maps_render.c so_long.c keyhooks.c ft_printf.c move.c map_check.c \
				maps_help_check.c move_set.c
MPATH_DIR	= project/
MPATH		= $(addprefix $(MPATH_DIR), $(MPATH_SRCS))
OBJ_M		= $(MPATH:.c=.o)

FUNC_SRCS	= get_next_line.c get_next_line_utils.c 
FUNC_DIR	= gnl/
FUNC		= $(addprefix $(FUNC_DIR), $(FUNC_SRCS))
OBJ_F		= $(FUNC:.c=.o)


#LIBRARY = -Lmlx -lmlx -framework OpenGL -framework AppKit
#MINILIBX = mlx/

%.o: %.c $(HEADER) Makefile
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ_F) $(OBJ_M)
	@$(CC) $(OBJ_F) $(OBJ_M) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all: $(NAME)

clean:	
		@$(RM) $(OBJ_M)
		@$(RM) $(OBJ_F)
		@echo "$(YELLOW)Objectfile deleted!$(DEFAULT)"

fclean: 
		@$(RM) $(OBJ_M)
		@$(RM) $(OBJ_F)
		@$(RM) $(NAME)
		@echo "$(RED)All deleted!$(DEFAULT)"

re:	fclean all

.PHONY: all clean fclean re

# -lmlx -framework OpenGL -framework AppKit

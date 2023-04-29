# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: haarab <haarab@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/21 16:11:37 by haarab            #+#    #+#              #
#    Updated: 2023/02/23 18:22:33 by haarab           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = solong

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
MINI = -lmlx -lmlx -framework OpenGL -framework AppKit
MINILIB = -lmlx -lXext -lX11

OBJS =  checkmap.o scounter.o ft_exit.o ft_map.o handleGame.o image.o move_Player.o movement.o path.o so_long.o get_next_line/get_next_line.o get_next_line/get_next_line_utils.o


all: $(NAME)


$(NAME) : checkmap.c  counter.c  ft_exit.c ft_map.c handleGame.c image.c move_Player.c movement.c path.c so_long.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
	$(CC) $(CFLAGS)  -o solong checkmap.c  counter.c  ft_exit.c ft_map.c handleGame.c image.c move_Player.c movement.c path.c so_long.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c $(MINI)


clean:
	$(RM) $(OBJS)
	
fclean: clean
	$(RM) $(NAME)

re: fclean all

rungame :
		./solong ./map/map.ber
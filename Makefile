# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: haarab <haarab@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/21 16:11:37 by haarab            #+#    #+#              #
#    Updated: 2023/05/05 17:09:18 by haarab           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
MINI = -lmlx -lmlx -framework OpenGL -framework AppKit

SRC = checkmap.c size_windows.c counter.c  ft_exit.c ft_map.c handleGame.c image.c move_Player.c movement.c path.c so_long.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
OBJS =  checkmap.o size_windows.o scounter.o ft_exit.o ft_map.o handleGame.o image.o move_Player.o movement.o path.o so_long.o get_next_line/get_next_line.o get_next_line/get_next_line_utils.o


all: $(NAME)

$(NAME) : $(SRC)
	$(CC) $(CFLAGS) $(SRC) $(MINI)  -o so_long

clean:
	$(RM) $(OBJS)
	
fclean: clean
	$(RM) $(NAME)

re: fclean all

# run : $(NAME)
# 		./solong ./map/map.ber
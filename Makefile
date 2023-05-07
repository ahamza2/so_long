# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: haarab <haarab@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/21 16:11:37 by haarab            #+#    #+#              #
#    Updated: 2023/05/06 16:18:39 by haarab           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
MINI = -lmlx -lmlx -framework OpenGL -framework AppKit

SRCS = checkmap.c size_windows.c counter.c  ft_exit.c ft_map.c handlegame.c image.c move_player.c movement.c path.c so_long.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)


$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MINI) -o $(NAME)

clean:
	$(RM) $(OBJS)
	
fclean: clean
	$(RM) $(NAME)

re: fclean all

# run : $(NAME)
# 		./solong ./map/map.ber
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mntumba <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/09 19:33:14 by mntumba           #+#    #+#              #
#    Updated: 2018/01/12 09:17:03 by mntumba          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = display.c draw.c hook.c main.c parser.c\
	  libft/ft_atoi.c libft/ft_strsplit.c libft/readfile.c\

OBJ = $(SRC:.c=.o)

CFLAGS = -g -Wall -Wextra -Werror

LIB = -L/usr/local/lib -lmlx

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(CFLAGS) $(LIB) -framework OpenGL -framework Appkit $(SRC) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

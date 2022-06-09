NAME = so_long

OBJ = main.c\
		ft_itoa.c\
		put_pixel.c\
		close_window.c\
		init.c\
		move.c\
		tools.c\
		functions.c\

CC = gcc

CFAGS = -Wall -Wextra -Werror -g
%.o: %.c
	$(CC) $(CFAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

re: 
	rm -rf *.o $(NAME)
	make $(NAME)

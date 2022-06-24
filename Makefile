NAME	=	so_long
NAME_B	=	so_long_bonus
HEADER	=	so_long.h
FLAGS	=	-Wall -Wextra -Werror

SRCS =	counter.c\
		ft_printf.c\
		listener.c\
		map_init.c\
		put_pixel.c\
		ft_itoa.c\
		close_window.c\
		init.c\
		move.c\
		tools.c\
		draw.c\

SRCS_B = 	animation.c\
			close_window.c\
			counter.c\
			draw.c\
			ft_itoa.c\
			ft_printf.c\
			init.c\
			listener.c\
			load_images.c\
			locate.c\
			map_init.c\
			move.c\
			put_pixel.c\
			tools.c\

CC = gcc


FD_S = srcs/
FD_O = objs/
FD_B = bonus/
FD_O_B = objs_b/

OBJS	=	${SRCS:.c=.o}
OBJS_B	=	${SRCS_B:.c=.o}



SRCS_WD	=	$(addprefix ${FD_S}, ${SRCS})
OBJS_WD = 	$(addprefix ${FD_O}, ${OBJS})

SRCS_B_WD	=	$(addprefix ${FD_B}, ${SRCS_B})
OBJS_B_WD	=	$(addprefix ${FD_O_B}, ${OBJS_B})

MLX_INCL	=	./mlx/libmlx.a
MLX_MAKE	=	make -C $(dir $(MLX_INCL))




# $(NAME): $(OBJ)
# 		$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

COMPILER = ${CC} objectfiles -framework OpenGL -framework AppKit -I. $(MLX_INCL)
COMPILERS = ${CC} $(FLAGS) -Imlx

all: lib $(FD_O) $(FD_O_B) $(NAME)

$(MLX_INCL):
				${MLX_MAKE} all

lib: $(MLX_INCL)

$(FD_O):
		mkdir $(FD_O)

$(FD_O_B):
		mkdir $(FD_O_B)

$(NAME): ${FD_O}main.o ${OBJS_WD} ${HEADER}
			$(COMPILER:objectfiles=$(OBJS_WD) ${FD_O}main.o) -o $(NAME)

$(NAME_B):	${FD_O_B}main.o ${OBJS_B_WD} ${HEADER}
			$(COMPILER:objectfiles=$(OBJS_B_WD) ${FD_O_B}main.o) -o $(NAME_B)

clean:
		${MLX_MAKE} clean
		rm -rf ${FD_O}main.o $(FD_O_B)main.o ${OBJS_WD} ${OBJS_B_WD}

fclean:
		${MLX_MAKE} clean
		rm -rf ${FD_O}main.o $(FD_O_B)main.0 ${OBJS_WD} ${OBJS_B_WD} ${NAME} ${NAME_B}


${FD_O}%.o:	${FD_S}%.c ${HEADER}
			$(COMPILERS) -c $< -o $@
${FD_O}%.o: %.c ${HEADER}
			$(COMPILERS) -c $< -o $@




${FD_O_B}%.o:	${FD_B}%.c ${HEADER}
			$(COMPILERS) -c $< -o $@
${FD_O_B}%.o: %.c ${HEADER}
			$(COMPILERS) -c $< -o $@




re:	fclean all

bonus: lib $(FD_O_B) $(NAME_B)

.PHONY: all re clean fclean bonus

# $(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

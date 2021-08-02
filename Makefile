NAME	=	cub3D
MLX		=	./minilibx
LIB		=	./liba
SRC		=	pars_v2.c draw3d.c set_param.c texproc.c set_sprite.c \
			sprite_casting.c gnl/get_next_line.c gnl/get_next_line_utils.c \
			errmng.c screenshot.c texproc1.c moovement.c rotates.c draw_utils.c \
			render3d_utils.c valid_chek.c pars_utils1.c pars_utils2.c int.c pars_utils3.c
OBJ 	=	$(SRC:.c=.o)
CC		=	gcc -g
LIBA	=	liba/libft.a
FLAGS	= 	-Wall -Wextra -Werror

.c.o:
	@$(CC) $(FLAGS) -c $< -o $@


all:	$(NAME)

$(NAME):	$(OBJ)
	@cd liba && make
	@cd minilibx && make
	$(CC) -framework OpenGL -framework AppKit $(OBJ) minilibx/libmlx.a $(LIBA) -o $(NAME)

clean:
	rm -f $(OBJ)
	cd liba && make clean
	cd minilibx && make clean

fclean:
	rm -f $(OBJ) $(NAME)
	cd liba && make fclean
	cd minilibx && make clean

re: clean all

.PHONY: clean fclean all re
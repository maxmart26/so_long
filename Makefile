NAME = so_long
CC = cc
CFLAGS =
SRC = main.c\
	  print_map.c\
	  get_next_line_bonus.c\
	  mouve.c\
	  mouve_2.c\
	  render.c\
	  sprite_init.c\
	  ft_mouve_end.c\
	  ft_mouve_end_2.c\
	  ft_mouve_start.c\
	  mouve_war.c\
	  ft_header.c\
	  ft_print_mouve_u.c\
	  check_maps_main.c\
	  check_maps.c\
	  check_maps2.c\
	  ft_print_error.c\
	  get_next_line_utils_bonus.c
OBJ = ${SRC:.c=.o}
MLX_FLAGS = -L mlx -lmlx -lXext -lX11 -lm -g3
INCLUDES = -I mlx -I include

%.o: %.c
	${CC} -g3 -c -o $@ $< ${INCLUDES}

${NAME}: ${OBJ}
	${CC} -o ${NAME} ${OBJ} ${MLX_FLAGS}

all: ${NAME}

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all

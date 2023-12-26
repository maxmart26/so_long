/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matorgue <warthog2603@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:00:40 by matorgue          #+#    #+#             */
/*   Updated: 2023/12/26 12:01:55 by matorgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 31
# endif

# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 300

# define PIXEL_WIDTH 30
# define PIXEL_HEIGHT 30

# define MLX_ERROR 1
# define RED_PIXEL 0xFF0000
# define GREEN_PIXEL 0xFF00
# define WHITE_PIXEL 0xFFFFFF

# define SHIP_TOP "./assets/ship/ship_top.xpm"
# define SHIP_BOT "./assets/ship/ship_bot.xpm"
# define SHIP_RIGHT "./assets/ship/ship_right.xpm"
# define SHIP_LEFT "./assets/ship/ship_left.xpm"

# define WALL "./assets/wall/wall.xpm"
# define MAPS "./assets/maps/maps.xpm"
# define END "./assets/end/end.xpm"

# define WAR_TOP "./assets/war/war_top.xpm"
# define WAR_RIGHT "./assets/war/war_right.xpm"
# define WAR_LEFT "./assets/war/war_left.xpm"
# define WAR_BOT "./assets/war/war.xpm"

# define HEART_FULL "./assets/heart/heart_full.xpm"
# define HEART_HALF "./assets/heart/heart_half.xpm"
# define HEART_MEPTY "./assets/heart/heart_mepty.xpm"

# define MONEY "./assets/money/money.xpm"
# define MONEY_1 "./assets/money/money.xpm"
# define MONEY_2 "./assets/money/piece2.xpm"
# define MONEY_3 "./assets/money/piece3.xpm"
# define MONEY_4 "./assets/money/piece4.xpm"
# define MONEY_5 "./assets/money/piece5.xpm"

# define NUMBER_U "./assets/number/0.xpm"
# define NUMBER_D "./assets/number/0.xpm"
# define NUMBER_S "./assets/number/0.xpm"
# define NUMBER_M "./assets/number/0.xpm"
# define NUMBER_T "./assets/number/0.xpm"
# define NUMBER_0 "./assets/number/0.xpm"
# define NUMBER_1 "./assets/number/1.xpm"
# define NUMBER_2 "./assets/number/2.xpm"
# define NUMBER_3 "./assets/number/3.xpm"
# define NUMBER_4 "./assets/number/4.xpm"
# define NUMBER_5 "./assets/number/5.xpm"
# define NUMBER_6 "./assets/number/6.xpm"
# define NUMBER_7 "./assets/number/7.xpm"
# define NUMBER_8 "./assets/number/8.xpm"
# define NUMBER_9 "./assets/number/9.xpm"

# define ECHAP 65307
# define TOP 119
# define BOT 115
# define LEFT 97
# define RIGHT 100

typedef struct s_img
{
	void				*xpm_ptr;
	int					x;
	int					y;
}						t_img;

typedef struct s_img_ship
{
	t_img				img_ship_main;
	t_img				img_ship_top;
	t_img				img_ship_bot;
	t_img				img_ship_right;
	t_img				img_ship_left;
}						t_img_ship;

typedef struct s_img_heart
{
	t_img				img_heart_l;
	t_img				img_heart_i;
	t_img				img_heart_f;
	t_img				img_heart_full;
	t_img				img_heart_half;
	t_img				img_heart_mepty;
}						t_img_heart;

typedef struct s_img_war
{
	t_img				img_war_main;
	t_img				img_war_top;
	t_img				img_war_bot;
	t_img				img_war_right;
	t_img				img_war_left;
}						t_img_war;

typedef struct s_img_money
{
	t_img				img_money_main;
	t_img				img_money_1;
	t_img				img_money_2;
	t_img				img_money_3;
	t_img				img_money_4;
	t_img				img_money_5;
}						t_img_money;

typedef struct s_img_number
{
	t_img				img_number_u;
	t_img				img_number_d;
	t_img				img_number_s;
	t_img				img_number_m;
	t_img				img_number_ta;
	t_img				img_number_0;
	t_img				img_number_1;
	t_img				img_number_2;
	t_img				img_number_3;
	t_img				img_number_4;
	t_img				img_number_5;
	t_img				img_number_6;
	t_img				img_number_7;
	t_img				img_number_8;
	t_img				img_number_9;
}						t_img_number;

typedef struct s_data
{
	char				**maps;
	char				*header;
	void				*mlx_ptr;
	void				*win_ptr;
	t_img_ship			img_ship;
	t_img				img_wall;
	t_img				img_maps;
	t_img				img_end;
	t_img_heart			img_heart;
	t_img_money			img_money;
	t_img_war			img_war;
	t_img_number		img_number;
	int					count_line;
	int					count_move;
	int					count_life;
	int					tick;
	int					x_start;
	int					y_start;
	int					index_war;
	int					x_war;
	int					y_war;
	int					x;
	int					y;
	int					x_money;
	int					y_money;
}						t_data;

typedef struct s_coordonees
{
	int					i;
	int					j;
	struct s_coordonees	*next;
}						t_coordonees;

void					ft_print_map(t_data *data);
void					ft_print_line(char *line, t_data *data, int k);
int						ft_count_maps(char *av);

char					*get_next_line(int fd);
char					*ft_new(char *ptr);
char					*ft_static(char *ptr);
char					*ft_strjoin(char *stockage, char *buffer);
char					*ft_strjoin_suite(char *stockage, char *buffer,
							char *str);
char					*ft_cut(char *stockage);

void					ft_mouve_top(t_data *data);
void					ft_mouve_right(t_data *data);
void					ft_mouve_left(t_data *data);
void					ft_mouve_bot(t_data *data);
size_t					ft_strlen(char const *str);

char	*ft_strnchr(char *const str, char const c, size_t const n);
void	*ft_memcpy(void *const dest, void const *const src,size_t size);

int						ft_end(t_data *data);
void					ft_end_number(t_data *data);
void					ft_end_heart(t_data *data);
void					ft_end_war(t_data *data);
void					ft_end_money(t_data *data);
void					ft_end_ship(t_data *data);

int						ft_index_money(t_data *data, char c);
void					ft_index_start(t_data *data);
void					ft_index(t_data *data, char c, int k);

void					ft_mouve_war(t_data *data);
void					ft_respawn(t_data *data);
void					ft_respawn_war(t_data *data);

char					*ft_header(char *av);
void					ft_print_mouve_u(t_data *data, int nb);
void					ft_print_mouve_d(t_data *data, int nb);
void					ft_print_mouve_s(t_data *data, int nb);
void					ft_print_mouve_m(t_data *data, int nb);
void					ft_print_mouve_ta(t_data *data, int nb);

int						check_path(t_data *data);
t_coordonees			*ft_lstnew(int i, int j);
void					ft_get_case_possible(char **map, int i, int j,
							t_coordonees **case_possible);
int						map_valide(t_data *data);
void					ft_putstr_error(char *str);

void					ft_end_number(t_data *data);
void					ft_end_heart(t_data *data);
void					ft_end_war(t_data *data);
void					ft_end_money(t_data *data);

void					ft_init_sprites(t_data *data);
int						render(t_data *data);
int						ft_key_hook(int keycode, t_data *data);
t_img					ft_new_sprite(void *mlx, char *path, t_data *data);
void					ft_init_mlx(t_data *data);

void					ft_index(t_data *data, char c, int k);
void					ft_print_mouve(t_data *data);
void					ft_print_mouve2(t_data *data);
int						ft_check_line(char *stockage);
char					*ft_clean(char *stockage, int i, int j);
int						check_taille(t_data *data);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matorgue <warthog2603@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 16:23:16 by matorgue          #+#    #+#             */
/*   Updated: 2023/12/26 10:48:44 by matorgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_sprites_2(t_data *data)
{
	void	*mlx;

	mlx = data->mlx_ptr;
	data->img_heart.img_heart_full = ft_new_sprite(mlx, HEART_FULL, data);
	data->img_heart.img_heart_l = data->img_heart.img_heart_full;
	data->img_heart.img_heart_i = data->img_heart.img_heart_full;
	data->img_heart.img_heart_f = data->img_heart.img_heart_full;
	data->img_heart.img_heart_half = ft_new_sprite(mlx, HEART_HALF, data);
	data->img_heart.img_heart_mepty = ft_new_sprite(mlx, HEART_MEPTY, data);
	data->img_number.img_number_0 = ft_new_sprite(mlx, NUMBER_0, data);
	data->img_number.img_number_u = data->img_number.img_number_0;
	data->img_number.img_number_d = data->img_number.img_number_0;
	data->img_number.img_number_s = data->img_number.img_number_0;
	data->img_number.img_number_m = data->img_number.img_number_0;
	data->img_number.img_number_ta = data->img_number.img_number_0;
	data->img_number.img_number_1 = ft_new_sprite(mlx, NUMBER_1, data);
	data->img_number.img_number_2 = ft_new_sprite(mlx, NUMBER_2, data);
	data->img_number.img_number_3 = ft_new_sprite(mlx, NUMBER_3, data);
	data->img_number.img_number_4 = ft_new_sprite(mlx, NUMBER_4, data);
	data->img_number.img_number_5 = ft_new_sprite(mlx, NUMBER_5, data);
	data->img_number.img_number_6 = ft_new_sprite(mlx, NUMBER_6, data);
	data->img_number.img_number_7 = ft_new_sprite(mlx, NUMBER_7, data);
	data->img_number.img_number_8 = ft_new_sprite(mlx, NUMBER_8, data);
	data->img_number.img_number_9 = ft_new_sprite(mlx, NUMBER_9, data);
}

void	ft_init_sprites(t_data *data)
{
	void	*mlx;

	mlx = data->mlx_ptr;
	data->img_wall = ft_new_sprite(mlx, WALL, data);
	data->img_maps = ft_new_sprite(mlx, MAPS, data);
	data->img_ship.img_ship_top = ft_new_sprite(mlx, SHIP_TOP, data);
	data->img_ship.img_ship_main = data->img_ship.img_ship_top;
	data->img_ship.img_ship_bot = ft_new_sprite(mlx, SHIP_BOT, data);
	data->img_ship.img_ship_right = ft_new_sprite(mlx, SHIP_RIGHT, data);
	data->img_ship.img_ship_left = ft_new_sprite(mlx, SHIP_LEFT, data);
	data->img_money.img_money_1 = ft_new_sprite(mlx, MONEY, data);
	data->img_money.img_money_main = data->img_money.img_money_1;
	data->img_money.img_money_2 = ft_new_sprite(mlx, MONEY_2, data);
	data->img_money.img_money_3 = ft_new_sprite(mlx, MONEY_3, data);
	data->img_money.img_money_4 = ft_new_sprite(mlx, MONEY_4, data);
	data->img_money.img_money_5 = ft_new_sprite(mlx, MONEY_5, data);
	data->img_war.img_war_top = ft_new_sprite(mlx, WAR_TOP, data);
	data->img_war.img_war_main = data->img_war.img_war_top;
	data->img_war.img_war_bot = ft_new_sprite(mlx, WAR_BOT, data);
	data->img_war.img_war_left = ft_new_sprite(mlx, WAR_LEFT, data);
	data->img_war.img_war_right = ft_new_sprite(mlx, WAR_RIGHT, data);
	data->img_end = ft_new_sprite(mlx, END, data);
	ft_init_sprites_2(data);
}

void	ft_init_mlx(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
	{
		free(data->mlx_ptr);
	}
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1923, 1050, "my game");
	if (data->win_ptr == NULL)
	{
		free(data->mlx_ptr);
	}
}

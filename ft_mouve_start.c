/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouve_start.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matorgue <warthog2603@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 07:54:58 by matorgue          #+#    #+#             */
/*   Updated: 2023/12/24 15:50:33 by matorgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

void	ft_index_start(t_data *data)
{
	data->x_start = 0;
	while (data->maps[data->x_start])
	{
		data->y_start = 0;
		while (data->maps[data->x_start][data->y_start])
		{
			if (data->maps[data->x_start][data->y_start] == 'P')
				return ;
			(data->y_start)++;
		}
		(data->x_start)++;
	}
}

void	ft_respawn(t_data *data)
{
	data->count_life--;
	if (data->count_life == 2)
		data->img_heart.img_heart_f = data->img_heart.img_heart_mepty;
	if (data->count_life == 1)
		data->img_heart.img_heart_i = data->img_heart.img_heart_mepty;
	if (data->count_life == 0)
		ft_end(data);
	data->maps[data->x_start][data->y_start] = 'P';
	data->img_ship.img_ship_main = data->img_ship.img_ship_top;
}

void	ft_respawn_war(t_data *data)
{
	data->count_life--;
	if (data->count_life == 2)
		data->img_heart.img_heart_f = data->img_heart.img_heart_mepty;
	if (data->count_life == 1)
		data->img_heart.img_heart_i = data->img_heart.img_heart_mepty;
	data->maps[data->x_start][data->y_start] = 'P';
	data->img_ship.img_ship_main = data->img_ship.img_ship_top;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matorgue <warthog2603@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:09:58 by matorgue          #+#    #+#             */
/*   Updated: 2023/12/24 16:55:11 by matorgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

void	ft_mouve_top(t_data *data)
{
	ft_index(data, 'P', 0);
	if (data->maps[data->x - 1][data->y] != '1' && data->maps[data->x
		- 1][data->y] != 'E' && data->maps[data->x - 1][data->y] != 'W')
	{
		data->maps[data->x - 1][data->y] = 'P';
		data->maps[data->x][data->y] = '0';
		data->img_ship.img_ship_main = data->img_ship.img_ship_top;
		ft_print_mouve(data);
	}
	if (data->maps[data->x - 1][data->y] == 'E' && ft_index_money(data,
			'C') == 0)
	{
		ft_end(data);
		ft_print_mouve(data);
	}
	if (data->maps[data->x - 1][data->y] == 'W')
	{
		data->maps[data->x][data->y] = '0';
		ft_respawn(data);
		ft_print_mouve(data);
	}
}

void	ft_mouve_right(t_data *data)
{
	ft_index(data, 'P', 0);
	if (data->maps[data->x][data->y + 1] != '1' && data->maps[data->x][data->y
		+ 1] != 'E' && data->maps[data->x][data->y + 1] != 'W')
	{
		data->maps[data->x][data->y + 1] = 'P';
		data->maps[data->x][data->y] = '0';
		data->img_ship.img_ship_main = data->img_ship.img_ship_right;
		ft_print_mouve(data);
	}
	if (data->maps[data->x][data->y + 1] == 'E' && ft_index_money(data,
			'C') == 0)
	{
		ft_end(data);
		ft_print_mouve(data);
	}
	if (data->maps[data->x][data->y + 1] == 'W')
	{
		data->maps[data->x][data->y] = '0';
		ft_respawn(data);
	}
}

void	ft_mouve_left(t_data *data)
{
	ft_index(data, 'P', 0);
	if (data->maps[data->x][data->y - 1] != '1' && data->maps[data->x][data->y
		- 1] != 'E' && data->maps[data->x][data->y - 1] != 'W')
	{
		data->maps[data->x][data->y - 1] = 'P';
		data->maps[data->x][data->y] = '0';
		data->img_ship.img_ship_main = data->img_ship.img_ship_left;
		ft_print_mouve(data);
	}
	if (data->maps[data->x][data->y - 1] == 'E' && ft_index_money(data,
			'C') == 0)
	{
		ft_end(data);
		ft_print_mouve(data);
	}
	if (data->maps[data->x][data->y - 1] == 'W')
	{
		data->maps[data->x][data->y] = '0';
		ft_respawn(data);
		ft_print_mouve(data);
	}
}

void	ft_mouve_bot(t_data *data)
{
	ft_index(data, 'P', 0);
	if (data->maps[data->x + 1][data->y] != '1' && data->maps[data->x
		+ 1][data->y] != 'E' && data->maps[data->x + 1][data->y] != 'W')
	{
		data->maps[data->x + 1][data->y] = 'P';
		data->maps[data->x][data->y] = '0';
		data->img_ship.img_ship_main = data->img_ship.img_ship_bot;
		ft_print_mouve(data);
	}
	if (data->maps[data->x + 1][data->y] == 'E' && ft_index_money(data,
			'C') == 0)
	{
		ft_end(data);
		ft_print_mouve(data);
	}
	if (data->maps[data->x + 1][data->y] == 'W')
	{
		data->maps[data->x][data->y] = '0';
		ft_respawn(data);
		ft_print_mouve(data);
	}
}

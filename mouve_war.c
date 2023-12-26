/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouve_war.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matorgue <warthog2603@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 06:49:47 by matorgue          #+#    #+#             */
/*   Updated: 2023/12/24 16:58:11 by matorgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

void	ft_index_war(t_data *data)
{
	data->x_war = 0;
	while (data->maps[data->x_war])
	{
		data->y_war = 0;
		while (data->maps[data->x_war][data->y_war])
		{
			if (data->maps[data->x_war][data->y_war] == 'W')
			{
				return ;
			}
			(data->y_war)++;
		}
		(data->x_war)++;
	}
}

void	ft_mouve_war_1(t_data *data)
{
	if (data->maps[data->x_war - 1][data->y_war] == 'P')
	{
		data->maps[data->x_war][data->y_war] = '0';
		data->maps[data->x_war - 1][data->y_war] = 'W';
		ft_respawn_war(data);
	}
	else
	{
		data->maps[data->x_war - 1][data->y_war] = 'W';
		data->maps[data->x_war][data->y_war] = '0';
	}
	data->img_war.img_war_main = data->img_war.img_war_top;
	data->index_war--;
}

void	ft_mouve_war_2(t_data *data)
{
	if (data->maps[data->x_war + 1][data->y_war] == 'P')
	{
		data->maps[data->x_war][data->y_war] = '0';
		data->maps[data->x_war + 1][data->y_war] = 'W';
		ft_respawn_war(data);
	}
	else
	{
		data->maps[data->x_war][data->y_war] = '0';
		data->maps[data->x_war + 1][data->y_war] = 'W';
	}
	data->img_war.img_war_main = data->img_war.img_war_bot;
	data->index_war++;
}

void	ft_mouve_war(t_data *data)
{
	ft_index_war(data);
	if (data->maps[data->x_war - 1][data->y_war] != '1' && data->index_war <= 0)
		ft_mouve_war_1(data);
	else if (data->maps[data->x_war + 1][data->y_war] != '1'
		&& data->index_war > 0)
		ft_mouve_war_2(data);
	else if (data->maps[data->x_war - 1][data->y_war] == '1'
		&& data->index_war < 0)
		data->index_war = 10;
	else if (data->maps[data->x_war + 1][data->y_war] == '1'
		&& data->index_war > 0)
		data->index_war = -1;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouve_end.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matorgue <warthog2603@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:44:18 by matorgue          #+#    #+#             */
/*   Updated: 2023/12/26 12:06:14 by matorgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

int	ft_index_money(t_data *data, char c)
{
	data->x_money = 0;
	while (data->x_money != data->count_line)
	{
		data->y_money = 0;
		while (data->maps[data->x_money][data->y_money])
		{
			if (data->maps[data->x_money][data->y_money] == c)
				return (1);
			(data->y_money)++;
		}
		(data->x_money)++;
	}
	return (0);
}

void	free_tab(char **tab, int row)
{
	while (row >= 0)
		free(tab[row--]);
	free(tab);
}

int	ft_end(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img_wall.xpm_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img_maps.xpm_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img_end.xpm_ptr);
	ft_end_ship(data);
	ft_end_heart(data);
	ft_end_number(data);
	ft_end_war(data);
	ft_end_money(data);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free(data->header);
	free_tab(data->maps, data->count_line - 1);
	exit(1);
}

void	ft_end_ship(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img_ship.img_ship_bot.xpm_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img_ship.img_ship_top.xpm_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img_ship.img_ship_right.xpm_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img_ship.img_ship_left.xpm_ptr);
}

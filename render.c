/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matorgue <warthog2603@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 16:20:57 by matorgue          #+#    #+#             */
/*   Updated: 2023/12/26 11:48:51 by matorgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_key_hook(int keycode, t_data *data)
{
	if (keycode == ECHAP)
	{
		ft_end(data);
		return (0);
	}
	else if (keycode == TOP)
		ft_mouve_top(data);
	else if (keycode == BOT)
		ft_mouve_bot(data);
	else if (keycode == LEFT)
		ft_mouve_left(data);
	else if (keycode == RIGHT)
		ft_mouve_right(data);
	return (0);
}

int	on_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}

int	render(t_data *data)
{
	if (data->tick == 0)
	{
		data->img_money.img_money_main = data->img_money.img_money_1;
		ft_mouve_war(data);
	}
	if (data->tick == 100)
		data->img_money.img_money_main = data->img_money.img_money_2;
	if (data->tick == 200)
		data->img_money.img_money_main = data->img_money.img_money_3;
	if (data->tick == 300)
		data->img_money.img_money_main = data->img_money.img_money_4;
	if (data->tick == 400)
		data->img_money.img_money_main = data->img_money.img_money_5;
	if (data->tick == 500)
		data->tick = -1;
	ft_print_line(data->header, data, -1);
	ft_print_map(data);
	data->tick++;
	return (0);
}

int	ft_count_maps(char *av)
{
	int		fd;
	int		count;
	char	*line;

	count = 0;
	fd = open(av, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	return (count);
}

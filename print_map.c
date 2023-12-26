/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matorgue <warthog2603@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 08:07:04 by matorgue          #+#    #+#             */
/*   Updated: 2023/12/26 11:38:22 by matorgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

int	ft_open(char *pathname)
{
	int	fd;

	fd = open(pathname, O_RDONLY);
	if (fd == -1)
		return (-1);
	return (fd);
}

void	ft_print_map(t_data *data)
{
	int	i;
	int	k;

	k = 0;
	while (k != data->count_line)
	{
		ft_print_line(data->maps[k], data, k + 1);
		k++;
	}
}

void	ft_print_line_3(char *line, t_data *data, int k, int i)
{
	if (line[i] == 'S')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img_number.img_number_s.xpm_ptr, i * 64, k * 64);
	else if (line[i] == 'M')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img_number.img_number_m.xpm_ptr, i * 64, k * 64);
	else if (line[i] == 'T')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img_number.img_number_ta.xpm_ptr, i * 64, k * 64);
}

void	ft_print_line_2(char *line, t_data *data, int k, int i)
{
	if (line[i] == 'P')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img_ship.img_ship_main.xpm_ptr, i * 64, k * 64);
	else if (line[i] == 'L')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img_heart.img_heart_l.xpm_ptr, i * 64, k * 64);
	else if (line[i] == 'I')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img_heart.img_heart_i.xpm_ptr, i * 64, k * 64);
	else if (line[i] == 'F')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img_heart.img_heart_f.xpm_ptr, i * 64, k * 64);
	else if (line[i] == 'U')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img_number.img_number_u.xpm_ptr, i * 64, k * 64);
	else if (line[i] == 'D')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img_number.img_number_d.xpm_ptr, i * 64, k * 64);
	else
		ft_print_line_3(line, data, k, i);
}

void	ft_print_line(char *line, t_data *data, int k)
{
	int	i;

	i = 0;
	k++;
	while (line[i])
	{
		if (line[i] == '1')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->img_wall.xpm_ptr, i * 64, k * 64);
		else if (line[i] == '0')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->img_maps.xpm_ptr, i * 64, k * 64);
		else if (line[i] == 'C')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->img_money.img_money_main.xpm_ptr, i * 64, k * 64);
		else if (line[i] == 'E')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->img_end.xpm_ptr, i * 64, k * 64);
		else if (line[i] == 'W')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->img_war.img_war_main.xpm_ptr, i * 64, k * 64);
		else
			ft_print_line_2(line, data, k, i);
		i++;
	}
}

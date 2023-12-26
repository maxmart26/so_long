/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouve_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matorgue <warthog2603@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 16:53:17 by matorgue          #+#    #+#             */
/*   Updated: 2023/12/24 16:53:38 by matorgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

void	ft_print_mouve2(t_data *data)
{
	ft_print_mouve_u(data, data->count_move % 10);
	if (data->count_move > 9)
		ft_print_mouve_d(data, (data->count_move / 10) % 10);
	if (data->count_move > 99)
		ft_print_mouve_s(data, ((data->count_move / 10) / 10) % 10);
	if (data->count_move > 999)
		ft_print_mouve_m(data, (((data->count_move / 10) / 10) / 10) % 10);
	if (data->count_move > 9999)
		ft_print_mouve_ta(data, ((((data->count_move / 10) / 10) / 10) / 10)
			% 10);
}

void	ft_print_mouve(t_data *data)
{
	data->count_move += 1;
	printf("%d\n", data->count_move);
	ft_print_mouve2(data);
}

void	ft_index(t_data *data, char c, int k)
{
	data->x = 0;
	while (data->maps[data->x])
	{
		data->y = 0;
		while (data->maps[data->x][data->y])
		{
			if (data->maps[data->x][data->y] == c)
			{
				if (k != 0)
					k--;
				else
					return ;
			}
			(data->y)++;
		}
		(data->x)++;
	}
}

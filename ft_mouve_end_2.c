/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouve_end_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matorgue <warthog2603@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 15:48:35 by matorgue          #+#    #+#             */
/*   Updated: 2023/12/26 10:49:21 by matorgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_end_money(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img_money.img_money_1.xpm_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img_money.img_money_2.xpm_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img_money.img_money_3.xpm_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img_money.img_money_4.xpm_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img_money.img_money_5.xpm_ptr);
}

void	ft_end_war(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img_war.img_war_bot.xpm_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img_war.img_war_left.xpm_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img_war.img_war_right.xpm_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img_war.img_war_top.xpm_ptr);
}

void	ft_end_heart(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img_heart.img_heart_full.xpm_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img_heart.img_heart_half.xpm_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img_heart.img_heart_mepty.xpm_ptr);
}

void	ft_end_number(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img_number.img_number_0.xpm_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img_number.img_number_1.xpm_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img_number.img_number_2.xpm_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img_number.img_number_3.xpm_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img_number.img_number_4.xpm_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img_number.img_number_5.xpm_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img_number.img_number_6.xpm_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img_number.img_number_7.xpm_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img_number.img_number_8.xpm_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img_number.img_number_9.xpm_ptr);
}

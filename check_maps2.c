/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matorgue <warthog2603@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 16:51:12 by matorgue          #+#    #+#             */
/*   Updated: 2023/12/26 13:09:15 by matorgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_rectangle(t_data *data)
{
	int	i;

	i = 0;
	while (i != data->count_line)
	{
		if (ft_strlen(data->maps[i]) != ft_strlen(data->maps[0]))
			return (0);
		i++;
	}
	return (1);
}

int	check_bordure(t_data *data)
{
	int	i;
	int	j;
	int	bord_right;
	int	bord_bottom;

	i = 0;
	bord_bottom = ft_strlen(data->maps[data->count_line - 1]) - 1;
	bord_right = ft_strlen(data->maps[0]) - 1;
	while (i != data->count_line)
	{
		j = 0;
		while (data->maps[i][j])
		{
			if ((i == 0 || i == bord_bottom || j == 0 || j == bord_right)
				&& data->maps[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_element_inconnu(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i != data->count_line)
	{
		j = 0;
		while (data->maps[i][j])
		{
			if (data->maps[i][j] != '0' && data->maps[i][j] != '1'
				&& data->maps[i][j] != 'C' && data->maps[i][j] != 'P'
				&& data->maps[i][j] != 'E' && data->maps[i][j] != 'W')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_element(t_data *data, int nb_collectible, int nb_player, int nb_exit)
{
	int	i;
	int	j;

	i = 0;
	while (i != data->count_line)
	{
		j = 0;
		while (data->maps[i][j])
		{
			if (data->maps[i][j] == 'C')
				nb_collectible++;
			else if (data->maps[i][j] == 'P')
				nb_player++;
			else if (data->maps[i][j] == 'E')
				nb_exit++;
			j++;
		}
		i++;
	}
	if (nb_collectible < 1 || nb_player != 1 || nb_exit != 1)
		return (0);
	return (1);
}

int	map_valide(t_data *data)
{
	if (check_rectangle(data) == 0)
		return (ft_putstr_error("Error\n la map doit etre un recangle\n"), 0);
	if (check_bordure(data) == 0)
		return (ft_putstr_error("Error\n la map doit etre entouree de mur\n"),
			0);
	if (check_element_inconnu(data) == 0)
		return (ft_putstr_error("Error\n elements inconnus\n"),
			0);
	if (check_element(data, 0, 0, 0) == 0)
		return (ft_putstr_error("Error\n la map doit contenir un joueur"\
		", une sortie et au moins un collectible\n"), 0);
	if (check_path(data) == 0)
		return (ft_putstr_error("Error\n le joueur doit avoir acces"\
		" a tous les collectibles et a la sortie\n"),
			0);
	if (check_taille(data) == 0)
		return (ft_putstr_error("Error\n maps trop grande"), 0);
	return (1);
}

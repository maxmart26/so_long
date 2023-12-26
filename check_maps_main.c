/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matorgue <warthog2603@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:54:33 by matorgue          #+#    #+#             */
/*   Updated: 2023/12/24 14:55:18 by matorgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_find_case(char **map, t_coordonees *case_possible, char c)
{
	int	count;

	count = 0;
	while (case_possible != NULL)
	{
		if (map[case_possible->i][case_possible->j] == c)
			count++;
		case_possible = case_possible->next;
	}
	return (count);
}

int	ft_nb_collectible(t_data *data)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	while (i != data->count_line)
	{
		j = 0;
		while (data->maps[i][j])
		{
			if (data->maps[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	ft_free_list(t_coordonees *case_possible)
{
	t_coordonees	*tmp;

	while (case_possible != NULL)
	{
		tmp = case_possible;
		case_possible = case_possible->next;
		free(tmp);
	}
}

int	ft_find_player(char **map, int *i, int *j, char c)
{
	*i = 0;
	while (map[*i])
	{
		*j = 0;
		while (map[*i][*j])
		{
			if (map[*i][*j] == c)
				return (1);
			(*j)++;
		}
		(*i)++;
	}
	return (0);
}

int	check_path(t_data *data)
{
	t_coordonees	*case_possible;
	int				i;
	int				j;

	ft_find_player(data->maps, &i, &j, 'P');
	case_possible = ft_lstnew(i, j);
	if (case_possible == NULL)
		return (0);
	ft_get_case_possible(data->maps, i, j, &case_possible);
	if (ft_find_case(data->maps, case_possible, 'E') == 0)
		return (ft_free_list(case_possible), 0);
	if (ft_nb_collectible(data) != ft_find_case(data->maps, case_possible, 'C'))
		return (ft_free_list(case_possible), 0);
	return (ft_free_list(case_possible), 1);
}

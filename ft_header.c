/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_header.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matorgue <warthog2603@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:34:34 by matorgue          #+#    #+#             */
/*   Updated: 2023/12/26 12:02:49 by matorgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_header(char *av)
{
	char	*maps;
	int		i;
	int		fd;
	int		b;

	i = 0;
	fd = open(av, O_RDONLY);
	maps = get_next_line(fd);
	while (maps[i] != '\n')
		i++;
	maps[++i] = '\0';
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	return (maps);
}

int	check_taille(t_data *data)
{
	if (ft_strlen(data->maps[0]) > 30)
		return (0);
	if (data->count_line > 15)
		return (0);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matorgue <warthog2603@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:00:03 by matorgue          #+#    #+#             */
/*   Updated: 2023/12/26 12:05:02 by matorgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

t_img	ft_new_sprite(void *mlx, char *path, t_data *data)
{
	t_img	sprite;

	sprite.xpm_ptr = mlx_xpm_file_to_image(mlx, path, &sprite.x, &sprite.y);
	if (sprite.xpm_ptr == NULL)
		printf("error loading %s\n", path);
	return (sprite);
}

char	*ft_new_maps(char *av)
{
	int	fd;

	fd = open(av, O_RDONLY);
	return (get_next_line(fd));
}

char	**ft_maps(char *av)
{
	int		k;
	char	**maps;
	int		i;
	int		fd;
	int		b;

	i = 0;
	k = ft_count_maps(av);
	fd = open(av, O_RDONLY);
	maps = malloc(k * sizeof(char *));
	if (!maps)
		return (NULL);
	while (i < k)
	{
		maps[i] = get_next_line(fd);
		b = 0;
		while (maps[i][b] != '\n')
			b++;
		maps[i][b] = '\0';
		i++;
	}
	return (maps);
}

void	main_init(t_data *data)
{
	data->header = ft_header("maps/header/header.ber");
	data->index_war = 0;
	data->tick = 0;
	data->count_move = 0;
	data->count_life = 3;
}

int	main(int ac, char **av)
{
	t_data	data;
	int		k;
	int		i;

	k = 0;
	ac = 0;
	data.maps = ft_maps(av[1]);
	main_init(&data);
	ft_index_start(&data);
	ft_init_mlx(&data);
	ft_init_sprites(&data);
	if (!data.win_ptr)
		return (free(data.mlx_ptr), 1);
	data.count_line = ft_count_maps(av[1]);
	if (map_valide(&data) == 0)
		ft_end(&data);
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &ft_key_hook, &data);
	mlx_hook(data.win_ptr, 17, 0, &ft_end, &data);
	mlx_loop(data.mlx_ptr);
}

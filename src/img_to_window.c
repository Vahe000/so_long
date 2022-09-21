/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_to_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:48:07 by vasargsy          #+#    #+#             */
/*   Updated: 2022/08/18 18:03:14 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_to_window(t_game *map, void *image, int x, int y)
{
	mlx_put_image_to_window(map->mlx, map->mlx_window,
		image, y * map->img_width, x * map->img_height);
}

void	img_to_xpm(t_game *map)
{
	map->img_height = 70;
	map->img_width = 124;
	map->wall = mlx_xpm_file_to_image(map->mlx, "./img/wall.xpm",
			&map->img_width, &map->img_height);
	map->exit = mlx_xpm_file_to_image(map->mlx, "./img/exit.xpm",
			&map->img_width, &map->img_height);
	map->space = mlx_xpm_file_to_image(map->mlx, "./img/space.xpm",
			&map->img_width, &map->img_height);
	map->items = mlx_xpm_file_to_image(map->mlx, "./img/collectible.xpm",
			&map->img_width, &map->img_height);
	map->player = mlx_xpm_file_to_image(map->mlx, "./img/player.xpm",
			&map->img_width, &map->img_height);
}

void	map_to_window(t_game *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->map_height)
	{
		j = -1;
		while (++j < map->map_width)
		{
			if (map->mapdata[i][j] == '0')
				img_to_window(map, map->space, i, j);
			else if (map->mapdata[i][j] == '1')
				img_to_window(map, map->wall, i, j);
			else if (map->mapdata[i][j] == 'C')
				img_to_window(map, map->items, i, j);
			else if (map->mapdata[i][j] == 'E')
				img_to_window(map, map->exit, i, j);
			else if (map->mapdata[i][j] == 'P')
			{
				map->player_pos_x = j;
				map->player_pos_y = i;
				img_to_window(map, map->player, i, j);
			}
		}
	}
}

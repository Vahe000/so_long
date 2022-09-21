/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 20:57:52 by vasargsy          #+#    #+#             */
/*   Updated: 2022/09/10 17:53:59 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_rect(char **map, int map_height)
{
	int	i;

	i = 0;
	while (++i < map_height)
		if (ft_strlen(map[0]) != ft_strlen(map[i]))
			return (0);
	return (1);
}

static int	check_walls(char **map, int map_height, int map_width)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < map_width)
	{
		if (map[0][i] != '1' || map[map_height - 1][i] != '1' )
			return (0);
		i++;
	}
	while (j < map_height)
	{
		if (map[j][0] != '1' || map[j][map_width - 1] != '1')
			return (0);
		j++;
	}
	return (1);
}

static int	check_param_num(t_game *map)
{
	int	i;
	int	j;

	i = 0;
	map->player_num = 0;
	map->exit_num = 0;
	 
	while (i < map->map_height)
	{
		j = 0;
		while (j < map->map_width)
		{
			if (map->mapdata[i][j] == 'P')
				map->player_num++;
			if (map->mapdata[i][j] == 'E')
				map->exit_num++;
			if (map->mapdata[i][j] == 'C')
				map->item_num++;
			j++;
		}
		i++;
	}
	if (map->player_num != 1 || map->exit_num == 0 || map->item_num == 0)
		return (0);
	return (1);
}

static int	check_epc(char **map, int map_height, int map_width)
{
	int	i;
	int	j;

	j = 1;
	while (j < map_height)
	{
		i = 0;
		while (i < map_width)
		{
			if (map[j][i] != '0' && map[j][i] != '1' && map[j][i] != 'C'
				&& map[j][i] != 'E' && map[j][i] != 'P')
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

void	map_checking(t_game *map)
{
	int	i;

	i = 0;
	map->map_width = ft_strlen(map->mapdata[i]);
	while (map->mapdata[i])
		++i;
	map->map_height = i;
	map->game_is_end = 0;
	if (!check_walls(map->mapdata, map->map_height, map->map_width)
		|| !check_epc(map->mapdata, map->map_height, map->map_width)
		|| !check_rect(map->mapdata, map->map_height)
		|| !check_param_num(map))
	{
		write(2, "error\n", 6);
		exit(1);
	}
}

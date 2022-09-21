/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 13:43:06 by vasargsy          #+#    #+#             */
/*   Updated: 2022/08/24 20:00:52 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

static int	check_path(char *path)
{
	int	i;

	i = ft_strlen(path);
	i -= 4;
	if (ft_strcmp(path + i, ".ber"))
	{
		write(2, "error\n", 6);
		exit(1);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	map;

	if (argc == 2 && check_path(argv[1]))
	{
		read_map(argv[1], &map);
		map.mlx = mlx_init();
		map.mlx_window = mlx_new_window(map.mlx, map.map_width * 124,
				map.map_height * 70, "Scrat");
		img_to_xpm(&map);
		map_to_window(&map);
		player_move(&map);
		mlx_loop(map.mlx);
	}
}

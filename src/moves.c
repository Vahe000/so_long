/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 12:37:52 by vasargsy          #+#    #+#             */
/*   Updated: 2022/07/28 11:57:22 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	img_update(char c, t_game *game)
{
	mlx_destroy_image(game->mlx, game->player);
	if (c == 'd')
		game->player = mlx_xpm_file_to_image(game->mlx,
				"./img/player.xpm", &game->img_width, &game->img_height);
	else if (c == 'a')
		game->player = mlx_xpm_file_to_image(game->mlx,
				"./img/player_2.xpm", &game->img_width, &game->img_height);
}

void	move_w(t_game *game)
{
	if (game->mapdata[game->player_pos_y][game->player_pos_x] == 'E'
			&& game->item_num == 0)
	{
		mlx_clear_window(game->mlx, game->mlx_window);
		game->move_count++;
		exit(0);
	}
	else if (game->mapdata[game->player_pos_y][game->player_pos_x] == 'E'
			|| game->mapdata[game->player_pos_y][game->player_pos_x] == '1')
		game->player_pos_y++;
	else
	{
		if (game->mapdata[game->player_pos_y][game->player_pos_x] == 'C')
			game->item_num--;
		game->mapdata[game->player_pos_y][game->player_pos_x] = 'P';
		game->mapdata[game->player_pos_y + 1][game->player_pos_x] = '0';
		game->move_count++;
		mlx_clear_window(game->mlx, game->mlx_window);
		map_to_window(game);
	}
}

void	move_s(t_game *game)
{
	if (game->mapdata[game->player_pos_y][game->player_pos_x] == 'E'
			&& game->item_num == 0)
	{
		mlx_clear_window(game->mlx, game->mlx_window);
		game->game_is_end = 1;
		game->move_count++;
		exit(0);
	}
	else if (game->mapdata[game->player_pos_y][game->player_pos_x] == 'E'
			|| game->mapdata[game->player_pos_y][game->player_pos_x] == '1')
		game->player_pos_y--;
	else
	{
		if (game->mapdata[game->player_pos_y][game->player_pos_x] == 'C')
			game->item_num--;
		game->mapdata[game->player_pos_y][game->player_pos_x] = 'P';
		game->mapdata[game->player_pos_y - 1][game->player_pos_x] = '0';
		game->move_count++;
		mlx_clear_window(game->mlx, game->mlx_window);
		map_to_window(game);
	}
}

void	move_a(t_game *game)
{
	img_update('a', game);
	if (game->mapdata[game->player_pos_y][game->player_pos_x] == 'E'
			&& game->item_num == 0)
	{
		mlx_clear_window(game->mlx, game->mlx_window);
		game->game_is_end = 1;
		game->move_count++;
		exit(0);
	}
	else if (game->mapdata[game->player_pos_y][game->player_pos_x] == 'E'
			|| game->mapdata[game->player_pos_y][game->player_pos_x] == '1')
		game->player_pos_x++;
	else
	{
		if (game->mapdata[game->player_pos_y][game->player_pos_x] == 'C')
			game->item_num--;
		game->mapdata[game->player_pos_y][game->player_pos_x] = 'P';
		game->mapdata[game->player_pos_y][game->player_pos_x + 1] = '0';
		game->move_count++;
		mlx_clear_window(game->mlx, game->mlx_window);
		map_to_window(game);
	}
}

void	move_d(t_game *game)
{
	img_update('d', game);
	if (game->mapdata[game->player_pos_y][game->player_pos_x] == 'E'
			&& game->item_num == 0)
	{
		mlx_clear_window(game->mlx, game->mlx_window);
		game->game_is_end = 1;
		game->move_count++;
		exit(0);
	}
	else if (game->mapdata[game->player_pos_y][game->player_pos_x] == 'E'
			|| game->mapdata[game->player_pos_y][game->player_pos_x] == '1')
		game->player_pos_x--;
	else
	{
		if (game->mapdata[game->player_pos_y][game->player_pos_x] == 'C')
			game->item_num--;
		game->mapdata[game->player_pos_y][game->player_pos_x] = 'P';
		game->mapdata[game->player_pos_y][game->player_pos_x - 1] = '0';
		game->move_count++;
		mlx_clear_window(game->mlx, game->mlx_window);
		map_to_window(game);
	}
}

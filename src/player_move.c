/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:48:13 by vasargsy          #+#    #+#             */
/*   Updated: 2022/08/24 19:34:57 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->mlx_window);
	exit(0);
	return (0);
}

static void	move_keys(int key_code, t_game *game)
{
	if (key_code == KEY_W || key_code == KEY_UP)
	{
		game->player_pos_y--;
		move_w(game);
	}
	if (key_code == KEY_S || key_code == KEY_DOWN)
	{
		game->player_pos_y++;
		move_s(game);
	}
	if (key_code == KEY_A || key_code == KEY_LEFT)
	{
		game->player_pos_x--;
		move_a(game);
	}
	if (key_code == KEY_D || key_code == KEY_RIGHT)
	{
		game->player_pos_x++;
		move_d(game);
	}
}

static int	key_handle(int key_code, t_game *game)
{
	if (key_code == 53)
		exit_game(game);
	else
	{
		move_keys(key_code, game);
		write (1, "Moves = ", 8);
		ft_putnbr(game->move_count);
		write (1, "\n", 1);
	}
	return (0);
}

void	player_move(t_game *game)
{
	mlx_hook(game->mlx_window, 2, 1L << 0, key_handle, game);
	mlx_hook(game->mlx_window, 17, 1L << 17, exit_game, game);
}

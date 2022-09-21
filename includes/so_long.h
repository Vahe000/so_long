/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:16:36 by vasargsy          #+#    #+#             */
/*   Updated: 2022/08/24 19:58:59 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 80
# endif

# define KEY_ESC 53
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <fcntl.h>

typedef struct s_game
{
	void	*mlx;
	void	*mlx_window;

	char	**mapdata;

	int		map_height;
	int		map_width;

	void	*wall;
	void	*exit;
	void	*items;
	void	*player;
	void	*space;

	void	*img;
	int		img_width;
	int		img_height;

	int		player_pos_x;
	int		player_pos_y;
	int		move_count;
	int		game_is_end;

	int		player_num;
	int		exit_num;
	int		item_num;

	void	*win;

}	t_game;

char		*get_next_line(int fd);
char		*fill_line(char *line, int fd, int len);
int			check_rect(char **map, int map_height);

char		*ft_strdup(char *s1);
size_t		ft_strlen(char *s);
char		*ft_strchr(char *s, int c);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_substr(char	*s, unsigned int start, size_t len);
char		**ft_split(char const *s, char c);
void		ft_putnbr(int nb);
char		*ft_strdup(char *s1);

void		read_map(char *path, t_game *map);
void		map_checking(t_game *map);
int			ft_strcmp(char *s1, char *s2);

void		img_to_window(t_game *map, void *image, int x, int y);
void		img_to_xpm(t_game *map);
void		map_to_window(t_game *map);
int			exit_game(t_game *game);

void		player_move(t_game *game);
void		move_w(t_game *game);
void		move_s(t_game *game);
void		move_a(t_game *game);
void		move_d(t_game *game);

#endif

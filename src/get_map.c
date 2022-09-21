/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 11:33:34 by vasargsy          #+#    #+#             */
/*   Updated: 2022/08/25 12:20:28 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(char *path, t_game *map)
{
	int		map_fd;
	char	*str;
	char	*cur;
	char	*tmp;

	cur = ft_strdup("");
	map_fd = open(path, O_RDONLY);
	str = get_next_line(map_fd);
	while (str)
	{
		tmp = cur;
		cur = ft_strjoin(tmp, str);
		free(str);
		str = get_next_line(map_fd);
	}
	map->mapdata = ft_split(cur, '\n');
	free(str);
	free(cur);
	close(map_fd);
	map_checking(map);
}

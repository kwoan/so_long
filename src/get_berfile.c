/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_berfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwpark <kwpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 19:26:39 by kwpark            #+#    #+#             */
/*   Updated: 2022/11/11 01:19:32 by kwpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_refresh(t_map *map)
{
	char	*tmp;

	tmp = ft_strchr(map->ber_line, 'P');
	*tmp = '0';
	map->ber_line[map->y * (map->width + 1) + map->x] = 'P';
}

int	exit_game(t_solong *so_long)
{
	mlx_destroy_window(so_long->mlx, so_long->win);
	exit(0);
}

static char	*ft_strdup_without_nl(const char *s1)
{
	char	*ptr;
	int		i;

	ptr = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (s1[i] && s1[i] != '\n')
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

static char	*ft_strjoin_without_nl(char const *s1, char const *s2)
{
	char	*res;
	size_t	i;

	if (!s1 || !s2)
		return (0);
	res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (0);
	i = 0;
	while (*s1)
		res[i++] = *s1++;
	while (*s2 && *s2 != '\n')
		res[i++] = *s2++;
	res[i] = '\0';
	return (res);
}

void	get_berfile(char *map_file, t_map *map)
{
	int		fd;
	char	*line;
	char	*tmp;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		error_handler();
	line = get_next_line(fd);
	map->ber_line = ft_strdup_without_nl(line);
	map->height = 0;
	map->width = ft_strlen(line) - 2;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (line)
		{
			map->height++;
			tmp = ft_strjoin_without_nl(map->ber_line, line);
			free(map->ber_line);
			map->ber_line = tmp;
		}
	}
	close(fd);
	map_error_check(map);
}

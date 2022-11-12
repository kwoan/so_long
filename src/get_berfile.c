/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_berfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwpark <kwpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 19:26:39 by kwpark            #+#    #+#             */
/*   Updated: 2022/11/12 14:58:59 by kwpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

static char	*ft_strjoin_without_nl(char *s1, char *s2)
{
	char	*res;
	char	*tmp;
	size_t	i;

	if (!s1 || !s2)
		return (0);
	tmp = s1;
	res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (0);
	i = 0;
	while (*s1)
		res[i++] = *s1++;
	while (*s2 && *s2 != '\n')
		res[i++] = *s2++;
	res[i] = '\0';
	free(tmp);
	return (res);
}

void	get_berfile(char *map_file, t_map *map)
{
	int		fd;
	char	*line;

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
			rectangular_check(map, line);
			map->height++;
			map->ber_line = ft_strjoin_without_nl(map->ber_line, line);
		}
	}
	close(fd);
	map_error_check(map);
}

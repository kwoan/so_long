/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwpark <kwpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 21:36:55 by kwpark            #+#    #+#             */
/*   Updated: 2022/11/17 14:27:45 by kwpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	wall_check(t_map *map)
{
	int	i;

	i = 0;
	while (i <= map->width && map->ber_line[i])
	{
		if (map->ber_line[i] != '1')
			error_handler();
		i++;
	}
	i = (map->width + 1) * map->height;
	while (i <= (map->width + 1) * (map->height + 1) && map->ber_line[i])
	{
		if (map->ber_line[i] != '1')
			error_handler();
		i++;
	}
}

static void	map_elem_check(t_map *map)
{
	int	i;
	int	p_cnt;

	i = 0;
	p_cnt = 0;
	if (!ft_strchr(map->ber_line, 'P') \
		|| !ft_strchr(map->ber_line, 'E') || !ft_strchr(map->ber_line, 'C'))
		error_handler();
	while (i < (map->width + 1) * (map->height + 1))
	{
		if (map->ber_line[i] == 'P')
			p_cnt++;
		if (!ft_strchr("01PEC", map->ber_line[i]))
			error_handler();
		i++;
	}
	if (p_cnt > 1)
		error_handler();
}

void	rectangular_check(t_map *map, char *line)
{
	int	line_len;

	if (ft_strchr(line, '\n'))
		line_len = (int)ft_strlen(line) - 2;
	else
		line_len = (int)ft_strlen(line) - 1;
	if (map->width != line_len)
		error_handler();
}

void	map_error_check(t_map *map)
{
	int	i;

	i = 0;
	while (i <= map->height)
	{
		if (map->ber_line[(map->width + 1) * i] != '1' \
			|| map->ber_line[map->width + (map->width + 1) * i] != '1')
			error_handler();
		i++;
	}
	wall_check(map);
	map_elem_check(map);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwpark <kwpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 05:18:11 by kwpark            #+#    #+#             */
/*   Updated: 2022/11/12 15:16:33 by kwpark           ###   ########.fr       */
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

void	error_handler(void)
{
	printf("Error\n");
	exit(1);
}

static void	flood_fill(t_map *map, int *select, int x, int y)
{
	if (map->ber_line[x + (map->width + 1) * y] == '1' \
		|| select[x + (map->width + 1) * y] == -1)
		return ;
	select[x + (map->width + 1) * y] = -1;
	flood_fill(map, select, x + 1, y);
	flood_fill(map, select, x - 1, y);
	flood_fill(map, select, x, y + 1);
	flood_fill(map, select, x, y - 1);
}

void	path_error_check(t_map *map)
{
	int	i;
	int	*select;

	i = 0;
	select = ft_calloc(1, sizeof(int) * ft_strlen(map->ber_line));
	flood_fill(map, select, map->x, map->y);
	while (i < (int)ft_strlen(map->ber_line))
	{
		if (map->ber_line[i] == 'C' && select[i] != -1)
			error_handler();
		if (map->ber_line[i] == 'E' && select[i] != -1)
			error_handler();
		i++;
	}
	free(select);
}

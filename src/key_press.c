/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwpark <kwpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 19:27:40 by kwpark            #+#    #+#             */
/*   Updated: 2022/11/12 15:29:48 by kwpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_w(t_solong *so_long, int *move_cnt)
{
	char	tmp;
	t_map	*map;

	map = so_long->map;
	tmp = map->ber_line[(map->y - 1) * (map->width + 1) + map->x];
	if (tmp == '1')
		;
	else if (tmp == 'E')
	{
		if (ft_strchr(map->ber_line, 'C') == NULL)
		{
			map->y--;
			printf("%d\n", ++(*move_cnt));
			exit(0);
		}
	}
	else
	{
		map->y--;
		printf("%d\n", ++(*move_cnt));
	}
	map_refresh(map);
	map_draw(map, so_long->img, so_long->mlx, so_long->win);
}

void	move_s(t_solong *so_long, int *move_cnt)
{
	char	tmp;
	t_map	*map;

	map = so_long->map;
	tmp = map->ber_line[(map->y + 1) * (map->width + 1) + map->x];
	if (tmp == '1')
		;
	else if (tmp == 'E')
	{
		if (ft_strchr(map->ber_line, 'C') == NULL)
		{
			map->y++;
			printf("%d\n", ++(*move_cnt));
			exit(0);
		}
	}
	else
	{
		map->y++;
		printf("%d\n", ++(*move_cnt));
	}
	map_refresh(map);
	map_draw(map, so_long->img, so_long->mlx, so_long->win);
}

void	move_a(t_solong *so_long, int *move_cnt)
{
	char	tmp;
	t_map	*map;

	map = so_long->map;
	tmp = map->ber_line[map->y * (map->width + 1) + (map->x - 1)];
	if (tmp == '1')
		;
	else if (tmp == 'E')
	{
		if (ft_strchr(map->ber_line, 'C') == NULL)
		{
			map->x--;
			printf("%d\n", ++(*move_cnt));
			ft_putnbr_fd(++(*move_cnt), 1);
			exit(0);
		}
	}
	else
	{
		map->x--;
		printf("%d\n", ++(*move_cnt));
	}
	map_refresh(map);
	map_draw(map, so_long->img, so_long->mlx, so_long->win);
}

void	move_d(t_solong *so_long, int *move_cnt)
{
	char	tmp;
	t_map	*map;

	map = so_long->map;
	tmp = map->ber_line[map->y * (map->width + 1) + (map->x + 1)];
	if (tmp == '1')
		;
	else if (tmp == 'E')
	{
		if (ft_strchr(map->ber_line, 'C') == NULL)
		{
			map->x++;
			printf("%d\n", ++(*move_cnt));
			exit(0);
		}
	}
	else
	{
		map->x++;
		printf("%d\n", ++(*move_cnt));
	}
	map_refresh(map);
	map_draw(map, so_long->img, so_long->mlx, so_long->win);
}

int	key_press(int keycode, t_solong *so_long)
{
	static int	i;

	if (keycode == KEY_W)
		move_w(so_long, &i);
	else if (keycode == KEY_S)
		move_s(so_long, &i);
	else if (keycode == KEY_A)
		move_a(so_long, &i);
	else if (keycode == KEY_D)
		move_d(so_long, &i);
	else if (keycode == KEY_ESC)
		exit(0);
	return (0);
}

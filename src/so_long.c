/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwpark <kwpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 19:26:56 by kwpark            #+#    #+#             */
/*   Updated: 2022/11/11 01:28:46 by kwpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_struct_alloc(void *mlx, t_img *img)
{
	int		w;
	int		h;

	img->player = mlx_xpm_file_to_image(mlx, "img/player.xpm", &w, &h);
	img->door = mlx_xpm_file_to_image(mlx, "img/door.xpm", &w, &h);
	img->fence = mlx_xpm_file_to_image(mlx, "img/fence.xpm", &w, &h);
	img->chest = mlx_xpm_file_to_image(mlx, "img/chest.xpm", &w, &h);
	img->plain = mlx_xpm_file_to_image(mlx, "img/plain.xpm", &w, &h);
}

void	map_draw(t_map *map, t_img *img, void *mlx, void *win)
{
	int	i;
	int	j;

	i = 0;
	while (i <= map->height)
	{
		j = 0;
		while (j <= map->width)
		{
			mlx_put_image_to_window(mlx, win, img->plain, j * 64, i * 64);
			if (*(map->ber_line + i * (map->width + 1) + j) == '1')
				mlx_put_image_to_window(mlx, win, img->fence, j * 64, i * 64);
			else if (*(map->ber_line + i * (map->width + 1) + j) == 'P')
				mlx_put_image_to_window(mlx, win, img->player, j * 64, i * 64);
			else if (*(map->ber_line + i * (map->width + 1) + j) == 'E')
				mlx_put_image_to_window(mlx, win, img->door, j * 64, i * 64);
			else if (*(map->ber_line + i * (map->width + 1) + j) == 'C')
				mlx_put_image_to_window(mlx, win, img->chest, j * 64, i * 64);
			j++;
		}
		i++;
	}
}

void	player_location_set(t_map *map)
{
	int	i;

	i = 0;
	while (i < (map->width + 1) * (map->height + 1))
	{
		if (map->ber_line[i] == 'P')
			break ;
		i++;
	}
	map->x = i % (map->width + 1);
	map->y = i / (map->width + 1);
}

void	alloc_solong(t_solong *so_long)
{
	so_long->img = ft_calloc(1, sizeof(t_img));
	if (!so_long->img)
		exit(1);
	so_long->map = ft_calloc(1, sizeof(t_map));
	if (!so_long->map)
		exit(1);
}

int	main(int ac, char **av)
{
	t_solong	*so_long;

	(void)av;
	if (ac != 2)
		error_handler();
	so_long = ft_calloc(1, sizeof(t_solong));
	if (!so_long)
		exit(1);
	so_long->mlx = mlx_init();
	alloc_solong(so_long);
	img_struct_alloc(so_long->mlx, so_long->img);
	get_berfile(av[1], so_long->map);
	so_long->win = mlx_new_window(so_long->mlx, 64 * (so_long->map->width + 1), \
		64 * (so_long->map->height + 1), "mlx_project");
	map_draw(so_long->map, so_long->img, so_long->mlx, so_long->win);
	player_location_set(so_long->map);
	mlx_hook(so_long->win, X_EVENT_KEY_RELEASE, 0, &key_press, so_long);
	mlx_hook(so_long->win, X_EVENT_KEY_EXIT, 0, &exit_game, so_long);
	mlx_loop(so_long->mlx);
}

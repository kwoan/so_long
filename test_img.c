/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwpark <kwpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 18:00:30 by kwpark            #+#    #+#             */
/*   Updated: 2022/11/01 17:10:10 by kwpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h"
#include "so_long.h"

int	main(void)
{
	void	*mlx;
	void	*win;
	void	*player;
	void	*door;
	void	*fence;
	void	*chest;
	void	*plain;

	int img_width;
	int img_height;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1000, 500, "mlx 42");
	player = mlx_xpm_file_to_image(mlx, "player.xpm", &img_width, &img_height);
	door = mlx_xpm_file_to_image(mlx, "door.xpm", &img_width, &img_height);
	fence = mlx_xpm_file_to_image(mlx, "fence.xpm", &img_width, &img_height);
	chest = mlx_xpm_file_to_image(mlx, "chest.xpm", &img_width, &img_height);
	plain = mlx_xpm_file_to_image(mlx, "plain.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlx, win, player, 0, 0);
	mlx_put_image_to_window(mlx, win, door, 64, 64);
	mlx_put_image_to_window(mlx, win, fence, 128, 128);
	mlx_put_image_to_window(mlx, win, chest, 192, 192);
	mlx_put_image_to_window(mlx, win, plain, 256, 256);

	mlx_loop(mlx);
}
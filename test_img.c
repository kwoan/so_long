/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwpark <kwpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 18:00:30 by kwpark            #+#    #+#             */
/*   Updated: 2022/11/01 15:11:54 by kwpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h"
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	void	*mlx;
	void	*win;
	void	*img1;

	int img_width;
	int img_height;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1000, 500, "mlx 42");
	img1 = mlx_xpm_file_to_image(mlx, "collectible.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlx, win, img1, 0, 0);

	mlx_loop(mlx);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwpark <kwpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:37:01 by kwpark            #+#    #+#             */
/*   Updated: 2022/11/11 01:23:34 by kwpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "../minilibx/mlx.h"


# define X_EVENT_KEY_PRESS			2
# define X_EVENT_KEY_RELEASE		3
# define X_EVENT_KEY_EXIT			17

# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

typedef struct s_img
{
	void	*plain;
	void	*player;
	void	*fence;
	void	*door;
	void	*chest;
}	t_img;

typedef struct s_map
{
	char	*ber_line;
	int		height;
	int		width;
	int		x;
	int		y;
}	t_map;

typedef struct s_solong
{
	t_img	*img;
	t_map	*map;
	void	*mlx;
	void	*win;
}	t_solong;

void	get_berfile(char *map_file, t_map *map);
int		key_press(int keycode, t_solong *so_long);
void	map_draw(t_map *map, t_img *img, void *mlx, void *win);
void	map_refresh(t_map *map);

void	map_error_check(t_map *map);
void	error_handler(void);

int		exit_game(t_solong *so_long);


#endif
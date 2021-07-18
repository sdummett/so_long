/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 09:44:51 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/18 20:02:36 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	init_img_datas_struct(t_mlx_datas *vars)
{
	vars->free_space.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/ground.xpm", &vars->width, &vars->height);
	vars->free_space.x = 0;
	vars->free_space.y = 0;
	if (error_msg(vars->free_space.img, "Image reading has failed.\n"))
		return (-1);
	vars->wall.img = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/rock.xpm", &vars->width, &vars->height);
	vars->wall.x = 0;
	vars->wall.y = 0;
	if (error_msg(vars->wall.img, "Image reading has failed.\n"))
		return (-1);
	if (init_collectible_img_struct(vars) == -1)
		return (-1);
	if (init_p_down_imgs(vars) == -1)
		return (-1);
	if (init_p_right_imgs(vars) == -1)
		return (-1);
	if (init_p_left_imgs(vars) == -1)
		return(-1);
	if (init_p_win_imgs(vars) == -1)
		return (-1);
	if (init_p_lost_imgs(vars) == -1)
		return (-1);
	if (init_madara_imgs(vars) == -1)
		return (-1);
	if (init_tobi_imgs(vars) == -1)
		return (-1);
	return (0);
}

int	init_mlx_datas_struct(t_mlx_datas *vars)
{
	vars->mlx = mlx_init();
	if (error_msg(vars->mlx, "mlx_init has failed.\n"))
		return (0);
	vars->moves = 0;
	if (init_img_datas_struct(vars) == -1)
		return (-1);
	vars->win_size_x = vars->map_datas.width * vars->width;
	vars->win_size_y = vars->map_datas.height * vars->height;
	vars->win = mlx_new_window(vars->mlx, vars->win_size_x, \
			vars->win_size_y, "so_long");
	if (error_msg(vars->win, "Opening a new window has failed.\n"))
		return (0);
	return (0);
}

void	init_map_datas_struct(t_map_datas *map)
{
	map->width = 0;
	map->height = 0;
	map->collectible = 0;
	map->player = 0;
	map->exit = 0;
}
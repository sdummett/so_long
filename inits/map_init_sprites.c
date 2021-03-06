/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init_sprites.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 02:45:46 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/26 21:03:36 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_put_exit(t_mlx_datas *vars, int x, int y)
{
	put_img(vars, vars->tobi.stand.img, x, y);
}

void	init_put_collectible(t_mlx_datas *vars, int x, int y)
{
	put_img(vars, vars->collect_imgs.kunai_0.img, x, y);
}

void	init_put_free_space(t_mlx_datas *vars, int x, int y)
{
	put_img(vars, vars->free_space.img, x, y);
}

void	init_put_wall(t_mlx_datas *vars, int x, int y)
{
	put_img(vars, vars->wall.img, x, y);
}

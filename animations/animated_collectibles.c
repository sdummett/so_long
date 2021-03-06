/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animated_collectibles.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 13:19:09 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/21 00:13:35 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static	void	animate_collect_2(t_mlx_datas *vars, int img, int x, int y)
{
	int	width;
	int	height;

	width = x * vars->width;
	height = y * vars->height;
	if (img == 5)
		put_img(vars, vars->collect_imgs.kunai_5.img, width, height);
	else if (img == 6)
		put_img(vars, vars->collect_imgs.kunai_6.img, width, height);
	else if (img == 7)
		put_img(vars, vars->collect_imgs.kunai_7.img, width, height);
	else if (img == 8)
		put_img(vars, vars->collect_imgs.kunai_8.img, width, height);
	else if (img == 9)
		put_img(vars, vars->collect_imgs.kunai_9.img, width, height);
	else if (img == 10)
		put_img(vars, vars->collect_imgs.kunai_10.img, width, height);
}

void	animate_collect(t_mlx_datas *vars, int img, int x, int y)
{
	int	width;
	int	height;

	width = x * vars->width;
	height = y * vars->height;
	if (img == 0)
		put_img(vars, vars->collect_imgs.kunai_0.img, width, height);
	else if (img == 1)
		put_img(vars, vars->collect_imgs.kunai_1.img, width, height);
	else if (img == 2)
		put_img(vars, vars->collect_imgs.kunai_2.img, width, height);
	else if (img == 3)
		put_img(vars, vars->collect_imgs.kunai_3.img, width, height);
	else if (img == 4)
		put_img(vars, vars->collect_imgs.kunai_4.img, width, height);
	else
		animate_collect_2(vars, img, x, y);
}

void	put_collectible(t_mlx_datas *vars)
{
	static int	i = 0;
	int			x;
	int			y;

	y = 0;
	while (vars->map[y] != NULL)
	{
		x = 0;
		while (vars->map[y][x] != '\0')
		{
			if (vars->map[y][x] == 'C')
				animate_collect(vars, i, x, y);
			x++;
		}
		y++;
	}
	i++;
	if (i == 11)
		i = 1;
}

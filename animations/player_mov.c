/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mov.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 13:12:38 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/21 00:13:59 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_ath(t_mlx_datas *vars)
{
	int			i;
	char		*str;
	static int	last_move_value = 0;

	i = 1;
	while (i * vars->width < vars->win_size_x)
	{
		if (i == 1)
			put_img(vars, vars->ath.ath_0.img, 0, vars->moves.y);
		else
		{
			put_img(vars, vars->ath.ath_1.img, i * vars->width, vars->moves.y);
			if (i == 2)
			{
				str = ft_itoa(vars->moves.count);
				mlx_string_put(vars->mlx, vars->win, vars->width, \
					vars->moves.y + 37, 0xff8000, str);
				if (last_move_value != vars->moves.count)
				{
					printf("Moves -> %d.\n", vars->moves.count);
					last_move_value = vars->moves.count;
				}
				free(str);
			}
		}
		i++;
	}
	// str = ft_itoa(vars->moves.count);
	// put_img(vars, vars->ath.ath_2.img, vars->width, vars->moves.y);
	// mlx_string_put(vars->mlx, vars->win, vars->width, \
	// 	vars->moves.y + 37, 0xff8000, str);
	
	// free(str);
}

void	put_free_space(t_mlx_datas *vars)
{
	if (vars->play_pos.last_x != vars->play_pos.x || vars->play_pos.last_y != \
	vars->play_pos.y)
	{
		put_img(vars, \
		vars->free_space.img, vars->play_pos.last_x * vars->width, \
		vars->play_pos.last_y * vars->height);
		vars->play_pos.last_x = vars->play_pos.x;
		vars->play_pos.last_y = vars->play_pos.y;
	}
}

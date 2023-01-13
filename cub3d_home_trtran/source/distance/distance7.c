/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance7.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:03:39 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/06/14 11:03:52 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_ray_projection(t_cub *c, double step, int flag)
{
	double	angle;

	angle = ft_correct_radian(c->cntr_rad + c->fov / 2 - step);
	angle = angle - c->cntr_rad;
	if (angle < 0)
		angle = -angle;
	ft_ray_length(c, step, flag);
	// if ((c->w_or_d == 3 || c->w_or_d == 4) && c->pic == 'W')
			// c->ray_projection = c->pl_board_x - c->cross_coor_x;
	// if ((c->w_or_d == 3 || c->w_or_d == 4) && c->pic == 'E')
			// c->ray_projection = c->cross_coor_x - c->pl_board_x;
	// if ((c->w_or_d == 3 || c->w_or_d == 4) && c->pic == 'N')
			// c->ray_projection = c->pl_board_y - c->cross_coor_y;
	// if ((c->w_or_d == 3 || c->w_or_d == 4) && c->pic == 'S')
			// c->ray_projection = c->cross_coor_y - c->pl_board_y;
	if (c->w_or_d != 3 && c->w_or_d != 4)
		c->ray_projection = c->ray_length * cos(angle);
}

double	ft_ray_cast(t_cub *c, double step, int flag)
{
	ft_cntr_rad(c);
	ft_crossing_direction_with_map(c, step);
	ft_side_dist_xy(c, step);
	ft_delta_dist_xy(c, step);
	ft_ray_projection(c, step, flag);
	return (c->ray_length);
}

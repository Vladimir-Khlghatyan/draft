/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:07:37 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/06/18 01:27:01 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_print_arr(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = -1;
	while (arr[++i])
		printf("%s[%s%s%s]%s\n", RED, RESET, arr[i], RED, RESET);
}

int	ft_close(t_cub *c)
{
	mlx_destroy_window(c->mlx, c->win);
	ft_arrfree(c->map);
	exit(1);
}

// int	main(int ac, char **av)
// {
// 	t_cub	*c;

// 	c = (t_cub *)malloc(sizeof(t_cub));
// 	if (!c)
// 		ft_error("can't creat a t_cub struct\n", 1);
// 	if (ac != 2)
// 		ft_error("invalid num of argumnets\n", 1);
// 	ft_initiator(c, av);
// 	/************************************************/	
// 	// c->dir_vec_x = 0.70710678118654757274;
// 	// c->dir_vec_y = -0.70710678118654746172;
// 	// // double	step = 0; // c->fov / 2;
// 	// double	step = (c->fov / (WIDTH_WINDOW - 1) * 750);
// 	// // c->pl_board_x = 2000;
// 	// // c->pl_board_y = 1000;
// 	// ft_ray_cast(c, step);
// 	// printf("-------------------------------------------------\n");
// 	// printf("c->fov=%lf\n", c->fov * 180 / M_PI);
// 	// printf("c->cntr_angle=%.10lf\n", c->cntr_rad);
// 	// printf("c->ray_angle=%.10lf\n", (c->cntr_rad + c->fov / 2 - step));
// 	// printf("c->s_dist_x=%lf\n", c->s_dist_x);
// 	// printf("c->s_dist_y=%lf\n", c->s_dist_y);
// 	// printf("c->d_dist_x=%lf\n", c->d_dist_x);
// 	// printf("c->d_dist_y=%lf\n", c->d_dist_y);
// 	// printf("c->pl_map_x=%d\n", c->pl_map_x);
// 	// printf("c->pl_map_y=%d\n", c->pl_map_y);
// 	// printf("c->pl_board_x=%lf\n", c->pl_board_x);
// 	// printf("c->pl_board_y=%lf\n", c->pl_board_y);
// 	// printf("c->compass_x=%c\n", c->compass_x);
// 	// printf("c->compass_y=%c\n", c->compass_y);
// 	// printf("c->cross_coor_x=%lf\n", c->cross_coor_x);
// 	// printf("c->cross_coor_y=%lf\n", c->cross_coor_y);
// 	// printf("c->ray_length=%.10lf\n", c->ray_length);
// 	// printf("c->pic=%c\n", c->pic);			
// 	/************************************************/
// 	// c->dir_vec_x = 0.70710678118654757274;
// 	// c->dir_vec_y = -0.70710678118654746172;
// 	// // c->pl_board_x = 3500;
// 	// // c->pl_board_y = 3900;
// 	// double	step = c->fov / (WIDTH_WINDOW - 1);
// 	// int	i = -1;
// 	// while (++i < WIDTH_WINDOW)
// 	// {
// 	// 	ft_ray_cast(c, step * i);
// 	// 	printf("i=%d %.10lf\n", i, c->ray_length);
// 	// }
// 	// printf("ok!\n");
// 	// // i = -1;
// 	// // while (++i < WIDTH_WINDOW)
// 	// // {
// 	// // 	ft_ray_cast(c, step * i);
// 	// // 	printf("%.10lf\n", c->d_dist_y);
// 	// // }
// 	/************************************************/
// 	// c->dir_vec_x = -0.6;
// 	// c->dir_vec_y = -0.8;
// 	// c->pl_board_x = 3500;
// 	// c->pl_board_y = 3900;
// 	// mlx_do_key_autorepeaton(c->mlx);
// 	// mlx_hook(c->win, 2, 1L << 0, key_hook, c);
// 	mlx_hook(c->win, RED_CROSS, 0, ft_close, c);
// 	// mlx_loop_hook(c->mlx, ft_draw_wall_pordz, c);
// 	mlx_loop(c->mlx);
// 	return (0);
// }

int	main(int ac, char **av)
{
	t_cub	*c;

	c = (t_cub *)malloc(sizeof(t_cub));
	if (!c)
		ft_error("can't creat a t_cub struct\n", 1);
	if (ac != 2)
		ft_error("invalid num of argumnets\n", 1);
	ft_initiator(c, av);
	mlx_do_key_autorepeaton(c->mlx);
	mlx_hook(c->win, 2, 1L << 0, key_hook, c);
	mlx_hook(c->win, 6, 1L << 6, mouse_hook, c);
	mlx_hook(c->win, RED_CROSS, 0, ft_close, c);
	mlx_loop_hook(c->mlx, ft_cub3d, c);
	mlx_loop(c->mlx);
	return (0);
}


// int	ft_get_xmp_pixel_color1(char *addr, int	linelen, int bpp, int x, int y)
// {
// 	char	*dst;

// 	dst = addr + (y * linelen + x * (bpp / 8));
// 	return (*(unsigned int *)dst);
// }

// int	main(int ac, char **av)
// {
// 	void	*ptr;
// 	int		width;
// 	int		height;
// 	char	*addr;
// 	int		bpp;
// 	int		linelen;
// 	int		endian;
// 	int		color;
// 	t_cub	*c;

// 	c = (t_cub *)malloc(sizeof(t_cub));
// 	if (ac != 3)
// 		return (0);
// 	ft_initiator(c, av);
// 	ptr = mlx_xpm_file_to_image(c->mlx, av[2], &width, &height);
// 	addr = mlx_get_data_addr(ptr, &bpp, &linelen, &endian);
// 	color = ft_get_xmp_pixel_color1(addr, linelen, bpp, 5, 5);
// 	printf("width=%d height=%d linelen=%d bpp=%d color=%d\n", width, height, linelen, bpp, color);
// 	mlx_loop(c->mlx);
// 	return (0);
// }

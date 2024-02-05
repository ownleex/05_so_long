/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:56:56 by ayarmaya          #+#    #+#             */
/*   Updated: 2024/02/05 18:29:18 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../include/so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int	x;
	int	y;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 800, 800, "So_Long");
	img.img = mlx_new_image(mlx, 800, 800);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
		&img.line_length, &img.endian);
/*
	while (y < 490)
	{
		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
		x++;
		y++;
	}
	while (y > 10)
	{
		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
		y--;
	}
	while (x > 10)
	{
		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
		x--;
	}
*/
	x = 30;
	y = 30;
	while (x <= 770)
	{
		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
		my_mlx_pixel_put(&img, x + 1, y + 1, 0x00FFFF00);
		my_mlx_pixel_put(&img, x + 2, y + 2, 0x00FF0000);
		my_mlx_pixel_put(&img, x + 3, y + 3, 0x00FFFF00);
		my_mlx_pixel_put(&img, x + 4, y + 4, 0x00FF0000);
		my_mlx_pixel_put(&img, x, y + 740, 0x00FF0000);
		my_mlx_pixel_put(&img, x + 1, y + 741, 0x00FFFF00);
		my_mlx_pixel_put(&img, x + 2, y + 742, 0x00FF0000);
		my_mlx_pixel_put(&img, x + 3, y + 743, 0x00FFFF00);
		my_mlx_pixel_put(&img, x + 4, y + 744, 0x00FF0000);
		x++;
	}
	x = 30;
	y = 30;
	while (y <= 770)
	{
		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
		my_mlx_pixel_put(&img, x + 1, y + 1, 0x00FFFF00);
		my_mlx_pixel_put(&img, x + 2, y + 2, 0x00FF0000);
		my_mlx_pixel_put(&img, x + 3, y + 3, 0x00FFFF00);
		my_mlx_pixel_put(&img, x + 4, y + 4, 0x00FF0000);
		my_mlx_pixel_put(&img, x + 740, y, 0x00FF0000);
		my_mlx_pixel_put(&img, x + 741, y + 1, 0x00FFFF00);
		my_mlx_pixel_put(&img, x + 742, y + 2, 0x00FF0000);
		my_mlx_pixel_put(&img, x + 743, y + 3, 0x00FFFF00);
		my_mlx_pixel_put(&img, x + 744, y + 4, 0x00FF0000);
		y++;
	}
	

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}

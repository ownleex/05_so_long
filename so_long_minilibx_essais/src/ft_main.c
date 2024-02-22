/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:56:56 by ayarmaya          #+#    #+#             */
/*   Updated: 2024/02/20 22:29:10 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(void)
{
	t_vars	game;
	int		fd;
	char	*line;
//	char	**map;

	ft_printf("\033[34m\nChargement de la carte du niveau\033[0m");
	usleep(1500000);
	ft_printf(".");
	usleep(1500000);
	ft_printf(".");
	usleep(1500000);
	ft_printf(".\n\n");
	usleep(1500000);
	// Ouverture du fichier en lecture seule
	fd = open("maps/big.ber", O_RDONLY);
	if (fd == -1)
	{
		perror("Erreur lors de l'ouverture du fichier");
		return 1;
	}

	// Lecture et affichage de chaque ligne du fichier
	while ((line = get_next_line(fd)) != NULL)
	{
		ft_printf("%s", line);
		free(line);
	}
	usleep(1000000);
	ft_printf("\n\nChargement réussi !!!\n\n");
	// Fermeture du fichier
	close(fd);
	game.mlx_ptr = mlx_init();
	game.win_ptr = mlx_new_window(game.mlx_ptr, 1500, 1000, "---> FireWater <---");
	game.img_green_ptr = mlx_xpm_file_to_image(game.mlx_ptr, "sprites/green.xpm", &game.green_width, &game.green_height);
	game.img_fire_ptr = mlx_xpm_file_to_image(game.mlx_ptr, "sprites/fire.xpm", &game.fire_width, &game.fire_height);
	game.img_water_ptr = mlx_xpm_file_to_image(game.mlx_ptr, "sprites/water.xpm", &game.water_width, &game.water_height);
	game.img_tree_ptr = mlx_xpm_file_to_image(game.mlx_ptr, "sprites/tree.xpm", &game.tree_width, &game.tree_height);
	game.img_exit_ptr = mlx_xpm_file_to_image(game.mlx_ptr, "sprites/exit.xpm", &game.exit_width, &game.exit_height);

	int		green_x = 0;
	int		green_y = 0;
	while (green_y <= 1000)
	{
		while (green_x <= 1500)
		{
			if (game.img_green_ptr != NULL)
			{
				mlx_put_image_to_window(game.mlx_ptr, game.win_ptr, game.img_green_ptr, green_x, green_y);
				green_x += 100;
			}
		}
		green_y += 100;
		green_x = 0;
	}
	int		tree_x = 0;
	int		tree_y = 0;
	while (tree_x <= 1500)
	{
		if (game.img_tree_ptr != NULL)
		{
			mlx_put_image_to_window(game.mlx_ptr, game.win_ptr, game.img_tree_ptr, tree_x, tree_y);
			mlx_put_image_to_window(game.mlx_ptr, game.win_ptr, game.img_tree_ptr, tree_x, tree_y + 900);
			tree_x += 100;
		}
	}
	tree_x = 0;
	tree_y = 100;
	while (tree_y <= 900)
	{
		if (game.img_tree_ptr != NULL)
		{
			mlx_put_image_to_window(game.mlx_ptr, game.win_ptr, game.img_tree_ptr, tree_x, tree_y);
			mlx_put_image_to_window(game.mlx_ptr, game.win_ptr, game.img_tree_ptr, tree_x + 1400, tree_y);
			tree_y += 100;
		}
	}
	if (game.img_fire_ptr != NULL)
	{
		mlx_put_image_to_window(game.mlx_ptr, game.win_ptr, game.img_fire_ptr, 800, 400);
		mlx_put_image_to_window(game.mlx_ptr, game.win_ptr, game.img_fire_ptr, 500, 800);
		mlx_put_image_to_window(game.mlx_ptr, game.win_ptr, game.img_fire_ptr, 200, 200);
	}
	if (game.img_water_ptr != NULL)
	{
		mlx_put_image_to_window(game.mlx_ptr, game.win_ptr, game.img_water_ptr, 1000, 700);
	}
	if (game.img_exit_ptr != NULL)
	{
		mlx_put_image_to_window(game.mlx_ptr, game.win_ptr, game.img_exit_ptr, 300, 300);
	}
	ft_printf("+------------------------------------------------------------------------------------------------+\n");
	ft_printf("|                                                                                                |\n");
	ft_printf("|   Vous êtes une goutte d'eau , vous devez éteindre les feux avant de rejoindre la piscine !    |\n");
	ft_printf("|                                                                                                |\n");
	ft_printf("+------------------------------------------------------------------------------------------------+\n\n");
//	mlx_key_hook(game.win_ptr, handle_input, &game);
	mlx_hook(game.win_ptr, KeyRelease, KeyReleaseMask, handle_input, &game);
	mlx_loop(game.mlx_ptr);
	return (EXIT_SUCCESS);
}

/*
int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		x;
	int		y;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 800, 800, "So Long");
	img.img = mlx_new_image(mlx, 800, 800);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
	&img.line_length, &img.endian);
	x = 0;
	y = 0;
	while (y <= 800)
	{
		while (x <= 800)
		{
			my_mlx_pixel_put(&img, x, y, 0x000000FF);
			x++;
		}
		y++;
		x = 0;
	}
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
*/

/*
#include <mlx.h>
#include <stdlib.h>

int main(void)
{
    void    *mlx_ptr;
    void    *win_ptr;
    void    *img_ptr;
    int     img_width;
    int     img_height;

    // Initialiser la connexion avec le serveur X
    mlx_ptr = mlx_init();
    if (!mlx_ptr)
        return (EXIT_FAILURE);

    // Créer une nouvelle fenêtre
    win_ptr = mlx_new_window(mlx_ptr, 2000, 1500, "So Long");
    if (!win_ptr)
    {
        free(mlx_ptr);
        return (EXIT_FAILURE);
    }

    // Charger une image XPM
    img_ptr = mlx_xpm_file_to_image(mlx_ptr, "sprites/background.xpm", &img_width, &img_height);
    if (!img_ptr)
    {
        mlx_destroy_window(mlx_ptr, win_ptr);
        free(mlx_ptr);
        return (EXIT_FAILURE);
    }

    img_ptr = mlx_xpm_file_to_image(mlx_ptr, "sprites/crystal.xpm", &img_width, &img_height);
    if (!img_ptr)
    {
        mlx_destroy_window(mlx_ptr, win_ptr);
        free(mlx_ptr);
        return (EXIT_FAILURE);
    }

    // Afficher l'image dans la fenêtre
    mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);

    // Entrer dans la boucle d'événements pour garder la fenêtre ouverte
    mlx_loop(mlx_ptr);

    return (EXIT_SUCCESS);
}
*/
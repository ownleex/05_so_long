/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:56:56 by ayarmaya          #+#    #+#             */
/*   Updated: 2024/02/06 17:38:33 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

#include <mlx.h>
#include <stdlib.h>

int main(void)
{
    void    *mlx_ptr;
    void    *win_ptr;
    void    *img_bg_ptr; // Pointeur vers l'image de fond
    void    *img_fg_ptr; // Pointeur vers l'image de premier plan
    void    *img_fg_ptr2;
    int     bg_width, bg_height;
    int     fg_width, fg_height;
    int     fg2_width, fg2_height;

    // Initialisation de MiniLibX
    mlx_ptr = mlx_init();

    // Création de la fenêtre
    win_ptr = mlx_new_window(mlx_ptr, 1500, 1003, "So Long");

    // Chargement de l'image de fond
    img_bg_ptr = mlx_xpm_file_to_image(mlx_ptr, "sprites/background.xpm", &bg_width, &bg_height);
    
    // Chargement de l'image de premier plan
    img_fg_ptr = mlx_xpm_file_to_image(mlx_ptr, "sprites/crystal.xpm", &fg_width, &fg_height);

   // Chargement de l'image 2 de premier plan
    img_fg_ptr2 = mlx_xpm_file_to_image(mlx_ptr, "sprites/tree1.xpm", &fg2_width, &fg2_height);

    // Affichage de l'image de fond
    if (img_bg_ptr != NULL) {
        mlx_put_image_to_window(mlx_ptr, win_ptr, img_bg_ptr, 0, 0);
    }

    // Affichage de l'image de premier plan à une position spécifique
    if (img_fg_ptr != NULL) {
        // Positionnez l'image de premier plan où vous le souhaitez
        int fg_x = 200; // Position X pour l'image de premier plan
        int fg_y = 150; // Position Y pour l'image de premier plan
        mlx_put_image_to_window(mlx_ptr, win_ptr, img_fg_ptr, fg_x, fg_y);
    }

    // Affichage de l'image de premier plan à une position spécifique
    if (img_fg_ptr2 != NULL) {
        // Positionnez l'image de premier plan où vous le souhaitez
        int fg2_x = 600; // Position X pour l'image de premier plan
        int fg2_y = 150; // Position Y pour l'image de premier plan
        mlx_put_image_to_window(mlx_ptr, win_ptr, img_fg_ptr2, fg2_x, fg2_y);
    }

    // Entrer dans la boucle d'événements
    mlx_loop(mlx_ptr);

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
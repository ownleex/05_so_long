/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moove.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:30:48 by ayarmaya          #+#    #+#             */
/*   Updated: 2024/02/22 16:48:32 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_down(t_vars *game)
{
	// Supposition: game->map représente votre carte, et game->player_x et game->player_y représentent
	// les coordonnées X et Y du joueur sur cette carte.
	int x = game->player_x;
	int y = game->player_y;

	// Vérifiez si le déplacement est possible (pas de mur ('1') en dessous du joueur).
	if (game->map[y + 1][x] != '1')
	{
		// Vérifiez si l'espace en dessous est un objet collectable ('C').
		if (game->map[y + 1][x] == 'C')
		{
			game->nbr_fire--; // Réduisez le nombre de collectibles si nécessaire.
			ft_printf("\033[32mObjet collecté! Restants: %d\033[0m\n", game->nbr_fire);
		}
		// Vérifiez si l'espace en dessous est la sortie ('E') et si tous les collectibles ont été ramassés.
		else if (game->map[y + 1][x] == 'E' && game->nbr_fire == 0)
		{
			ft_printf("\033[5m\033[32m\n\n[EXIT] : Vous avez gagné !\n\n\033[0m");
			// Ajoutez ici la logique pour gérer la victoire du joueur.
			// Par exemple, fermez la fenêtre et quittez le programme proprement.
		}
		
		// Mise à jour de la position du joueur si l'espace est vide ou contient un collectible.
		if (game->map[y + 1][x] == '0' || game->map[y + 1][x] == 'C')
		{
			game->map[y][x] = '0'; // Marquez l'ancienne position du joueur comme vide.
			game->player_y += 1; // Mettez à jour la position y du joueur vers le bas.
			game->map[y + 1][x] = 'P'; // Marquez la nouvelle position avec 'P'.
		}
		// Ajoutez toute logique supplémentaire ici, comme redessiner la carte avec le joueur déplacé.
		set_green(game);
		set_fire(game);
		set_water(game);
		set_walls(game);
		set_exit(game);
	}
	else
	{
		ft_printf("\033[31mMouvement impossible: il y a un mur!\033[0m\n");
	}
}

void	move_up(t_vars *game)
{
	// Supposition: game->map représente votre carte, et game->player_x et game->player_y représentent
	// les coordonnées X et Y du joueur sur cette carte.
	int x = game->player_x;
	int y = game->player_y;

	// Vérifiez si le déplacement est possible (pas de mur ('1') au-dessus du joueur).
	if (game->map[y - 1][x] != '1')
	{
		// Vérifiez si l'espace au-dessus est un objet collectable ('C').
		if (game->map[y - 1][x] == 'C')
		{
			game->nbr_fire--; // Réduisez le nombre de collectibles si nécessaire.
			ft_printf("\033[32mObjet collecté! Restants: %d\033[0m\n", game->nbr_fire);
		}
		// Vérifiez si l'espace au-dessus est la sortie ('E') et si tous les collectibles ont été ramassés.
		else if (game->map[y - 1][x] == 'E' && game->nbr_fire == 0)
		{
			ft_printf("\033[5m\033[32m\n\n[EXIT] : Vous avez gagné !\n\n\033[0m");
			// Ajoutez ici la logique pour gérer la victoire du joueur.
			// Par exemple, fermez la fenêtre et quittez le programme proprement.
		}
		
		// Mise à jour de la position du joueur si l'espace est vide ou contient un collectible.
		if (game->map[y - 1][x] == '0' || game->map[y - 1][x] == 'C')
		{
			game->map[y][x] = '0'; // Marquez l'ancienne position du joueur comme vide.
			game->player_y -= 1; // Mettez à jour la position y du joueur vers le haut.
			game->map[y - 1][x] = 'P'; // Marquez la nouvelle position avec 'P'.
		}
		// Ajoutez toute logique supplémentaire ici, comme redessiner la carte avec le joueur déplacé.
		set_green(game);
		set_fire(game);
		set_water(game);
		set_walls(game);
		set_exit(game);
	}
	else
	{
		ft_printf("\033[31mMouvement impossible: il y a un mur!\033[0m\n");
	}
}


void	move_right(t_vars *game)
{
	// Supposition: game->map représente votre carte, et game->player_x et game->player_y représentent
	// les coordonnées X et Y du joueur sur cette carte.
	int x = game->player_x;
	int y = game->player_y;

	// Vérifiez si le déplacement est possible (pas de mur ('1') à droite du joueur).
	if (game->map[y][x + 1] != '1')
	{
		// Vérifiez si l'espace à droite est un objet collectable ('C').
		if (game->map[y][x + 1] == 'C')
		{
			game->nbr_fire--; // Réduisez le nombre de collectibles si nécessaire.
			ft_printf("\033[32mObjet collecté! Restants: %d\033[0m\n", game->nbr_fire);
		}
		// Vérifiez si l'espace à droite est la sortie ('E') et si tous les collectibles ont été ramassés.
		else if (game->map[y][x + 1] == 'E' && game->nbr_fire == 0)
		{
			ft_printf("\033[5m\033[32m\n\n[EXIT] : Vous avez gagné !\n\n\033[0m");
			// Ajoutez ici la logique pour gérer la victoire du joueur.
			// Par exemple, fermez la fenêtre et quittez le programme proprement.
		}
		
		// Mise à jour de la position du joueur si l'espace est vide ou contient un collectible.
		if (game->map[y][x + 1] == '0' || game->map[y][x + 1] == 'C')
		{
			game->map[y][x] = '0'; // Marquez l'ancienne position du joueur comme vide.
			game->player_x += 1; // Mettez à jour la position x du joueur vers la droite.
			game->map[y][x + 1] = 'P'; // Marquez la nouvelle position avec 'P'.
		}
		// Ajoutez toute logique supplémentaire ici, comme redessiner la carte avec le joueur déplacé.
		set_green(game);
		set_fire(game);
		set_water(game);
		set_walls(game);
		set_exit(game);
	}
	else
	{
		ft_printf("\033[31mMouvement impossible: il y a un mur!\033[0m\n");
	}
}


void	move_left(t_vars *game)
{
	// Supposition: game->map représente votre carte, et game->player_x et game->player_y représentent
	// les coordonnées X et Y du joueur sur cette carte.
	int x = game->player_x;
	int y = game->player_y;

	// Vérifiez si le déplacement est possible (pas de mur ('1') à gauche du joueur).
	if (game->map[y][x - 1] != '1')
	{
		// Vérifiez si l'espace à gauche est un objet collectable ('C').
		if (game->map[y][x - 1] == 'C')
		{
			game->nbr_fire--; // Réduisez le nombre de collectibles si nécessaire.
			ft_printf("\033[32mObjet collecté! Restants: %d\033[0m\n", game->nbr_fire);
		}
		// Vérifiez si l'espace à gauche est la sortie ('E') et si tous les collectibles ont été ramassés.
		else if (game->map[y][x - 1] == 'E' && game->nbr_fire == 0)
		{
			ft_printf("\033[5m\033[32m\n\n[EXIT] : Vous avez gagné !\n\n\033[0m");
			// Ajoutez ici la logique pour gérer la victoire du joueur.
			// Par exemple, fermez la fenêtre et quittez le programme proprement.
		}
		
		// Mise à jour de la position du joueur si l'espace est vide ou contient un collectible.
		if (game->map[y][x - 1] == '0' || game->map[y][x - 1] == 'C')
		{
			game->map[y][x] = '0'; // Marquez l'ancienne position du joueur comme vide.
			game->player_x -= 1; // Mettez à jour la position x du joueur.
			game->map[y][x - 1] = 'P'; // Marquez la nouvelle position avec 'P'.
		}
		// Ajoutez toute logique supplémentaire ici, comme redessiner la carte avec le joueur déplacé.
		set_green(game);
		set_fire(game);
		set_water(game);
		set_walls(game);
		set_exit(game);
	}
	else
	{
		ft_printf("\033[31mMouvement impossible: il y a un mur!\033[0m\n");
	}
}

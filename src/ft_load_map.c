/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:36:17 by ayarmaya          #+#    #+#             */
/*   Updated: 2024/02/22 07:13:02 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_temp_map(t_list *temp_map)
{
	t_list	*current;

	while (temp_map != NULL)
	{
		current = temp_map;
		temp_map = temp_map->next;
		free(current->content);
		free(current);
	}
}

void	remove_back_n(char *line)
{
	char	*newline;

	newline = strchr(line, '\n');
	if (newline != NULL)
		*newline = '\0';
}

void	load_map_struct(t_list *temp_map, int line_count, t_vars *game)
{
	int		i;

	i = 0;
	game->map = (char **)malloc(sizeof(char *) * (line_count + 1));
	if (!game->map)
		exit_with_message("\nError\nProblème mémoire : chargement map\n\n");
	while (temp_map)
	{
		game->map[i] = ft_strdup((char *)temp_map->content);
		if (!game->map[i])
			exit_with_message("\nError\nProblème de duplication de la ligne\n\n");
		temp_map = temp_map->next;
		i++;
	}
	game->map[i] = NULL;
}

void	load_map(char *map_file, t_vars *game)
{
	int		fd;
	char	*line;
	t_list	*temp_map;
	int		line_count;

	line_count = 0;
	temp_map = NULL;
	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		exit_with_perror("\nError\nErreur lors du chargement de la carte\n\n");
	line = get_next_line(fd);
	while (line != NULL)
	{
		ft_printf("\033[32m%s\033[0m", line);
		remove_back_n(line);
		ft_lstadd_back(&temp_map, ft_lstnew(ft_strdup(line)));
		free(line);
		line_count++;
		line = get_next_line(fd);
	}
	close(fd);
	load_map_struct(temp_map, line_count, game);
	free_temp_map(temp_map);
	ft_printf("\n\n");
}

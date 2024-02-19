/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:36:17 by ayarmaya          #+#    #+#             */
/*   Updated: 2024/02/19 14:38:53 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../libft/include/libft.h"

void	load_map_struct(t_list *temp_map, int line_count)
{
	char	**map;
	int		i = 0;
	t_list	*current;

	map = malloc(sizeof(char *) * (line_count + 1));
	if (!map)
	{
		ft_printf("Error\nProblème mémoire au chargement de la carte")
		return (NULL);
	}
	current = temp_map;
	while (current)
	{
		map[i] = ft_strdup((char *)current->content);
		current = current->next;
		i++;
	}
	map[i] = NULL; 
	check_rectangular(map);
}

void	load_map(char *map)
{
	int		fd;
	char	*line;
	t_list	*temp_map;
	int		line_count = 0;

	temp_map = NULL;
	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		perror("Error\nErreur lors du chargement de la carte");
		return;
	}
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		ft_printf("%s", line);
		ft_lstadd_back(&temp_map, ft_lstnew(ft_strdup(line)));
		line_count++;
		free(line);
	}
	close(fd);
	load_map_struct(temp_map, line_count);
}

int	check_ber(char *map)
{
	int	i;

	i = ft_strlen(map);
	if (map[i - 4] != '.' || map[i - 3] != 'b'
		|| map[i - 2] != 'e' || map[i - 1] != 'r')
		return (0);
	return (1);
}
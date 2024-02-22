/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:06:49 by ayarmaya          #+#    #+#             */
/*   Updated: 2024/02/22 04:37:02 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	exit_with_message(char *message)
{
	ft_printf("%s", message);
	exit(EXIT_FAILURE);
}

void	exit_with_perror(char *message)
{
	perror(message);
	exit(EXIT_FAILURE);
}

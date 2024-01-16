/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 01:53:07 by ayarmaya          #+#    #+#             */
/*   Updated: 2024/01/12 17:15:08 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(unsigned char *)(s + i) = 0;
		i++;
	}
}

/*
int	main(void)
{
	char	str[] = "bla bla blaaaaaaaa";
	printf("Avant ft_bzero : %s\n", str);
	ft_bzero(str + 2, 1);
	printf("Apres ft_bzero : %s\n", str);
	return (0);
}
*/

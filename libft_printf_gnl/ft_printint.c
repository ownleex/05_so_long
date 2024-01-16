/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:15:52 by ayarmaya          #+#    #+#             */
/*   Updated: 2023/12/11 15:31:04 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printint(int nbr)
{
	int		ret;
	char	*str;

	str = ft_itoa(nbr);
	ret = ft_printstr(str);
	free(str);
	return (ret);
}

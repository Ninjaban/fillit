/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 08:54:57 by jcarra            #+#    #+#             */
/*   Updated: 2016/11/09 13:36:54 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int		main(int ac, char **av)
{
	if (ac != 2)
	{
		ft_putstr("Usage: ./fillit [file]\n");
		return (1);
	}
	if (ft_fillit(av[1]) == -1)
	{
		ft_putstr("error\n");
		return (1);
	}
	return (0);
}

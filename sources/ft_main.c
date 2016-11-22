/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 08:54:57 by jcarra            #+#    #+#             */
/*   Updated: 2016/11/22 09:03:26 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int		main(int ac, char **av)
{
	if (ac != 2)
	{
		ft_putendl_fd("Usage: ./fillit [file]", 2);
		return (1);
	}
	if (ft_fillit(av[1]) == -1)
	{
		ft_putendl_fd("error", 2);
		return (1);
	}
	return (0);
}

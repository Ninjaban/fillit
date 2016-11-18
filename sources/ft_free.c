/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 16:16:01 by mrajaona          #+#    #+#             */
/*   Updated: 2016/11/18 16:23:45 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	*ft_freemap(t_map *map)
{
	if (map)
	{
		if (map->map)
			free(map->map);
		free(map);
	}
	map = NULL;
	return (NULL);
}

void	ft_freeargs(t_args *args)
{
	if (args)
	{
		if (args->ttab)
			free(args->ttab);
		if (args->ptab)
			free(args->ptab);
		if (args->map)
			ft_freemap(args->map);
		free(args);
	}
}

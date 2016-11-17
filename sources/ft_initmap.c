/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 09:10:59 by mrajaona          #+#    #+#             */
/*   Updated: 2016/11/17 14:10:39 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** square root rounded up
*/

static unsigned char	ft_sqrt(int nb)
{
	unsigned char	i;

	i = 0;
	while (i * i < nb && i < 21)
		i++;
	return (i);
}

static void				ft_freemap(t_map *map)
{
	if (map)
	{
		if (map->map)
			free(map->map);
		free(map);
	}
	map = NULL;
}

static t_map			*ft_initmap(const unsigned char size)
{
	t_map			*map;
	unsigned int	i;

	if ((map = (t_map *)malloc(sizeof(t_map))) == NULL)
		return (NULL);
	map->size = size;
	if ((map->map = (t_mapl *)malloc(sizeof(t_map) * size)) == NULL)
	{
		free(map);
		return (NULL);
	}
	i = 0;
	while (i < size)
		map->map[i++].line = 0;
	map->size = size;
	return (map);
}

t_map					*ft_makemap(t_map *map, const unsigned char size)
{
	if (map)
		ft_freemap(map);
	if ((map = ft_initmap(size)) == NULL)
		return (NULL);
	return (map);
}

void					ft_map(const int nb, short *tab)
{
	unsigned char	size;
	t_map			*map;
	t_tetri			*tetri;

	size = ft_sqrt(nb * 4);
	map = NULL;
	if ((tetri = ft_tabtetri(nb, tab)) == NULL)
		return ;
	if ((map = ft_fillmap(size, tetri, nb)) == NULL)
		return ;
	/*****************************/
	//ft_printmap(map, tetri, nb);
	if (tetri)
		free(tetri);
	ft_freemap(map);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 09:10:59 by mrajaona          #+#    #+#             */
/*   Updated: 2016/11/18 16:21:08 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static unsigned char	ft_sqrt(int nb)
{
	unsigned char	i;

	i = 0;
	while (i * i < nb && i < 24)
		i++;
	return (i);
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

t_map					*ft_makemap(t_map *map, const unsigned char size,
									t_args *args)
{
	if (map)
		ft_freemap(map);
	if ((map = ft_initmap(size)) == NULL)
	{
		ft_freeargs(args);
		return (NULL);
	}
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
	if ((map = ft_solve(size, tetri, nb)) == NULL)
		return ;
	ft_printmap(map, tetri, nb);
	if (tetri)
		free(tetri);
	ft_freemap(map);
}

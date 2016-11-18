/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 14:40:28 by mrajaona          #+#    #+#             */
/*   Updated: 2016/11/18 15:25:33 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_map		*ft_cleanmap(t_map *map, t_tetri *ttab,
							char *ptab, int p)
{
	int	t;

	while (ptab[p])
	{
		t = 0;
		while (ttab[t].letter != ptab[p])
			t++;
		ft_tetridel(map, &(ttab[t]));
		ptab[p] = '\0';
		p++;
	}
	return (map);
}

t_map				*ft_solve(unsigned char size, t_tetri *ttab, const int nb)
{
	t_map	*map;
	char	*ptab;

	map = NULL;
	ptab = NULL;
	if ((ptab = (char *)malloc(sizeof(char) * (nb + 1))) == NULL)
		return (NULL);
	if ((map = ft_makemap(map, size)) == NULL)
		return (NULL);
	while (ft_fillmap(ptab, map, ttab, nb) != nb && size < 24)
	{
		size++;
		ft_cleanmap(map, ttab, ptab, 0);
		if ((map = ft_makemap(map, size)) == NULL)
			return (NULL);
	}
	if (size > 24)
	{
		ft_freemap(map);
		return (NULL);
	}
	return (map);
}

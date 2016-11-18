/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 14:40:28 by mrajaona          #+#    #+#             */
/*   Updated: 2016/11/18 16:39:44 by mrajaona         ###   ########.fr       */
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
	t_args	*args;

	map = NULL;
	ptab = NULL;
	args = NULL;
	if ((args = (t_args *)malloc(sizeof(t_args))) == NULL)
		return (NULL);
	if ((ptab = (char *)malloc(sizeof(char) * (nb + 1))) == NULL)
		return (NULL);
	args->ttab = ttab;
	args->ptab = ptab;
	if ((map = ft_makemap(map, size, args)) == NULL)
		return (NULL);
	args->map = map;
	while (ft_fillmap(args, nb) != nb && size++ < 24)
	{
		ft_cleanmap(map, ttab, ptab, 0);
		if ((map = ft_makemap(map, size, args)) == NULL)
			return (NULL);
	}
	if (size > 24)
		return (ft_freemap(map));
	return (map);
}

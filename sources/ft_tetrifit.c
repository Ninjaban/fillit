/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetrifit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 10:27:43 by mrajaona          #+#    #+#             */
/*   Updated: 2016/11/20 10:28:00 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_doesitfit(t_tetri *src, unsigned int dest,
									int pa, int pb)
{
	unsigned short	i;
	int				j;

	i = 0;
	j = 0;
	while (i < src->size.w)
	{
		if (B_TEST1(src->piece, pa + i) != 0 && B_TEST1(dest, pb + i) != 0)
			j++;
		i++;
	}
	return (j);
}

int			ft_itfits(t_map *map, t_tetri *tetri, t_pos *pos)
{
	char			pa;
	char			l;
	unsigned int	res;

	l = 0;
	res = 0;
	if ((tetri->size.h + pos->y) > map->size
		|| (tetri->size.w + pos->x) > map->size)
		return (0);
	while (l < tetri->size.h && (pos->y + l) < map->size)
	{
		pa = 4 * (l);
		res += ft_doesitfit(tetri, map->map[pos->y + l].line, pa, pos->x);
		l++;
	}
	if (res != 0)
		return (0);
	return (1);
}

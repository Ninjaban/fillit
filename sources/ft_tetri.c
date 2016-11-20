/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetri.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 09:16:41 by mrajaona          #+#    #+#             */
/*   Updated: 2016/11/20 12:06:34 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static unsigned int	ft_del(unsigned short src, unsigned int dest,
							int pa, int pb)
{
	unsigned int	mask;

	mask = (0xF << (pa - 4));
	dest = dest ^ (((src) & mask) >> (pa - 4) << pb);
	return (dest);
}

void				ft_tetridel(t_map *map, t_tetri *tetri)
{
	char	pa;
	char	l;

	l = 0;
	while (l < 4 && (tetri->pos.y + l) < map->size)
	{
		pa = 4 * (l + 1);
		map->map[tetri->pos.y + l].line = ft_del(tetri->piece,
												map->map[tetri->pos.y + l].line,
												pa, tetri->pos.x);
		l++;
	}
	tetri->pos.x = -1;
	tetri->pos.y = -1;
	tetri->used = 0;
}

static unsigned int	ft_cpy(unsigned short src, unsigned int dest,
							int pa, int pb)
{
	unsigned int	mask;

	mask = (0xF << (pa - 4));
	dest = (dest) | (((~(src) & mask) >> (pa - 4) << pb)
					^ (dest | (mask >> (pa - 4) << pb)));
	return (dest);
}

void				ft_tetricpy(t_map *map, t_tetri *tetri, t_pos *pos)
{
	char	pa;
	char	l;
	int		n;

	l = 0;
	while (l < 4 && (pos->y + l) < map->size)
	{
		n = pos->y + l;
		pa = 4 * (l + 1);
		map->map[n].line = ft_cpy(tetri->piece, map->map[n].line, pa, pos->x);
		l++;
	}
	tetri->pos.x = pos->x;
	tetri->pos.y = pos->y;
	tetri->used = 1;
}

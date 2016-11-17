/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 10:37:12 by mrajaona          #+#    #+#             */
/*   Updated: 2016/11/17 15:40:01 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h" //DEBUG

static t_map		*ft_cleanmap(t_map *map, t_tetri *ttab,
							char *ptab, int p)
{
	int	t;

	while (ptab[p])
	{
		t = 0;
		if (ttab[t].letter != ptab[p])
			t++;
		ft_tetridel(map, &(ttab[t]));
		ptab[p] = '\0';
		p++;
	}
	return (map);
}

#include <stdio.h> //DEBUG
void				ft_print_all(t_map *map)
{
	int i;
	int n;

	n = 0;
	while (n < map->size)
	{
		i = 0;
		while (i < map->size)
		{
			ft_putstr(((map->map[n].line & (1 << i)) == 0) ? "." : "#");
			i++;
		}
		n++;
		ft_putstr("\n");
	}
}

static int			ft_isok(unsigned short src, int pa)
{
	unsigned int	mask;

	mask = 0xF << (pa - 4);
	if ((mask & src) != 0)
		return (1);
	return (0);
}

static int			ft_doesitfit(unsigned short src, unsigned int dest,
									int pa, int pb)
{
	unsigned short	mask;

	mask = 0xF << (pa - 4);
	dest = dest & ((src & mask) >> (pa - 4) << pb);
	return (dest);
}

static int			ft_itfits(t_map *map, t_tetri *tetri, t_pos *pos)
{
	char			pa;
	char			l;
	unsigned int	res;

	l = 0;
	res = 0;
	ft_putstr("Does it fit ? ");
	while (l < 4)
	{
		pa = 4 * (l + 1);
		if ((pos->y + l) < map->size)
			res += ft_doesitfit(tetri->piece, map->map[pos->y + l].line,
								pa, pos->x);
		else
			res += ft_isok(tetri->piece, pa);
		l++;
	}
	printf("%d\n", res);
	if (res != 0)
		return (0);
	return (1);
}

/* CA MARCHE PAS ET CA TUE LA NORME */

t_map				*ft_fillmap(unsigned char size, t_tetri *ttab, const int nb)
{
	t_pos	pos;
	t_map	*map;
	int		t; // incrementation ttab
	int		p; // nb pieces placees
	char	ptab[nb + 1];

	p = 0;
	map = NULL;
	pos.x = 0;
	pos.y = 0;
	t = 0;
	while (p < nb)
	{
		if (map == NULL || (pos.y == size && t == nb))
		{
			ft_putstr("\nNULL\n");
			p = 0;
			if (map)
			{
				ft_cleanmap(map, ttab, ptab, 0);
				ft_putstr("Clean\n\n");
				size++;
			}
			if ((map = ft_makemap(map, size)) == NULL)
				return (NULL);
			while (p <= nb)
				ptab[p++] = '\0';
			p = 0;
			pos.x = 0;
			pos.y = 0;
		}
		t = 0;
		while (t < nb)
		{
			if (ttab[t].used == 0)
			{
				printf("Loop : x:%d y:%d, t:%d, s:%d\n", pos.x, pos.y, t, size);
				if (ft_itfits(map, &(ttab[t]), &pos) == 1)
				{
					ft_tetricpy(map, &(ttab[t]), &pos);
					ptab[p] = ttab[t].letter;
					pos.x++;
					p++;
					t = -1;
				}
			}
			if (pos.x == size)
			{
				pos.y++;
				pos.x = 0;
			}
			t++;
		}
		pos.x++;
		if (pos.x == size)
		{
			pos.y++;
			pos.x = 0;
		}
	}
	ft_putstr(ptab);
	ft_putstr("\n\n");
	return (map);
}

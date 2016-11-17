/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 10:37:12 by mrajaona          #+#    #+#             */
/*   Updated: 2016/11/17 12:07:53 by mrajaona         ###   ########.fr       */
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

/* CA MARCHE PAS */

static int			ft_doesitfit(unsigned short src, unsigned int dest,
									int pa, int pb)
{
	unsigned int	mask;

	mask = ((1 << (4)) - 1) << (pa - 4);
	printf("A: %0X\n", dest);
	dest = (dest & (((~(src) & mask) << (pa - pb))
								^ (dest | (mask << (pa - pb)))));
	printf("B: %0X\n\n", dest);
	return (dest);
}

static int			ft_itfits(t_map *map, t_tetri *tetri, t_pos *pos)
{
	char			pa;
	char			l;
	unsigned int	res;

	l = 0;
	res = 0;
	ft_putstr("hey\n");
	while (l < 4 && (pos->y + l) < map->size)
	{
		pa = 4 * ((4 - l) % 4);
		res += ft_doesitfit(tetri->piece, map->map[pos->y + l].line,
							pa, pos->x);
		printf("res it_fits : %d\n", res);
		l++;
	}
	if (res == 0)
		return (1);
	return (0);
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
	while (p <= nb)
		ptab[p++] = '\0';
	p = 0;
	t = 0;
	while (p < nb && t < nb)
	{
		t = 0;
		ft_putstr("loop\n");
		if (map == NULL || (pos.y == size && p < nb))
		{
			if (map == NULL || t == nb)
			{
				if ((map = ft_makemap(map, size)) == NULL)
					return (NULL);
				p = 0;
			}
			else
			{
				p--;
				ft_cleanmap(map, ttab, ptab, p);
			}
		}
		while (t < nb)
		{
			if (ttab[t].used == 0)
			{
				if (ft_itfits(map, &(ttab[t]), &pos) == 1)
				{
					ft_tetricpy(map, &(ttab[t]), &pos);
					ptab[p] = ttab[t].letter;
					p++;
					t = 0;
				}
			}
			t++;
		}
	}
	ft_putstr(ptab);
	ft_putstr("\n\n");
	return (map);
}

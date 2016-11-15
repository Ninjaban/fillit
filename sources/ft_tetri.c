/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetri.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 09:16:41 by mrajaona          #+#    #+#             */
/*   Updated: 2016/11/15 13:03:43 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static unsigned int	ft_del(unsigned short src, unsigned int dest,
							int pa, int pb)
{
	unsigned int	mask;

	mask = ((1 << (4)) - 1) << (pa - 4);
	dest = (dest) ^ (((~(src) & mask) >> (pa - pb))
					^ (dest | (mask >> (pa - pb))));
	return (dest);
}

void				ft_tetridel(t_map *map, t_tetri *tetri)
{
	char	pa;
	char	l;

	l = 0;
	while (l < 4 && (tetri->pos.y + l) < map->size)
	{
		pa = 4 * ((4 - l) % 4);
		map->map[tetri->pos.y + l].line = ft_del(tetri->piece,
												map->map[tetri->pos.y + l].line,
												pa, tetri->pos.x);
		l++;
	}
	tetri->pos.x = -1;
	tetri->pos.y = -1;
	tetri->used = 0;
}
#include "libft.h"
#include <stdio.h>//DEBUG
static unsigned int	ft_cpy(unsigned short src, unsigned int dest,
							int pa, int pb)
{
	unsigned int	mask;

	mask = ((1 << (4)) - 1) << (pa - 4);
	printf("src : %04X\n", src);
	printf("dest: %06X\n", dest);
	dest = (dest) | (((~(src) & mask) >> (pa - pb))
					^ (dest | (mask >> (pa - pb))));
	printf("cpy : %06X\n", dest);
	return (dest);
}

void				ft_tetricpy(t_map *map, t_tetri *tetri, t_pos *pos)
{
	char	pa;
	char	l;
	int		n;

	l = 0;
	ft_putstr("cpy\n");
	while (l < 4 && (pos->y + l) < map->size)
	{
		n = pos->y + l;
		pa = 4 * ((4 - l) % 4);
		map->map[n].line = ft_cpy(tetri->piece, map->map[n].line, pa, pos->x);
		l++;
	}
	/****************/
	ft_print_all(map);
	/****************/
	tetri->pos.x = pos->x;
	tetri->pos.y = pos->y;
	tetri->used = 1;
}

t_tetri				*ft_tabtetri(int nb, const short *tab)
{
	t_tetri	*tabtetri;
	int		i;

	if ((tabtetri = (t_tetri *)malloc(sizeof(t_tetri) * nb)) == NULL)
		return (NULL);
	i = 0;
	while (i < nb)
	{
		tabtetri[i].piece = tab[i];
		tabtetri[i].letter = 'A' + i;
		tabtetri[i].used = 0;
		i++;
	}
	return (tabtetri);
}

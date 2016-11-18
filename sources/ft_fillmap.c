/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 10:37:12 by mrajaona          #+#    #+#             */
/*   Updated: 2016/11/18 16:39:21 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int			ft_doesitfit(t_tetri *src, unsigned int dest,
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

static int			ft_itfits(t_map *map, t_tetri *tetri, t_pos *pos)
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

static int			ft_fill(t_args *a, t_pos *pos)
{
	int	i;
	int	p;
	int	nb;

	p = 0;
	while (a->ptab[p])
		p++;
	nb = 0;
	while (a->ttab[nb].piece > 0)
		nb++;
	i = 0;
	while (i < nb)
	{
		if (a->ttab[i].used == 0 && ft_itfits(a->map, &(a->ttab[i]), pos))
		{
			ft_tetricpy(a->map, &(a->ttab[i]), pos);
			a->ptab[p] = a->ttab[i].letter;
			p++;
		}
		i++;
	}
	return (p);
}

int					ft_fillmap(t_args *args, const int nb)
{
	t_pos	pos;
	int		p;

	p = 0;
	while (p <= nb)
		args->ptab[p++] = '\0';
	p = 0;
	pos.y = 0;
	while (pos.y < args->map->size)
	{
		pos.x = 0;
		while (pos.x < args->map->size)
		{
			p = ft_fill(args, &pos);
			pos.x++;
		}
		pos.y++;
	}
	return (p);
}

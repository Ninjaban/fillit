/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 10:37:12 by mrajaona          #+#    #+#             */
/*   Updated: 2016/11/20 14:58:14 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_setpos(t_pos *pos, int x, int y)
{
	pos->x = x;
	pos->y = y;
}

static void	ft_chktetri(t_args *args, int *t, int *p, t_pos *pos)
{
	while (TTAB[*t].piece != 0
			&& (TTAB[*t].used != 0 || ft_itfits(MAP, &(TTAB[*t]), pos) == 0))
		(*t)++;
	if (TTAB[*t].piece != 0)
	{
		ft_tetricpy(MAP, &(TTAB[*t]), pos);
		PTAB[*p] = TTAB[*t].letter;
		(*p)++;
		*t = 0;
	}
}

static int	ft_fill(t_args *args, int t, int p, t_pos *pos)
{
	if (TTAB[t].piece == 0)
	{
		if (p == t || pos->y == MAP->size)
			return (p);
		t = 0;
		pos->x++;
	}
	if (pos->x == MAP->size)
		ft_setpos(pos, 0, pos->y + 1);
	if (pos->y == MAP->size)
	{
		if (p == 0)
			return (p);
		p--;
		t = 0;
		while (TTAB[t].letter != PTAB[p])
			t++;
		ft_setpos(pos, TTAB[t].pos.x, TTAB[t].pos.y);
		ft_cleanmap(args, p);
		t++;
	}
	ft_chktetri(args, &t, &p, pos);
	return (ft_fill(args, t, p, pos));
}

int			ft_fillmap(t_args *args, const int nb)
{
	t_pos	pos;
	int		p;

	p = 0;
	while (p <= nb)
		PTAB[p++] = '\0';
	ft_setpos(&pos, 0, 0);
	return (ft_fill(args, 0, 0, &pos));
}

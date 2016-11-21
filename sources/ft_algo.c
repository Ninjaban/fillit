/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 12:33:48 by jcarra            #+#    #+#             */
/*   Updated: 2016/11/21 09:25:38 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

static int	ft_is_printable(t_map **map, short tetri, t_point *pos)
{
	int		n;

	n = -1;
	if (pos->x >= (*map)->size || pos->y >= (*map)->size)
		return (FALSE);
	while (++n < 16)
	{
		if (((tetri & (1 << n)) != 0) && ((pos->y + (n / 4) >= (*map)->size) ||
			(pos->x + (n % 4) >= (*map)->size)))
			return (FALSE);
		else if (((tetri & (1 << n)) != 0) &&
			((*map)->map[pos->y + (n / 4)][pos->x + (n % 4)] != '.'))
			return (FALSE);
	}
	return (TRUE);
}

static void	ft_print(t_map **map, short tetri, t_point **pos, char name)
{
	int		n;

	n = -1;
	while (++n < 16)
		if ((tetri & (1 << n)) != 0)
			(*map)->map[(*pos)->y + (n / 4)][(*pos)->x + (n % 4)] = name;
}

static void	ft_clean(t_map **map, char name)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < (*map)->size)
	{
		x = 0;
		while (x < (*map)->size)
		{
			if ((*map)->map[y][x] == name)
				(*map)->map[y][x] = '.';
			x = x + 1;
		}
		y = y + 1;
	}
}

static int	ft_algo_rec(t_map **map, short *tetri, t_point *pos, int nb)
{
	size_t	x;
	size_t	y;

	if (nb == (*map)->nb)
		return (TRUE);
	ft_setpoint(&pos, 0, 0, (*map)->size);
	while (pos->y < (*map)->size)
	{
		while ((ft_is_printable(map, tetri[nb], pos) != TRUE) &&
				(pos->y < (*map)->size))
			ft_setpoint(&pos, pos->x + 1, pos->y, (*map)->size);
		if (pos->y >= (*map)->size)
			return (FALSE);
		ft_print(&(*map), tetri[nb], &pos, (char)(nb + 'A'));
		x = pos->x;
		y = pos->y;
		if (ft_algo_rec(&(*map), tetri, pos, nb + 1) == TRUE)
			return (TRUE);
		ft_clean(&(*map), (char)(nb + 'A'));
		ft_setpoint(&pos, x + 1, y, (*map)->size);
	}
	return (FALSE);
}

int			ft_algo(int nb, short *tetri)
{
	t_map	*map;
	t_point	*pos;

	if ((map = malloc(sizeof(t_map))) == NULL)
		return (FALSE);
	if ((pos = malloc(sizeof(t_point))) == NULL)
		return (FALSE);
	map->size = 2;
	map->map = NULL;
	map->nb = nb;
	while ((map->size * map->size) < (size_t)(map->nb * 4))
		map->size++;
	if (ft_setmap(map->size, &map->map) == -1)
		return (FALSE);
	while (ft_algo_rec(&map, tetri, pos, 0) == FALSE)
	{
		map->size++;
		if (ft_setmap(map->size, &map->map) == -1)
			return (FALSE);
	}
	ft_display(&map);
	ft_free_map(map->map, map->size);
	free(pos);
	free(map);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 13:03:10 by jcarra            #+#    #+#             */
/*   Updated: 2016/11/20 15:50:06 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

void		ft_setpoint(t_point **pos, int x, int y, size_t size)
{
	if (x >= 0 && y >= 0)
	{
		(*pos)->x = (size_t)x;
		(*pos)->y = (size_t)y;
		if ((*pos)->x >= size)
		{
			(*pos)->x = 0;
			(*pos)->y++;
		}
	}
	else
	{
		(*pos)->x = size - 1;
		(*pos)->y--;
	}
}

void		ft_free_map(char **map, size_t size)
{
	size_t	n;

	n = 0;
	while (n < size)
		free(map[n++]);
	free(map);
}

static void	ft_comp_map(size_t size, char ***map)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
			(*map)[y][x++] = '_';
		y = y + 1;
	}
}

int			ft_setmap(size_t size, char ***map)
{
	size_t	n;

	n = 0;
	if (*map)
		ft_free_map(*map, size - 1);
	if ((*map = malloc(sizeof(char *) * size)) == NULL)
		return (-1);
	while (n < size)
		(*map)[n++] = NULL;
	n = 0;
	while (n < size)
		if (((*map)[n++] = malloc(size)) == NULL)
		{
			ft_free_map(*map, n);
			return (-1);
		}
	ft_comp_map(size, &(*map));
	return (0);
}

void		ft_display(t_map **map)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < (*map)->size)
	{
		x = 0;
		while (x < (*map)->size)
			ft_putchar((*map)->map[y][x++]);
		ft_putchar('\n');
		y = y + 1;
	}
}

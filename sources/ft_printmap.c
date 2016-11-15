/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 12:18:39 by mrajaona          #+#    #+#             */
/*   Updated: 2016/11/15 11:56:47 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

static char	**ft_createmap(t_map *map)
{
	char	**filled;
	int		i;
	int		j;

	if ((filled = (char **)malloc(sizeof(char *) * map->size)) == NULL)
		return (NULL);
	i = 0;
	while (i < map->size)
	{
		if ((filled[i] = (char *)malloc(map->size + 2)) == NULL)
		{
			while (--i >= 0)
				free(filled[i]);
			free(filled);
			return (NULL);
		}
		j = 0;
		while (j < map->size)
			filled[i][j++] = '.';
		filled[i][j++] = '\n';
		filled[i][j] = '\0';
		i++;
	}
	return (filled);
}

static char	**ft_placetetri(char **map, t_tetri *tetri, unsigned char size)
{
	int		n;
	char	p;

	p = 0;
	n = 0;
	while (n < 16 && n / 4 < size && p != 4)
	{
		if ((tetri->pos.x + (n % 4)) < size && B_TEST1(tetri->piece, n))
		{
			map[tetri->pos.y + (n / 4)][tetri->pos.x + (n % 4)] = tetri->letter;
			p++;
		}
		n++;
	}
	return (map);
}

void		ft_printmap(t_map *map, t_tetri *tetri, const int nb)
{
	char	**filled;
	int		i;

	if ((filled = ft_createmap(map)) == NULL)
		return ;
	i = 0;
	while (i < nb)
		ft_placetetri(filled, &(tetri[i++]), map->size);
	i = 0;
	while (i < map->size)
		ft_putstr(filled[i++]);
}

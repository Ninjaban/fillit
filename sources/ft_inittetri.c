/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inittetri.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 10:19:07 by mrajaona          #+#    #+#             */
/*   Updated: 2016/11/20 09:28:06 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_geth(const short tetri)
{
	int	h;

	h = 0;
	while (B_TESTF(tetri, 4 * (h + 1)) != 0 && h < 4)
		h++;
	return (h);
}

static int	ft_getw(const short tetri)
{
	int	i;
	int	j;
	int	w;
	int	tmp;

	i = 0;
	w = 0;
	while (i < 4)
	{
		j = 0;
		tmp = 0;
		while (j < 4)
		{
			tmp = (B_TEST1(tetri, (4 * i) + j) == 0 ? tmp : (j + 1));
			j++;
		}
		w = MAX(w, tmp);
		i++;
	}
	return (w);
}

t_tetri		*ft_tabtetri(int nb, const short *tab)
{
	t_tetri	*tabtetri;
	int		i;

	if ((tabtetri = (t_tetri *)malloc(sizeof(t_tetri) * (nb + 1))) == NULL)
		return (NULL);
	i = 0;
	while (i < nb)
	{
		tabtetri[i].piece = tab[i];
		tabtetri[i].letter = 'A' + i;
		tabtetri[i].size.h = ft_geth(tab[i]);
		tabtetri[i].size.w = ft_getw(tab[i]);
		tabtetri[i].pos.x = 0;
		tabtetri[i].pos.y = 0;
		tabtetri[i].used = 0;
		i++;
	}
	tabtetri[i].piece = 0;
	return (tabtetri);
}

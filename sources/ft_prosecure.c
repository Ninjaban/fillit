/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prosecure.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 10:56:18 by jcarra            #+#    #+#             */
/*   Updated: 2016/11/10 13:00:47 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int			ft_fillit_secure_pro_cmp(short *tab, int n)
{
	int		i;

	i = 0;
	while (i < 27)
	{
		if (i == n)
			i = i + 1;
		if (tab[i] == tab[n])
			return (1);
		i = i + 1;
	}
	return (0);
}

int			ft_fillit_secure_pro(short *tab)
{
	int		n;

	n = 0;
	while (tab[n] != 0)
	{
		if (ft_fillit_secure_pro_cmp(tab, n) == 1)
			return (-1);
	}
	return (0);
}

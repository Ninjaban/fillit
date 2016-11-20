/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 09:14:19 by jcarra            #+#    #+#             */
/*   Updated: 2016/11/20 12:39:57 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

static int	ft_free_stab(char *str, short *tab)
{
	if (str)
		free(str);
	if (tab)
		free(tab);
	return (-1);
}

int			ft_fillit(const char *name)
{
	char	*str;
	short	*tab;
	int		nb;

	if ((str = ft_fillit_read(name)) == NULL)
		return (-1);
	if (ft_fillit_secure_base(str) == -1)
		return (ft_free_stab(str, NULL));
	if ((tab = ft_fillit_parsing(str)) == NULL)
		return (ft_free_stab(str, NULL));
	nb = 0;
	while (tab[nb])
		nb = nb + 1;
	ft_algo(nb, tab);
	ft_free_stab(str, tab);
	return (0);
}

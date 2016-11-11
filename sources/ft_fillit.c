/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 09:14:19 by jcarra            #+#    #+#             */
/*   Updated: 2016/11/11 09:04:16 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

static void	ft_print_all(short *tab)
{
	int		n;
	int		i;

	n = -1;
	while (tab[++n])
	{
		i = -1;
		while (++i < 16)
		{
			if (i % 4 == 0)
				ft_putstr("\n");
			ft_putstr(((tab[n] & (1 << i)) == 0) ? "." : "#");
		}
		ft_putstr("\n");
	}
}

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

	if ((str = ft_fillit_read(name)) == NULL)
		return (-1);
	if (ft_fillit_secure_base(str) == -1)
		return (ft_free_stab(str, NULL));
	if ((tab = ft_fillit_parsing(str)) == NULL)
		return (ft_free_stab(str, NULL));
	if (ft_fillit_secure_pro(tab) == -1)
		return (ft_free_stab(str, tab));
	ft_print_all(tab);
	ft_free_stab(str, tab);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:40:02 by jcarra            #+#    #+#             */
/*   Updated: 2016/11/21 11:55:27 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

static short	ft_fillit_parsing_block_align(short bit)
{
	int			n;

	while ((bit & (1 << 0)) == 0 && (bit & (1 << 1)) == 0 &&
			(bit & (1 << 2)) == 0 && (bit & (1 << 3)) == 0)
	{
		n = 3;
		while (++n < 16)
			if ((bit & (1 << n)) != 0)
			{
				bit = bit | (1 << (n - 4));
				bit = bit & ~(1 << n);
			}
	}
	while ((bit & (1 << 0)) == 0 && (bit & (1 << 4)) == 0 &&
			(bit & (1 << 8)) == 0 && (bit & (1 << 12)) == 0)
	{
		n = 0;
		while (++n < 16)
			if ((bit & (1 << n)) != 0)
			{
				bit = bit | (1 << (n - 1));
				bit = bit & ~(1 << n);
			}
	}
	return (bit);
}

static short	ft_fillit_parsing_block(short bit, char *str, int start)
{
	int			n;

	n = 0;
	while (n < 16)
	{
		if (str[start] == '\n')
			start = start + 1;
		bit = (str[start++] == '.') ? bit & ~(1 << n) : bit | (1 << n);
		n = n + 1;
	}
	bit = ft_fillit_parsing_block_align(bit);
	return (bit);
}

static int		ft_fillit_parsing_alloc(short **tab, char *str)
{
	int			start;
	int			end;
	int			n;

	start = 0;
	end = 0;
	n = 0;
	while (str[start])
	{
		while (str[end] && str[end] != '\n')
		{
			end = end + 1;
			if (str[end] == '\n' &&
				(str[end + 1] != '\n' && str[end + 1] != '\0'))
				end = end + 1;
		}
		(*tab)[n] = ft_fillit_parsing_block((*tab)[n], str, start);
		while (str[end] == '\n')
			end = end + 1;
		start = end;
		if (++n > 27)
			return (-1);
	}
	return (0);
}

short			*ft_fillit_parsing(char *str)
{
	short		*tab;
	int			n;

	n = 0;
	if ((tab = malloc(sizeof(short) * 27)) == NULL)
		return (NULL);
	while (n < 27)
		tab[n++] = 0;
	if (ft_fillit_parsing_alloc(&tab, str) == -1 || !tab[0])
	{
		free(tab);
		return (NULL);
	}
	return (tab);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_secure.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 14:34:37 by jcarra            #+#    #+#             */
/*   Updated: 2016/11/11 10:13:16 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdio.h>

static int	ft_fillit_secure_block_rec(char *str, int start, int end, int n)
{
	int		nb;

	nb = 0;
	str[n] = '0';
	if (n + 1 < end && str[n + 1] == '#')
		nb = nb + ft_fillit_secure_block_rec(str, start, end, n + 1);
	if (n - 1 >= start && str[n - 1] == '#')
		nb = nb + ft_fillit_secure_block_rec(str, start, end, n - 1);
	if (n + 5 < end && str[n + 5] == '#')
		nb = nb + ft_fillit_secure_block_rec(str, start, end, n + 5);
	if (n - 5 >= start && str[n - 5] == '#')
		nb = nb + ft_fillit_secure_block_rec(str, start, end, n - 5);
	ft_putnbr(nb);
	return (nb + 1);
}

static int	ft_fillit_secure_block(char *str, int start, int end)
{
	int		n;

	n = start;
	while (str[n] != '#')
		n = n + 1;
	if (ft_fillit_secure_block_rec(str, start, end, n) != 4)
		return (-1);
	return (0);
}

static int	ft_fillit_secure_count(char *str, int start, int end)
{
	int		n;
	int		nb;

	n = start - 1;
	nb = 0;
	while (++n < end)
		if (str[n] == '#')
			nb = nb + 1;
	if (nb != 4)
		return (-1);
	return (0);
}

static int	ft_fillit_secure_tetri(char *str, int start, int end)
{
	int		n;
	int		nb;

	n = start - 1;
	while (++n < end)
		if (str[n] != '.' && str[n] != '#' && str[n] != '\n')
			return (-1);
	if (ft_fillit_secure_count(str, start, end) == -1)
		return (-1);
	n = start - 1;
	nb = 0;
	while (++n < end)
		if (str[n] == '\n')
		{
			if (nb != 4)
				return (-1);
			nb = 0;
		}
		else
			nb = nb + 1;
	if (ft_fillit_secure_block(str, start, end) == -1)
		return (-1);
	return (0);
}

int			ft_fillit_secure_base(char *str)
{
	int		start;
	int		end;

	start = 0;
	end = 0;
	while (str[start])
	{
		while (str[end] && str[end] != '\n')
			if (str[++end] == '\n' &&
				(str[end + 1] != '\n' && str[end + 1] != '\0'))
				end = end + 1;
		if (end - start != 19)
			return (-1);
		if (ft_fillit_secure_tetri(str, start, end) == -1)
			return (-1);
		start = end;
		while (str[end] == '\n')
			end = end + 1;
		if (end - start != 2 && (end - start != 1 || str[end] != '\0'))
			return (-1);
		start = end;
	}
	if (start > 535)
		return (-1);
	return (0);
}

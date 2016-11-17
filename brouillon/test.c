/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 10:22:33 by mrajaona          #+#    #+#             */
/*   Updated: 2016/11/17 10:17:44 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "test.h"

void     ft_print_all(unsigned int res)
{
	unsigned int i = 0;

	while (i < 32)
	{
		if (i == 0)
			write(1, ".",1);
		if (i % 4 == 0)
			write(1, ":",1);
		write(1, ((res & (1 << i)) == 0) ? "0" : "1", 1);

		i++;
	}
	write(1, "\n", 1);
}

unsigned short calc(unsigned int a, unsigned short b)
{
	unsigned int	mask;
	int n = 4;
	int pa = 4 * 5;
	int pb = 4;

	mask = ((1 << (n)) - 1) << (pa - n);

	printf("src :\t%08X\ndest :\t%08X\nmask :\t%08X\n", a, b, mask);
	printf("m :\t%08X\n\n", (~a & mask) >> (pa - pb));

	return (b | (((~a & mask) >> (pa - pb)) ^ (b | (mask >> (pa - pb)))));
}

int main(void)
{
	unsigned int	a;
	unsigned short	b;
	unsigned short	c;
	t_mapl			d;

	a = 0x00060500;
	b = 0xF1FF;
	c = calc(a, b);
	ft_print_all(a);
	ft_print_all(b);
	ft_print_all(c);
	printf("res :\t%08X\n\n-----\n\n", c);

	a = 0x00060100;
	b = 0xF19F;
	c = calc(a, b);
	ft_print_all(a);
	ft_print_all(b);
	ft_print_all(c);
	printf("res :\t%08X\n\n-----\n\n", c);

	a = 0xFFF90FFF;
	b = 0x0100;
	c = calc(a, b);
	ft_print_all(a);
	ft_print_all(b);
	ft_print_all(c);
	printf("res :\t%08X\n\n-----\n\n", c);

	a = 0xFFF901FF;
	b = 0x0160;
	c = calc(a, b);
	ft_print_all(a);
	ft_print_all(b);
	ft_print_all(c);
	d.line = 0x1FFFFF;
	printf("res :\t%08X\n\n-----\n\n", c);
	printf("res :\t%08X\n\n-----\n\n", d.line);

	return (0);
}

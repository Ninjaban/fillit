/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 09:12:18 by jcarra            #+#    #+#             */
/*   Updated: 2016/11/15 13:01:22 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define X 1
# define Y 0
# define B_TEST1(var, n) (var & (1 << n))
# define B_TESTF(var, n) (var & (0xF << (n - 4)))
# define B_TESTFF(var, n) (var & (0xFF << (n - 8)))
# define B_ONE(var, n) (var | (1 << n))
# define B_ZERO(var, n) var & ~(1 << n)
# define B_REV(var, n) var ^ (1 << n)

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>

/*
** size max = 21 (fits all 26 * 4 * 4 pieces)
** max value for line = 0x1FFFFF
** max value for piece = 0xFFFF
*/

typedef struct	s_mapl
{
	unsigned int	line : 21;
}				t_mapl;

typedef struct	s_map
{
	t_mapl			*map;
	unsigned char	size : 5;
}				t_map;

typedef struct	s_pos
{
	int	x;
	int	y;
}				t_pos;

typedef struct	s_tetri
{
	unsigned short	piece;
	char			letter;
	char			used;
	t_pos			pos;
}				t_tetri;

/*
**	Functions
*/

int				ft_fillit(const char *name);
int				ft_fillit_secure_base(char *str);
int				ft_fillit_secure_pro(short *tab);
char			*ft_fillit_read(const char *name);
short			*ft_fillit_parsing(char *str);
void			ft_map(const int nb, short *tab);
t_map			*ft_makemap(t_map *map, const unsigned char size);
t_map			*ft_fillmap(unsigned char size, t_tetri *tab, const int nb);
void			ft_tetricpy(t_map *map, t_tetri *tetri, t_pos *pos);
void			ft_tetridel(t_map *map, t_tetri *tetri);
t_tetri			*ft_tabtetri(int nb, const short *tab);
void			ft_printmap(t_map *map, t_tetri *tetri, const int nb);

/* DEBUG */
void 			ft_print_all(t_map *map);

#endif

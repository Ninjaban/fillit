/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 09:12:18 by jcarra            #+#    #+#             */
/*   Updated: 2016/11/20 14:40:14 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define X 1
# define Y 0
# define TRUE 1
# define FALSE 0
# define B_TEST1(var, n) (var & (1 << (n)))
# define B_TESTF(var, n) (var & (0xF << (n - 4)))
# define B_TESTFF(var, n) (var & (0xFF << (n - 8)))
# define B_ONE(var, n) (var | (1 << (n)))
# define B_ZERO(var, n) (var & ~(1 << (n)))
# define B_REV(var, n) (var ^ (1 << (n)))
# define MAX(x, y) (x > y ? x : y)

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>

/*
** size max = 24 (fits all 26 * 4 * 4 pieces)
** max value for line = 0xFFFFFF
** max value for piece = 0xFFFF
*/

/*
typedef struct	s_mapl
{
	unsigned int	line : 24;
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

typedef struct	s_tsize
{
	int	h;
	int	w;
}				t_tsize;

typedef struct	s_tetri
{
	unsigned short	piece;
	char			letter;
	char			used;
	t_tsize			size;
	t_pos			pos;
}				t_tetri;

typedef struct	s_args
{
	t_map	*map;
	t_tetri	*ttab;
	char	*ptab;
}				t_args;
*/

typedef struct	s_point
{
	size_t		x;
	size_t		y;
}				t_point;

typedef struct	s_map
{
	size_t		size;
	char		**map;
	int			nb;
}				t_map;

/*
**	Functions
*/

int				ft_fillit(const char *name);
int				ft_fillit_secure_base(char *str);
int				ft_fillit_secure_pro(short *tab);
char			*ft_fillit_read(const char *name);
short			*ft_fillit_parsing(char *str);
/*
void			ft_map(const int nb, short *tab);
t_map			*ft_makemap(t_map *map, const unsigned char size, t_args *args);
t_map			*ft_solve(unsigned char size, t_tetri *tab, const int nb);
int				ft_fillmap(t_args *args, const int nb);
void			*ft_freemap(t_map *map);
void			ft_freeargs(t_args *args);
void			ft_tetricpy(t_map *map, t_tetri *tetri, t_pos *pos);
void			ft_tetridel(t_map *map, t_tetri *tetri);
t_tetri			*ft_tabtetri(int nb, const short *tab);
void			ft_printmap(t_map *map, t_tetri *tetri, const int nb);
*/

int			ft_algo(int nb, short *tetri);
void		ft_setpoint(t_point **pos, int x, int y, size_t size);
void		ft_free_map(char **map, size_t size);
int			ft_setmap(size_t size, char ***map);
void		ft_display(t_map **map);

#endif

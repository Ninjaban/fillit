/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 09:12:18 by jcarra            #+#    #+#             */
/*   Updated: 2016/11/21 09:36:34 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define X 1
# define Y 0
# define TRUE 1
# define FALSE 0

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>

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
int				ft_algo(int nb, short *tetri);
void			ft_setpoint(t_point **pos, int x, int y, size_t size);
void			ft_free_map(char **map, size_t size);
int				ft_setmap(size_t size, char ***map);
void			ft_display(t_map **map);

#endif

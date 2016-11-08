/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 09:12:18 by jcarra            #+#    #+#             */
/*   Updated: 2016/11/08 09:43:00 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define X 1
# define Y 0

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>


/*
**	Structure
*/

typedef struct	s_tetri
{
	int			*p1;
	int			*p2;
	int			*p3;
	int			*p4;
}				t_tetri;

/*
**	Fonctions
*/

int			ft_fillit(const char *name);

#endif













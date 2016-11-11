/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 09:12:18 by jcarra            #+#    #+#             */
/*   Updated: 2016/11/11 09:03:22 by jcarra           ###   ########.fr       */
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
**	Fonctions
*/

int			ft_fillit(const char *name);
int			ft_fillit_secure_base(char *str);
int			ft_fillit_secure_pro(short *tab);
char		*ft_fillit_read(const char *name);
short		*ft_fillit_parsing(char *str);

#endif

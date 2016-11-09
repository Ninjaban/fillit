/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 09:14:19 by jcarra            #+#    #+#             */
/*   Updated: 2016/11/09 12:48:20 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int			ft_fillit(const char *name)
{
	char	*str;

	if ((str = ft_fillit_read(name)) == NULL)
		return (-1);
	if (ft_fillit_secure_base(str, 0, 0) == -1)
		return (-1);
	ft_putstr("Tout est ok.\n");
	/*ft_fillit_parsing(str);*/
	free(str);
	return (0);
}

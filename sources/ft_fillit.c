/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 09:14:19 by jcarra            #+#    #+#             */
/*   Updated: 2016/11/09 09:26:49 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int			ft_fillit(const char *name)
{
	char	*str;

	if ((str = ft_fillit_read(name)) == NULL)
		return (-1);
	if (ft_fillit_secure_base(str) == -1)
		return (-1);
	/*ft_fillit_parsing(str);*/
	free(str);
	return (0);
}

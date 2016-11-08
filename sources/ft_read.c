/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 14:31:40 by jcarra            #+#    #+#             */
/*   Updated: 2016/11/08 14:32:16 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

char		*ft_fillit_read(const char *name)
{
	char	*str;
	char	*tmp;
	char	buf[4097];
	int		fd;
	int		ret;

	if ((fd = open(name, O_RDONLY)) == -1)
		return (NULL);
	if ((str = malloc(1)) == NULL)
		return (NULL);
	str[0] = '\0';
	while ((ret = read(fd, buf, 4096)) == 4096)
	{
		buf[ret] = '\0';
		if ((tmp = ft_strjoin(str, buf)) == NULL)
			return (NULL);
		free(str);
		str = tmp;
	}
	buf[ret] = '\0';
	if ((tmp = ft_strjoin(str, buf)) == NULL)
		return (NULL);
	free(str);
	str = tmp;
	return (str);
}

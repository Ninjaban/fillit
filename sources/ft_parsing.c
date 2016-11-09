/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:40:02 by jcarra            #+#    #+#             */
/*   Updated: 2016/11/08 16:46:35 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_tetri		**ft_fillit_parsing(char *str)
{
	t_tetri	**tetris;
	int		n;

	n = 0;
	if ((tetris = malloc(sizeof (t_tetri *) * 26)) == NULL)
	  return (NULL);
	while (n < 26)
	  tetris[n++] = NULL;
	/* --- */
	return (tetris);
}

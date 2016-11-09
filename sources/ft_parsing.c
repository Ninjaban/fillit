/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:40:02 by jcarra            #+#    #+#             */
/*   Updated: 2016/11/09 12:02:58 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void				ft_tetri_free(t_tetri **tetris)
{
	int				n;

	n = 0;
	if (tetris != NULL)
	{
		while (tetris[n] != NULL)
			free(tetris[n++]);
		free(tetris);
	}
}

static t_tetri		**ft_fillit_parsing_alloc(t_tetri **tetris, char *str)
{
	int				start;
	int				end;

	start = 0;
	end = 0;
	while ()
}

t_tetri				**ft_fillit_parsing(char *str)
{
	t_tetri			**tetris;
	int				n;

	n = 0;
	if ((tetris = malloc(sizeof (t_tetri *) * 26)) == NULL)
	  return (NULL);
	while (n < 26)
	  tetris[n++] = NULL;
	tetris = ft_fillit_parsing_alloc(tetris, str);
	/* --- */
	return (tetris);
}

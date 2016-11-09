/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:40:02 by jcarra            #+#    #+#             */
/*   Updated: 2016/11/09 13:46:15 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_tetri_free(t_tetri **tetris)
{
	int		n;

	n = 0;
	if (tetris != NULL)
	{
		while (tetris[n] != NULL)
			free(tetris[n++]);
		free(tetris);
	}
}

static t_tetri	ft_fillit_parsing_block(t_tetri *tetri, char *str,
										int start, int end)
{
	if ((tetri = malloc(sizeof(t_tetri))) == NULL)
		return (NULL);
}

static void	ft_fillit_parsing_alloc(t_tetri ***tetris, char *str)
{
	int		start;
	int		end;
	int		n;

	start = 0;
	end = 0;
	n = 0;
	while (str[start])
	{
		while (str[end] && str[end] != '\n')
		{
			end = end + 1;
			if (str[end] == '\n' && (str[end + 1] != '\n' && str[end + 1] != '\0'))
				end = end + 1;
		}
		if (((*tetris)[n] = ft_fillit_parsing_block((*tetris)[n], str, start, end)) == NULL)
			return (NULL);
	}
}

t_tetri		**ft_fillit_parsing(char *str)
{
	t_tetri	**tetris;
	int		n;

	n = 0;
	if ((tetris = malloc(sizeof (t_tetri *) * 26)) == NULL)
	  return (NULL);
	while (n < 26)
	  tetris[n++] = NULL;
	if (ft_fillit_parsing_alloc(&tetris, str))
	{
		ft_tetri_free(tetris);
		return (NULL);sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss
	}
	/* --- */
	return (tetris);
}

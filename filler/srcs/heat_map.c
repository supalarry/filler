/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   heat_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/19 14:55:14 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/05/19 14:55:16 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "filler_header.h"

/*
** @desc Find if a dot aka empty spot still exists in board
** @param char **tab - two dimensional array representing board
** @param int height - height of the rectangle
** @param int width - width of the rectangle
** @return int 1 if '.' was found
** @return int 0 if no '.' was found
*/

int		dot_found(int **tab, int height, int width)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < height)
	{
		while (j < width)
		{
			if (tab[i][j] == '.')
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

/*
** @desc Place 1's around enemy pieces and create numeric heat map
** @param t_rect *board - structure storing board and it's dimensions
** @param char computer_piece - piece computer uses for playing
** @return void
*/

void	heat_map(t_rect *board, char computer_piece)
{
	int	current;

	current = 100;
	ones(board->rectangle_copy, board->height, board->width, computer_piece);
	while (dot_found(board->rectangle_copy, board->height, board->width))
	{
		current++;
		if (increment(board->rectangle_copy,
		board->height, board->width, current) == 0)
			break ;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   coordinates_support.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/19 14:54:29 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/05/19 14:54:32 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "filler_header.h"

/*
** @desc Starting at specific location on board, iterate right and down
** @desc based on size of piece and try to find player's piece in that range
** @param t_rect *piece - structure storing piece, cut shape and dimensions
** @param t_rect *board - structure storing board and it's dimensions
** @param int *coords - coordinates used to iterate all over the board
** @param t_players *players - structure storing players' numbers and pieces
** @return int 1 if within shape's coordinate range starting from specific
** @return coordinates on board player's piece exists
** @return int 0 if player's piece in scenario above was not found
*/

int	piece_found(t_rect *piece, t_rect *board, int *coords, t_players *players)
{
	int	i;
	int	j;
	int	max_i;
	int	max_j;

	i = coords[0];
	j = coords[1];
	max_i = i + piece->shape_height;
	max_j = j + piece->shape_width;
	while (i < max_i)
	{
		while (j < max_j)
		{
			if (board->rectangle[i][j] == players->my_piece)
				return (1);
			j++;
		}
		j = coords[1];
		i++;
	}
	return (0);
}

/*
** @desc Starting at specific coordinate on board, calculate values of each
** @desc cell if shape would be placed at that coordinate. This is done because
** @desc heat map was generated before surrounding enemy piece. Lowest sum
** @desc means that we are closest to blocking enemy.
** @param t_rect *piece - structure storing piece, cut shape and dimensions
** @param t_rect *board - structure storing board and it's dimensions
** @param int *coordinates - values used to iterate all over the board
** @return int as sum of values of cells under piece if it was placed
*/

int	piece_sum(t_rect *piece, t_rect *board, int *coordinates)
{
	int	i;
	int	j;
	int	max_i;
	int	max_j;
	int	sum;

	i = coordinates[0];
	j = coordinates[1];
	max_i = i + piece->shape_height;
	max_j = j + piece->shape_width;
	sum = 0;
	while (i < max_i)
	{
		while (j < max_j)
		{
			sum = sum + board->rectangle_copy[i][j];
			j++;
		}
		j = coordinates[1];
		i++;
	}
	return (sum);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/19 14:56:21 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/05/19 14:56:22 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "filler_header.h"

/*
** @desc Decide increment() function's return value
** @param int valid_dot - value determining return value
** @return void
*/

int		increment_return(int valid_dot)
{
	if (valid_dot == 1)
		return (1);
	return (0);
}

/*
** @desc Decide piece_overlay() function's return value
** @param int overlays - value determining return value
** @return void
*/

int		overlay_return(int overlays)
{
	if (overlays == 1)
		return (1);
	return (0);
}

/*
** @desc Replace player's game piece with dots to create heat map
** @param int **rectangle_copy - copy of board
** @param int height - board's height
** @param int width - board's width
** @param char my_piece - piece to replace by dots
** @return void
*/

void	dots(int **rectangle_copy, int height, int width, char my_piece)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < height)
	{
		while (j < width)
		{
			if (rectangle_copy[i][j] == my_piece)
				rectangle_copy[i][j] = '.';
			j++;
		}
		j = 0;
		i++;
	}
}

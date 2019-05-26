/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   increment_support.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/19 14:55:23 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/05/19 14:55:24 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "filler_header.h"

/*
** @desc Create heatmap points around specific cell left, up, right and down
** @param char **tab - two dimensional array representing board
** @param int *dimensions - array storing dimensions of board
** @param int *coords - array storing current location on a board
** @param int current - current value in heatmap
** @return int 1 if there is a coordinate where shape can be placed
** @return int 0 if there is not a coordinate where shape can be placed
*/

int	not_horizontal_cords(int **tab, int *coords, int *dimensions, int current)
{
	int	i;
	int	j;
	int	height;
	int	width;

	i = coords[0];
	j = coords[1];
	height = dimensions[0];
	width = dimensions[1];
	if (i < (height - 1) && tab[i + 1][j] == '.' && tab[i][j] != current)
		tab[i + 1][j] = current;
	if (i > 0 && tab[i - 1][j] == '.' && tab[i][j] != current)
		tab[i - 1][j] = current;
	if (j < (width - 1) && tab[i][j + 1] == '.' && tab[i][j] != current)
		tab[i][j + 1] = current;
	if (j > 0 && tab[i][j - 1] == '.' && tab[i][j] != current)
		tab[i][j - 1] = current;
	if ((i < (height - 1) && tab[i + 1][j] == current) ||
	(i > 0 && tab[i - 1][j] == current)
	|| (j < (width - 1) && tab[i][j + 1] == current) ||
	(j > 0 && tab[i][j - 1] == current))
		return (1);
	return (0);
}

/*
** @desc Create heatmap points around specific cell diognally
** @param char **tab - two dimensional array representing board
** @param int *dimensions - array storing dimensions of board
** @param int *coordinates - array storing current location on a board
** @param int c - current value in heatmap
** @return int 1 if there is a coordinate where shape can be placed
** @return int 0 if there is not a coordinate where shape can be placed
*/

int	horizontal_cords(int **tab, int *coordinates, int *dimensions, int c)
{
	int	i;
	int	j;
	int	height;
	int	width;

	i = coordinates[0];
	j = coordinates[1];
	height = dimensions[0];
	width = dimensions[1];
	if (i < (height - 1) && j < (width - 1) && tab[i + 1][j + 1] == '.'
	&& tab[i][j] != c)
		tab[i + 1][j + 1] = c;
	if (i < (height - 1) && j > 0 && tab[i + 1][j - 1] == '.'
	&& tab[i][j] != c)
		tab[i + 1][j - 1] = c;
	if (i > 0 && j < (width - 1) && tab[i - 1][j + 1] == '.' && tab[i][j] != c)
		tab[i - 1][j + 1] = c;
	if (i > 0 && j > 0 && tab[i - 1][j - 1] == '.' && tab[i][j] != c)
		tab[i - 1][j - 1] = c;
	if ((i < (height - 1) && tab[i + 1][j + 1] == c) ||
	(i < (height - 1) && tab[i + 1][j - 1] == c)
	|| (i > 0 && tab[i - 1][j + 1] == c) ||
	(i > 0 && tab[i - 1][j - 1] == c))
		return (1);
	return (0);
}

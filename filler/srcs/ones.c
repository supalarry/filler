/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ones.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/19 14:55:47 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/05/19 14:55:49 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "filler_header.h"

/*
** @desc Initialize variables to zero for ones() function
** @param int *i - address of variable representing y axis
** @param int *j - address of variable representing x axis
** @return void
*/

static void	initialize_variables(int *i, int *j)
{
	*i = 0;
	*j = 0;
}

/*
** @desc Place 1's around enemy's piece left, up, right, down
** @param char **tab - two dimensional array representing board
** @param int *coordinates - values storing location on board
** @param int height - height of the rectangle
** @param int width - width of the rectangle
** @return void
*/

static void	not_horizontal(int **tab, int *coordinates, int height, int width)
{
	int	i;
	int	j;

	i = coordinates[0];
	j = coordinates[1];
	if (i < (height - 1) && tab[i + 1][j] == '.')
		tab[i + 1][j] = 100;
	if (i > 0 && tab[i - 1][j] == '.')
		tab[i - 1][j] = 100;
	if (j < (width - 1) && tab[i][j + 1] == '.')
		tab[i][j + 1] = 100;
	if (j > 0 && tab[i][j - 1] == '.')
		tab[i][j - 1] = 100;
}

/*
** @desc Place 1's around enemy's piece horizontally
** @param char **tab - two dimensional array representing board
** @param int *coordinates - values storing location on board
** @param int height - height of the rectangle
** @param int width - width of the rectangle
** @return void
*/

static void	horizontal(int **tab, int *coordinates, int height, int width)
{
	int	i;
	int	j;

	i = coordinates[0];
	j = coordinates[1];
	if (i < (height - 1) && j < (width - 1) && tab[i + 1][j + 1] == '.')
		tab[i + 1][j + 1] = 100;
	if (i < (height - 1) && j > 0 && tab[i + 1][j - 1] == '.')
		tab[i + 1][j - 1] = 100;
	if (i > 0 && j < (width - 1) && tab[i - 1][j + 1] == '.')
		tab[i - 1][j + 1] = 100;
	if (i > 0 && j > 0 && tab[i - 1][j - 1] == '.')
		tab[i - 1][j - 1] = 100;
}

/*
** @desc Place 1's around enemy pieces
** @param char **tab - two dimensional array representing board
** @param int height - height of the rectangle
** @param int width - width of the rectangle
** @param char computer_piece - piece representing computer on board
** @return void
*/

void		ones(int **tab, int height, int width, int computer_piece)
{
	int	i;
	int	j;
	int	coordinates[2];

	initialize_variables(&i, &j);
	while (i < height)
	{
		while (j < width)
		{
			if (tab[i][j] == computer_piece)
			{
				coordinates[0] = i;
				coordinates[1] = j;
				not_horizontal(tab, coordinates, height, width);
				horizontal(tab, coordinates, height, width);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

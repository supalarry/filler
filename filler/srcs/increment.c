/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   increment.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/19 14:55:30 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/05/19 14:55:32 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "filler_header.h"

/*
** @desc Initialize coordinates array by storing row (i) and column (j)
** @param int *coordinates - storage array
** @param int i - variable storing row
** @param int j - variable storing column
** @return void
*/

static void	initialize_coordinates(int *coordinates, int i, int j)
{
	coordinates[0] = i;
	coordinates[1] = j;
}

/*
** @desc Initialize dimensions array by storing height and width
** @param int *dimensions - storage array
** @param int height - height of the rectangle
** @param int width - width of the rectangle
** @return void
*/

static void	initialize_dimensions(int *dimensions, int height, int width)
{
	dimensions[0] = height;
	dimensions[1] = width;
}

/*
** @desc Initialize i, j and valid_dot variables in increment() functiomn
** @param int *i - address of variable storing row
** @param int *j - address of variable storing column
** @param int *valid_dot - address of variable storing if piece can be placed
** @return void
*/

static void	initialize_variables(int *i, int *j, int *valid_dot)
{
	*i = 0;
	*j = 0;
	*valid_dot = 0;
}

/*
** @desc Update i and j variables in increment() function after each row
** @param int *i - address of variable storing row
** @param int *j - address of variable storing column
** @return void
*/

static void	update_variables(int *i, int *j)
{
	(*i)++;
	*j = 0;
}

/*
** @desc Increment fields of the board to create heat map
** @param char **tab - two dimensional array representing board
** @param int height - height of the rectangle
** @param int width - width of the rectangle
** @param char current - biggest (last) value in heatmap
** @return void
*/

int			increment(int **tab, int height, int width, int current)
{
	int	i;
	int	j;
	int	valid_dot;
	int	coordinates[2];
	int	dimensions[2];

	initialize_variables(&i, &j, &valid_dot);
	while (i < height)
	{
		while (j < width)
		{
			if (tab[i][j] >= 100)
			{
				initialize_coordinates(coordinates, i, j);
				initialize_dimensions(dimensions, height, width);
				if (not_horizontal_cords(tab, coordinates, dimensions, current)
				&& horizontal_cords(tab, coordinates, dimensions, current))
					valid_dot = 1;
			}
			j++;
		}
		update_variables(&i, &j);
	}
	return (increment_return(valid_dot));
}

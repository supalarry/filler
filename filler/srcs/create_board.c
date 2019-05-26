/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_board.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/19 14:54:51 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/05/19 14:54:52 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "filler_header.h"

/*
** @desc Reads and dismisses line from stdin plotting width of the board
** @desc This results in offset of stdin being at 3rd line
** @param void
** @return void
*/

void		skip_line(void)
{
	char	*line;

	get_next_line(0, &line);
	if (line != NULL)
		free(line);
}

/*
** @desc Store 0 at the end of board and it's copy's end
** @param t_rect *rect_struct - structure storing board, it's copy and size
** @param int i - destination row
** @param int j - destination column
** @return void
*/

static void	null_rectangles_end(t_rect *rect_struct, int i, int j)
{
	rect_struct->rectangle[i][j] = 0;
	rect_struct->rectangle_copy[i][j] = 0;
}

/*
** @desc Copy value from read line to board and it's copy
** @param t_rect *rect - structure storing board, it's copy and size
** @param char cell - character from read line
** @param int i - destination row
** @param int j - destination column
** @return void
*/

static void	fill_rectangles(t_rect *rect, char cell, int i, int j)
{
	rect->rectangle[i][j] = cell;
	rect->rectangle_copy[i][j] = cell;
	if (cell == 'o' || cell == 'x')
	{
		rect->rectangle[i][j] = rect->rectangle[i][j] - 32;
		rect->rectangle_copy[i][j] = rect->rectangle_copy[i][j] - 32;
	}
}

/*
** @desc Set create_board() i, j and k variables to 0
** @param int *i - address of variable to be set to 0
** @param int *j - address of variable to be set to 0
** @param int *k - address of variable to be set to 0
** @return void
*/

static void	initialize_variables_board(int *i, int *j, int *k)
{
	*i = 0;
	*j = 0;
	*k = 0;
}

/*
** @desc Declares, initializes and updates current state of the board
** @param void
** @return char ** as a current board
*/

t_rect		*create_board(char *line_sizes)
{
	int		i;
	int		j;
	int		k;
	char	*line;
	t_rect	*rect_struct;

	initialize_variables_board(&i, &j, &k);
	rect_struct = allocate_rectangle(line_sizes);
	skip_line();
	while (i < rect_struct->height)
	{
		get_next_line(0, &line);
		line = line + 4;
		while (j < rect_struct->width)
		{
			fill_rectangles(rect_struct, line[k], i, j);
			j++;
			k++;
		}
		null_rectangles_end(rect_struct, i, j);
		j = 0;
		k = 0;
		i++;
	}
	return (rect_struct);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_piece.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/19 14:54:59 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/05/19 14:55:01 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "filler_header.h"

/*
** @desc Set create_piece() i, j and k variables to 0
** @param int *i - address of variable to be set to 0
** @param int *j - address of variable to be set to 0
** @param int *k - address of variable to be set to 0
** @return void
*/

static void	initialize_variables_piece(int *i, int *j, int *k)
{
	*i = 0;
	*j = 0;
	*k = 0;
}

/*
** @desc Declares and initializes current piece
** @param void
** @return char ** as a current piece containing shape
*/

t_rect		*create_piece(char *line_sizes)
{
	int		i;
	int		j;
	int		k;
	char	*line;
	t_rect	*rect_struct;

	initialize_variables_piece(&i, &j, &k);
	rect_struct = allocate_rectangle(line_sizes);
	while (i < rect_struct->height)
	{
		get_next_line(0, &line);
		while (j < rect_struct->width)
		{
			rect_struct->rectangle[i][j] = line[k];
			j++;
			k++;
		}
		rect_struct->rectangle[i][j] = 0;
		free(line);
		k = 0;
		j = 0;
		i++;
	}
	rect_struct->shape = NULL;
	return (rect_struct);
}

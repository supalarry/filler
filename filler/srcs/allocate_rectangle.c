/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   allocate_rectangle.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/19 14:54:16 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/05/19 14:54:21 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "filler_header.h"

/*
** @desc Creates structure storing width and height of the board/piece
** @desc Furthermore, allocates memory to hold board's/piece's values
** @desc Also, after reading line increases offset of stdin to 2nd line
** @param void
** @return char ** as a placeholder for current board/current piece
*/

t_rect	*allocate_rectangle(char *line)
{
	int		i;
	t_rect	*rect;

	i = 0;
	rect = (t_rect *)malloc(sizeof(t_rect));
	rect->height = rectangle_height(line);
	rect->width = rectangle_width(line);
	rect->rectangle = (int **)malloc(sizeof(int *) * rect->height + 1);
	rect->rectangle_copy = (int **)malloc(sizeof(int *) * rect->height + 1);
	while (i < rect->height)
	{
		rect->rectangle[i] = (int *)malloc(sizeof(int) * rect->width + 1);
		rect->rectangle_copy[i] = (int *)malloc(sizeof(int) * rect->width + 1);
		i++;
	}
	rect->rectangle[i] = NULL;
	rect->rectangle_copy[i] = NULL;
	return (rect);
}

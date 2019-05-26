/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shape.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/19 14:56:16 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/05/19 14:56:18 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "filler_header.h"

/*
** @desc Allocate enough space for the shape within piece
** @param t_rect *piece - structure storing piece, cut shape and dimensions
** @param t_offset *offsets - stores margins of shape within piece
** @return void
*/

static void	allocate_shape(t_rect *piece, t_offset *offsets)
{
	int		i;
	int		height;
	int		width;

	i = 0;
	height = piece->height - offsets->top - offsets->down + 1;
	width = piece->width - offsets->left - offsets->right + 1;
	piece->shape = (int **)malloc(sizeof(int *) * height);
	while (i < height - 1)
	{
		piece->shape[i] = (int *)malloc(sizeof(int) * width);
		i++;
	}
	piece->shape[i] = NULL;
	piece->shape_height = height - 1;
	piece->shape_width = width - 1;
}

/*
** @desc Launch function to allocate space for shape and fill it's values
** @param t_rect *piece - structure storing piece, cut shape and dimensions
** @param t_offset *offsets - stores margins of shape within piece
** @return void
*/

void		create_shape(t_rect *piece, t_offset *offsets)
{
	int	i;
	int	j;
	int	m;
	int	n;

	allocate_shape(piece, offsets);
	i = offsets->top;
	j = offsets->left;
	m = 0;
	n = 0;
	while (i < piece->height - offsets->down)
	{
		while (j < piece->width - offsets->right)
		{
			piece->shape[m][n] = piece->rectangle[i][j];
			n++;
			j++;
		}
		piece->shape[m][n] = '\0';
		j = offsets->left;
		i++;
		m++;
		n = 0;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   offset.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/19 14:55:41 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/05/19 14:55:42 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "filler_header.h"

/*
** @desc Calculate right offset of a shape within piece
** @param t_rect *rect_struct - structure storing piece and it's dimensions
** @return int as right offset
*/

static int	right_offset(t_rect *rect_struct)
{
	int	i;
	int	j;

	i = 0;
	j = rect_struct->width - 1;
	while (j >= 0)
	{
		while (i < rect_struct->height && rect_struct->rectangle[i][j] == '.')
			i++;
		if (rect_struct->rectangle[i] == '\0')
		{
			j--;
			i = 0;
		}
		else
			break ;
	}
	return (rect_struct->width - j - 1);
}

/*
** @desc Calculate left offset of a shape within piece
** @param t_rect *rect_struct - structure storing piece and it's dimensions
** @return int as left offset
*/

static int	left_offset(t_rect *rect_struct)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < rect_struct->width)
	{
		while (i < rect_struct->height && rect_struct->rectangle[i][j] == '.')
			i++;
		if (rect_struct->rectangle[i] == '\0')
		{
			j++;
			i = 0;
		}
		else
			break ;
	}
	return (j);
}

/*
** @desc Calculate top offset of a shape within piece
** @param t_rect *rect_struct - structure storing piece and it's dimensions
** @return int as top offset
*/

static int	top_offset(t_rect *rect_struct)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (rect_struct->rectangle[i] != '\0')
	{
		while (j < rect_struct->width && rect_struct->rectangle[i][j] == '.')
			j++;
		if (rect_struct->rectangle[i][j] == '\0')
		{
			i++;
			j = 0;
		}
		else
			break ;
	}
	return (i);
}

/*
** @desc Calculate down offset of a shape within piece
** @param t_rect *rect_struct - structure storing piece and it's dimensions
** @return int as bottom offset
*/

static int	down_offset(t_rect *rect_struct)
{
	int	i;
	int	j;

	i = rect_struct->height - 1;
	j = 0;
	while (i >= 0)
	{
		while (rect_struct->rectangle[i][j] == '.')
			j++;
		if (rect_struct->rectangle[i][j] == '\0')
		{
			i--;
			j = 0;
		}
		else
			break ;
	}
	return (rect_struct->height - i - 1);
}

/*
** @desc Launch functions to store left, top, right and down offsets of
** @desc a shape within a piece
** @param t_rect *rect_struct - structure storing piece and it's dimensions
** @return t_offset * as address of structure storing offsets
*/

t_offset	*piece_offset(t_rect *rect_struct)
{
	t_offset	*offsets;

	offsets = (t_offset *)malloc(sizeof(t_offset));
	offsets->left = left_offset(rect_struct);
	offsets->top = top_offset(rect_struct);
	offsets->right = right_offset(rect_struct);
	offsets->down = down_offset(rect_struct);
	return (offsets);
}

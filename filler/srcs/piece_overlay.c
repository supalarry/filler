/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   piece_overlay.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/19 14:55:56 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/05/19 14:55:57 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "filler_header.h"

/*
** @desc Save value for first time and then store it in original source
** @param int *item - address of variable which value is stored or changed
** @return void
*/

static void	storage(int *item)
{
	static int	times;
	static int	coordinates_copy;

	if (item == NULL)
	{
		times = 0;
	}
	else if (times == 0)
	{
		coordinates_copy = *item;
		times++;
	}
	else
		*item = coordinates_copy;
}

/*
** @desc Initialize iteration range for piece_overlay() function
** @param int *max_i - address of variable representing maximum row
** @param int *max_j - address of variable representing maximum columnr
** @param int *c - values used to store current board coordinates
** @param t_rect *piece - structure storing piece, cut shape and dimensions
** @return void
*/

static void	initialize_borders(int *max_i, int *max_j, int *c, t_rect *piece)
{
	*max_i = c[0] + piece->shape_height;
	*max_j = c[1] + piece->shape_width;
}

/*
** @desc Initialize variables for piece_overlay() function
** @param int *i - address of variable representing y axis
** @param int *j - address of variable representing x axis
** @param int *overlays - address of variable storing # of cells shape cover
** @param int *c - values used to store current board coordinates
** @return void
*/

static void	initialize_variables(int *i, int *j, int *overlays, int *c)
{
	*i = 0;
	*j = 0;
	*overlays = 0;
	storage(&c[1]);
}

/*
** @desc Update variables for piece_overlay() function
** @param int *i - address of variable representing y axis
** @param int *j - address of variable representing x axis
** @param int *coordinates - values used to store current board coordinates
** @return void
*/

static void	update_variables(int *i, int *j, int *coordinates)
{
	(*i)++;
	*j = 0;
	coordinates[0]++;
	storage(&coordinates[1]);
}

/*
** @desc Checks if given current coordinates and a shape, shape overlaps
** @desc player's piece only once and no enemy's piece.
** @param t_rect *piece - structure storing piece, cut shape and dimensions
** @param t_rect *board - structure storing board and it's dimensions
** @param int *c - values used to store current board coordinates
** @param t_players *p - structure storing players' numbers and piecess
** @return int 1 if shape overlays one player's piece and no enemy's piece
** @return int 0 if shape overlays more player's pieces and/or enemy's piece
*/

int			piece_overlay(t_rect *piece, t_rect *board, int *c, t_players *p)
{
	int	i;
	int	j;
	int	max_i;
	int	max_j;
	int	overlays;

	storage(NULL);
	initialize_borders(&max_i, &max_j, c, piece);
	initialize_variables(&i, &j, &overlays, c);
	while (c[0] < max_i)
	{
		while (c[1] < max_j)
		{
			if (board->rectangle[c[0]][c[1]] == p->my_piece
			&& piece->shape[i][j] == '*')
				overlays++;
			else if (board->rectangle[c[0]][c[1]] == p->computer_piece
			&& piece->shape[i][j] == '*')
				return (0);
			j++;
			c[1]++;
		}
		update_variables(&i, &j, c);
	}
	return (overlay_return(overlays));
}

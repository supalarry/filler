/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   coordinates.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/19 14:54:42 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/05/19 14:54:46 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "filler_header.h"

/*
** @desc Initialize variables for coordinates function
** @param int *coords - values used to iterate all over the board
** @param int *win_coords - if valid coordinates are found, store here
** @param int *min_sum - stores values from board under shape
** @return void
*/

static void	initialize_variables(int *coords, int *win_coords, int *min_sum)
{
	coords[0] = 0;
	coords[1] = 0;
	win_coords[0] = -100;
	win_coords[1] = -100;
	*min_sum = 999999999;
}

/*
** @desc Copy values from src array to dst array
** @param int *dst - destination array
** @param int *src - source array
** @return void
*/

static void	transfer_array(int *dst, int *src)
{
	dst[0] = src[0];
	dst[1] = src[1];
}

/*
** @desc If valid coordinates were found, print them
** @param int *win - array storing final coordinates for placing piece
** @param t_offset *offsets - stores margins of shape within piece
** @return void
*/

static void	print_coordinates(int *win, t_offset *offsets)
{
	if (win[0] == -100)
		ft_printf("0 0\n");
	else
		ft_printf("%d %d\n", win[0] - offsets->top, win[1] - offsets->left);
}

/*
** @desc Launches functions to find player's piece within certain
** @desc range of shape's dimensions, validate if only one cell
** @desc overlays, choose position closest to enemy and print coordinates
** @param t_rect *piece - structure storing piece, cut shape and dimensions
** @param t_offset *o - stores margins of shape within piece
** @param t_rect *brd - structure storing board and it's dimensions
** @param t_players *p - structure storing players' numbers and pieces
** @return void
*/

void		coordinates(t_rect *piece, t_offset *o, t_rect *brd, t_players *p)
{
	int	coordinates[2];
	int	coordinates_copy[2];
	int	winning_coordinates[2];
	int	smallest_sum;

	initialize_variables(coordinates, winning_coordinates, &smallest_sum);
	while (coordinates[0] < brd->height - piece->shape_height + 1)
	{
		while (coordinates[1] < brd->width - piece->shape_width + 1)
		{
			transfer_array(coordinates_copy, coordinates);
			if (piece_found(piece, brd, coordinates, p)
			&& piece_overlay(piece, brd, coordinates, p)
			&& piece_sum(piece, brd, coordinates_copy) < smallest_sum)
			{
				smallest_sum = piece_sum(piece, brd, coordinates_copy);
				transfer_array(winning_coordinates, coordinates_copy);
			}
			transfer_array(coordinates, coordinates_copy);
			coordinates[1]++;
		}
		coordinates[1] = 0;
		coordinates[0]++;
	}
	print_coordinates(winning_coordinates, o);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/19 14:55:06 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/05/19 14:55:08 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "filler_header.h"

/*
** @desc Given two dimensional char array, free its arrays and pointer itself
** @param char **two_d - two dimensional character array
** @return void
*/

void	free_two_d_char(char **two_d)
{
	int		i;

	i = 0;
	while (two_d[i] != NULL)
	{
		free(two_d[i]);
		i++;
	}
	if (two_d != NULL)
		free(two_d);
}

/*
** @desc Given two dimensional int array, free its arrays and pointer itself
** @param char **two_d - two dimensional integer array
** @return void
*/

void	free_two_d(int **two_d)
{
	int		i;

	i = 0;
	while (two_d[i] != NULL)
	{
		free(two_d[i]);
		i++;
	}
	if (two_d != NULL)
		free(two_d);
}

/*
** @desc Free board, it's copy and structure itself
** @param t_rect *board - structure storing data to be freed
** @return void
*/

void	free_board(t_rect *board)
{
	free_two_d(board->rectangle);
	free_two_d(board->rectangle_copy);
	free(board);
}

/*
** @desc Free piece, it's copy, shape and structure itself
** @param t_rect *piece - structure storing data to be freed
** @return void
*/

void	free_piece(t_rect *piece)
{
	free_two_d(piece->rectangle);
	free_two_d(piece->rectangle_copy);
	free_two_d(piece->shape);
	free(piece);
}

/*
** @desc Launch functions to store board and piece structuree contents
** @param t_rect *board - structure storing board data to be freed
** @param t_rect *piece - structure storing piece data to be freed
** @return void
*/

void	free_launcher(t_rect *board, t_rect *piece, t_offset *offsets)
{
	free_board(board);
	free_piece(piece);
	free(offsets);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/30 14:23:26 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/05/19 14:55:37 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "filler_header.h"

/*
** @desc Replicate shell by executing binaries and bult in commands
** @desc and control and get information about environment
** @param void
** @return int 0 if program ran successfully
*/

int		main(void)
{
	t_rect		*brd;
	t_rect		*piece;
	t_players	*p;
	t_offset	*offsets;
	char		*line;

	p = player_info();
	while (get_next_line(0, &line) > 0)
	{
		if (line != NULL && ft_strncmp(line, "Plateau", 7) == 0)
		{
			brd = create_board(line);
			dots(brd->rectangle_copy, brd->height, brd->width, p->my_piece);
			heat_map(brd, p->computer_piece);
		}
		else if (line != NULL && ft_strncmp(line, "Piece", 5) == 0)
		{
			piece = create_piece(line);
			offsets = piece_offset(piece);
			create_shape(piece, offsets);
			coordinates(piece, offsets, brd, p);
			free_launcher(brd, piece, offsets);
		}
	}
	return (0);
}

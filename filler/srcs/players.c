/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   players.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/19 14:56:04 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/05/19 14:56:06 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "filler_header.h"

/*
** @desc Creates structure storing your and computer's id and pieces (X or O)
** @param void
** @return t_players * as structure storing players' data
*/

t_players	*player_info(void)
{
	char		*line;
	char		**line_items;
	t_players	*players;

	get_next_line(0, &line);
	players = (t_players *)malloc(sizeof(t_players));
	line_items = ft_strsplit(line, ' ');
	if (ft_strcmp("p1", line_items[2]) == 0)
	{
		players->my_number = 1;
		players->my_piece = 'O';
		players->computer_number = 2;
		players->computer_piece = 'X';
	}
	else if (ft_strcmp("p2", line_items[2]) == 0)
	{
		players->my_number = 2;
		players->my_piece = 'X';
		players->computer_number = 1;
		players->computer_piece = 'O';
	}
	free_two_d_char(line_items);
	free(line);
	return (players);
}

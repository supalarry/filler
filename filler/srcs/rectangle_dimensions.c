/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rectangle_dimensions.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/19 14:56:11 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/05/19 14:56:13 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "filler_header.h"

/*
** @desc Extracts height of board/piece from read line
** @param char * line - line containing dimensions of board/piece
** @return int as height of board/piece
*/

int		rectangle_height(char *line)
{
	int		height;
	char	**buffer;

	buffer = ft_strsplit(line, ' ');
	height = ft_atoi(buffer[1]);
	free_two_d_char(buffer);
	return (height);
}

/*
** @desc Extracts width of board/piece from read line
** @param char * line - line containing dimensions of board/piece
** @return int as width of board/piece
*/

int		rectangle_width(char *line)
{
	int		width;
	char	**buffer;

	buffer = ft_strsplit(line, ' ');
	width = ft_atoi(buffer[2]);
	free_two_d_char(buffer);
	return (width);
}

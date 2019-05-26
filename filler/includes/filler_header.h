/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   filler_header.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/19 14:57:58 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/05/19 14:58:00 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_HEADER_H
# define FILLER_HEADER_H
# include "../libft/includes/libft.h"

typedef	struct			s_rect
{
	int					**rectangle;
	int					**rectangle_copy;
	int					**shape;
	int					shape_height;
	int					shape_width;
	int					height;
	int					width;
}						t_rect;

typedef	struct			s_players
{
	int					my_number;
	int					my_piece;
	int					computer_number;
	int					computer_piece;
}						t_players;

typedef	struct			s_offset
{
	int					left;
	int					top;
	int					right;
	int					down;
}						t_offset;

t_rect					*create_board(char *line_sizes);
t_rect					*create_piece(char *line_sizes);
int						rectangle_height(char *line);
int						rectangle_width(char *line);
t_rect					*allocate_rectangle(char *line);
void					free_two_d(int **two_d);
t_players				*player_info(void);
void					heat_map(t_rect *board, char computer_piece);
void					create_shape(t_rect *piece, t_offset *offsets);
t_offset				*piece_offset(t_rect *rect_struct);
void					coordinates(t_rect *piece, t_offset *o,
						t_rect *brd, t_players *p);
int						piece_overlay(t_rect *piece, t_rect *board,
						int *c, t_players *p);
void					ones(int **tab, int height, int width,
						int computer_piece);
int						increment(int **tab, int height, int width,
						int current);
int						piece_found(t_rect *piece, t_rect *board,
						int *coords, t_players *players);
int						piece_sum(t_rect *piece, t_rect *board,
						int *coordinates);
int						not_horizontal_cords(int **tab, int *coords,
						int *dimensions, int current);
int						horizontal_cords(int **tab, int *coordinates,
						int *dimensions, int c);
void					skip_line(void);
void					free_board(t_rect *board);
void					free_piece(t_rect *piece);
void					dots(int **rectangle_copy, int height, int width,
						char my_piece);
void					free_launcher(t_rect *board, t_rect *piece,
						t_offset *offsets);
void					free_two_d_char(char **two_d);
int						increment_return(int valid_dot);
int						overlay_return(int overlays);
#endif

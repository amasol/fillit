/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 12:25:57 by arrudenk          #+#    #+#             */
/*   Updated: 2018/02/23 12:25:58 by arrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


									//убери лишние коментарии, библиотеку, прогляди что лишнне



#ifndef FILLIT_HEADER_H
# define FILLIT_HEADER_H

# define FIELD_SIZE 4
# define NEWLINES(x,y) y = (x / 21 * 4 + (x / 21)) - 1;

//# include <stdio.h>
# include <fcntl.h>
# include "../Libft/libft.h"
# include <stdlib.h>

typedef struct
{
	char	data[FIELD_SIZE][FIELD_SIZE];
	char	alphabet;
	int		w;
	int		h;
}	f_figure4x4;

typedef struct
{
	int		x;
	int		y;
}	t_coord;

typedef struct
{
	char	**field;
	int		size;
}	m_map;
//globals
void			ft_lstrev(t_list **begin_list);
f_figure4x4		*init_figures_field(void);
void			print_figures(f_figure4x4 *field);

//cut_field
f_figure4x4		*cut(f_figure4x4 *field);
//processFile
t_list			*create_figures_list(char **columns, int figures_number);
t_list			*extract_figures_from_buffer(char *buffer,
			    int figures_number);
void			set_zero(int *i, int *x, int *y);
void			set_minus_one(int *c, int *a);

//checkFile
int				checker(char *buffer, int fileLength);
int				check4x4(char *buffer);
int				syntax_ceck(char *buffer, int file_length);
int				wrong_symbol(char c);

//check_figure
int				check_figure(f_figure4x4 *figure);
int				control_sum(f_figure4x4 *figure);
int				pairing_func(int k1, int k2);
//smallestSquare
void			free_map(m_map *map);
m_map			*new_map(int size);
void			print_map(m_map *map);
int				place(f_figure4x4 *figure, m_map *map, int x, int y);
void			set_piece(f_figure4x4 *figure, m_map *map,
				t_coord *coord, char c);
m_map			*solve(t_list *figure_list, int figures_number);
void			*find_figure_size(f_figure4x4 *figure);
void			find_widtht(f_figure4x4 *figure);
void			find_height(f_figure4x4 *figure);
int				get_x_shift(f_figure4x4 *field);
int				get_y_shift(f_figure4x4 *field);
f_figure4x4		*move_by_y(f_figure4x4 *field, char fig);
f_figure4x4		*move_by_x(f_figure4x4 *field, char fig)

t_coord			*coord_new(int x, int y);

#endif //FILLIT_HEADER_H

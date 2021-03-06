/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 12:26:40 by arrudenk          #+#    #+#             */
/*   Updated: 2018/02/23 12:26:42 by arrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			solve_map(m_map *map, t_list *list)
{
	int			x;
	int			y;
	f_figure4x4	*tetri;

	if (list == NULL)
		return (1);
	y = -1;
	tetri = (f_figure4x4 *)(list->content);
	while (++y < map->size - tetri->h + 1)
	{
		x = -1;
		while (++x < map->size - tetri->w + 1)
		{
			if (place(tetri, map, x, y))
			{
				if (solve_map(map, list->next))
					return (1);
				else
					set_piece(tetri, map, coord_new(x, y), '.');   //coord_new --светться красным
			}
		}
	}
	return (0);
}

int			hight_sqrt(int n)
{
	int	size;

	size = 1;
	while (++size * size < n);					//нужно какое то тело функции
	return (size);
}

m_map		*solve(t_list *figure_list, int figures_number)
{
	m_map	*map;
	int		i;
	int		size;

	size = hight_sqrt(figures_number * 4);
	map = new_map(size);
	while (!solve_map(map, figure_list))
	{
		size++;
		free_map(map);
		map = new_map(size);
	}
	return (map);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 12:26:29 by arrudenk          #+#    #+#             */
/*   Updated: 2018/02/23 12:26:30 by arrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_list		*create_figures_list(char **columns, int figures_number)		//сделать 5 переменных
{
	int				x;
	int				y;
	int				c;
	int				i;
	t_list			*figures_list;
	f_figure4x4		*temp;
	int				a;

	set_zero(&i, &x, &y);
	temp = init_figures_field();
	figures_list = ft_memalloc(sizeof(t_list *) * figures_number);
	while (columns[i])
	{
		set_minus_one(&c, &a);
		while (columns[i][++a])
			temp->data[x][++c] = columns[i][a];
		x++;
		if (++i % FIELD_SIZE == 0) // то есть кратное четырем что значит "прошло 4 колонки"
		{
			ft_lstadd(&figures_list, ft_lstnew(temp, sizeof(f_figure4x4)));
			ft_memdel((void *)&temp);
			temp = init_figures_field();
			x = 0;
		}
	}
	ft_lstrev(&figures_list);
	return (figures_list);
}

t_list		*extract_figures_from_buffer(char *buffer, int figures_number)
{
	char		**columns;
	t_list		*figurelist;
	int i;

	i = -1;
	columns = ft_strsplit(buffer, '\n');
	figurelist = create_figures_list(columns, figures_number);
	while (columns[++i])
		ft_strdel(&columns[i]);
	free(columns);
	return (figurelist);
}

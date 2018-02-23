/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 12:26:06 by arrudenk          #+#    #+#             */
/*   Updated: 2018/02/23 12:26:09 by arrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char		*give_file_buff(char *file)
{
	char	*buff;
	int		fd;
	size_t	filelength;

	filelength = 0;
	buff = ft_memalloc(sizeof(char) + 1);
	fd = open(file, O_RDONLY);
	while (read(fd, (void *)buff, 1) > 0)
		filelength++;
	close(fd);
	ft_memdel((void *)&buff);
	fd = open(file, O_RDONLY);
	buff = ft_memalloc(sizeof(char) * filelength + 1);
	read(fd, buff, filelength);
	close(fd);
	return (buff);
}

int			main(int argc, char **argv)			// переделать мейн
{
	(void)argc;
	int		file;
	int		figures_number;
	char	*buff;
	int		file_len;

	figures_number = 0;
	buff = ft_strnew(21);
	file = open(argv[1], O_RDONLY);
	while (read(file, (void *)buff, 21) > 0)
		figures_number++;
	close(file);
	ft_strdel(&buff);
	buff = give_file_buff(argv[1]);
	file_len = figures_number * 21;

	if (checker(buff, file_len))
	{
		t_list *figures_list = extract_figures_from_buffer(buff, figures_number);
		int i;
		int j;
		t_list		*temp;

		temp = figures_list->next;
		i = 0;
		j = 0;
		ft_putchar('\n');
		while (i < figures_number)
		{
			cut(temp->content);
			ft_putnbr(check_figure(temp->content));
			ft_putchar('\n');
			find_figure_size(temp->content);
			print_figures(temp->content);
			temp = temp->next;
			i++;
		}
		m_map *mapa;

		mapa = solve(figures_list->next, figures_number);
		print_map(mapa);
		free_map(mapa);
	}
	return (0);
}

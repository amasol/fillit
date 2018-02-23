/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileChecker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 12:25:40 by arrudenk          #+#    #+#             */
/*   Updated: 2018/02/23 12:25:41 by arrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		wrong_symbol(char c)
{
	if (c != '.' && c != '#' && c != '\n' && c != '\0')
		return (1);
	else
		return (0);
}

int		syntax_ceck(char *buffer, int file_length)
{
	int i;
	int newline;
	int valid_new_lines_score;

	NEWLINES(file_length, valid_new_lines_score);
	i = -1;
	newline = 0;
	while (buffer[++i] != '\0')
	{
		if (buffer[i] == '\n')
			newline++;
		if (wrong_symbol(buffer[i]))
		{
			ft_putstr("wrong symbol ERROR ");
			return (0);
		}
	}
	if (newline != valid_new_lines_score)
	{
		ft_putstr("new line ERROR");
		return (0);
	}
	return (1);
}

int		check4x4(char *buffer)
{
	int		x;
	int		y;
	char	**column;

	column = ft_strsplit(buffer, '\n');
	x = 0;
	y = -1;
	while (column[x + 1])
	{
		while (column[x][++y]);								// в вайле нету тела
		if (y != 4)
		{
			ft_putstr("error");
			while (*column)
				ft_strdel(&*column++);
			return (0);
		}
		y = -1;
		x++;
	}
	while (*column)
		ft_strdel(&*column++);
	return (x < 3 ? 0 : 1);
}

int		checker(char *buffer, int fileLength)				// чеккер нужно будет делать
{
	int		firstCheck;
	int		secondCheck;

	firstCheck = syntax_ceck(buffer, fileLength);

	if (firstCheck){
		ft_putstr("first check: OK");ft_putchar('\n');
		secondCheck = check4x4(buffer);
	}
	else
	{
		ft_putstr("first check: KO");ft_putchar('\n');
		return (0);
	}

	if (secondCheck)
	{
		ft_putstr("secod check: OK");ft_putchar('\n');
	}
	else
	{
		ft_putstr("secod check: KO");ft_putchar('\n');
		return (0);
	}
	return (1);
}

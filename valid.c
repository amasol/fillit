/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 12:30:19 by amasol            #+#    #+#             */
/*   Updated: 2018/02/07 12:30:20 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		valid_termin(char *str)
{
	int count;

	count = 0;
	while (*str)
	{
		if (*str == 35)
		{
			if (*(str + 1) == 35)
				count++;
			if (*(str + 5) == 35)
				count++;
		}
		str++;
	}
	if (count != 3 && count != 4)
		return (1);
	return (0);
}

static int		tretiy_perenos(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n' && str[i + 1] == '\n' && str[i + 2])
			return (1);
		i++;
	}
	return (0);
}

static int		pravilnoe_kolvo(char *str)
{
	int hash;
	int point;
	int n;
	int i;

	hash	= 0;
	point	= 0;
	n 		= 0;
	i 		= 0;

	while (str[i])
	{
		if (str[i] == '#')
			hash++;
		if (str[i] == '.')
			point++;
		if (str[i] == '\n')
			n++;
		i++;
	}
		if (hash != 4 || point != 12 || n != 5)
			return (1);
	return (0);
}

int		lishniy_perenos(char *str)
{
	int i;
	int n;
	int flag;

	i = 0;
	flag = 0;
	n = 4;
	while (str[i] != '\0')
	{
		if (str[i] != '.' && str[i] != '#' && str[i] != '\n')
			return (1);
		if (str[i] == '.' || str[i] == '#')
		{
			n++;
			i++;
		}
		else
			i++;
		if (str[i] == '\n' && (n % 4))
		{
			flag++;
			i++;
		}
	}
	if (flag)
		return (1);
	return (0);
}

int valid(char *str)
{
	// printf("1. %d\n", tretiy_perenos(str));
	// printf("2. %d\n", pravilnoe_kolvo(str));
	// printf("3. %d\n", lishniy_perenos(str));
	// printf("4. %d\n\n", valid_termin(str));

	return (lishniy_perenos(str) + pravilnoe_kolvo(str) + tretiy_perenos(str) + valid_termin(str));
}

int 	check(int s, int i)
{
	if (g_point == i)
	{
		if (s != 20)
		{
			ft_putstr("error\n");
			return (0);
		}
		else
			g_buff[s++] = '\n';
	}
	return (s);
}

void	count(char *str)
{
	int 	fd;
	int 	i;
	int 	s;
	// записать в глобальную переменную результат кол-ва тетр  и (-1)

	i = 0;
	fd = open (str, O_RDONLY);
	while ((s = read(fd, str, 21)) > 0)
		i++;
	close(fd);
	g_point = i - 1;
}

int		main(int argc, char **argv)
{
	int		fd;
	int 	s;
	int 	i;
 
	i = 0;
	argc = argc + 0;
	fd = open(argv[1], O_RDONLY);
	count(argv[1]);
	while ((s = read(fd, g_buff, 21)) > 0)
	{
		if (!(s = check(s, i)))
			return (0);
		g_buff[s] = '\0';          // вызов глобальной переменной с записаными данными и сравнение
		if ((valid(g_buff) == 1))
			return (1);
		naxojdenie(g_buff, i);
//		podst(g_buff, i);
		i++;
	}
	close(fd);
	return (0);
}

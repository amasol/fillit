/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_termin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 18:00:59 by amasol            #+#    #+#             */
/*   Updated: 2017/12/25 16:47:30 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
//#include <stdio.h>

static void		ft_check_one(char *s) // проверка на валидность тетрм и \n
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n' && s[i + 1] == '\n' && s[i + 2] == '\n')
		{
			ft_putstr("error\n");
			exit(1);
		}
		i++;
	}
}

static void		ft_check_two(char *s) // проверка на количество символов в тетриминке
{
	int	tochka;
	int rechetka;
	int n;

//	printf("%s\n", s);
	tochka = 0;
	rechetka = 0;
	n = 0;
	while (*s != '\0')
	{
		if (*s == '.')
			tochka++;
		else if (*s == '#')
			rechetka++;
		else if (*s == '\n')
			n++;
		s++;
	}
//	printf("Tochka %d, Rewetka %d, N %d \n", tochka, rechetka, n);
	if (tochka != 12 || rechetka != 4 || n != 4)
	{
		ft_putstr("error\n");
		exit(1);
	}
}

void	ft_termin(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_check_one(str[i]);
		ft_check_two(str[i]);
		i++;
	}
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_termin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 18:00:59 by amasol            #+#    #+#             */
/*   Updated: 2018/01/06 12:48:54 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
//#include <stdio.h>
//
//функции по валидациии терминок

static void		ft_check_one(char *s) // проверка на валидность \n..не больше одного пробела после тетрм
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
	int rechetk;
	int tochk;
	int n;

	rechetk = 0;
	tochk = 0;
	n = 0;
	while (*s != '\0')
	{
		if (*s == '#')
			rechetk++;
		else if (*s == '.')
			tochk++;
		else if (*s == '\n')
			n++;
		s++;
	}
	if (rechetk != 12 || tochk != 4 || n != 4)
	{
		ft_putstr("error\n");
		exit(1);
	}
}

static void		ft_check_three(char *s) //ф. не дает проходить болье 4 символом до \n
{
	int i;

	i = 0;
	while (*s != '\0' || *s != '\n')
	{
		if (*s == '\n' && i != 4)
		{
			ft_putstr("error\n");
			exit(1);
		}
		else
			i = 0;
		s++;
	}
}

void	ft_termin(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_check_one(str[i]);
//		ft_check_two(str[i]);
//		ft_check_three(str[i]);
		i++;
	}
}

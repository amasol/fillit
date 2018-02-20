/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   podstanovka.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 20:39:31 by amasol            #+#    #+#             */
/*   Updated: 2018/02/17 15:05:44 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	naxojdenie(char *str, int k)
{
	int s;
	int c;
	int j;

	s = 0;
	j = 0;
	while (s < 4)
	{
		c = 0;
		while (*str != '\n')
		{
			if (*str == 35)
			{
				g_x[k][j] = c;
				g_y[k][j++] = s;
			}
			str++;
			c++;
		}
		str++;
		s++;
	}
	printf("%d --- x\n", g_x[0][0]);
	printf("%d --- y\n", g_y[0][0]);          
	printf("%d --- x\n", g_x[0][1]);
	printf("%d --- y\n", g_y[0][1]);
/*	printf("%d --- x\n", g_x[0][2]);
	printf("%d --- y\n", g_y[0][2]);
	printf("%d --- x\n", g_x[0][3]);
	printf("%d --- y\n", g_y[0][3]);*/
}

/*void	podst(char *str, int k)
{
	int x_min;
	int y_min;
	int i;
	int c;
	char **t;

	i = 0;
	c = 0;
	naxojdenie(str, k);
	x_min = g_x[k][0];
	y_min = g_y[k][0];
	while (i < 4)
	{
		if (g_x[k][i++] < x_min)
		 	x_min = g_x[k][i];
	}
	while (c < 4)
	{
		g_x[k][c] = g_x[k][c] - x_min;
		g_y[k][c] = g_y[k][c] - y_min;
		c++;
	}
	printf("%d --- x\n", g_x[0][0]);
	printf("%d --- y\n", g_y[0][0]);          
	printf("%d --- x\n", g_x[0][1]);
	printf("%d --- y\n", g_y[0][1]);
	printf("%d --- x\n", g_x[0][2]);
	printf("%d --- y\n", g_y[0][2]);
	printf("%d --- x\n", g_x[0][3]);
	printf("%d --- y\n", g_y[0][3]);
}
*/


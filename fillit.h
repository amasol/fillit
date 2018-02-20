/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 16:40:21 by amasol            #+#    #+#             */
/*   Updated: 2017/12/25 16:41:13 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef FILLIT_H
#	define FILLIT_H

#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "libft.h"

/*typedef struct s_list
{
}*/

int 	g_x[26][4];
int 	g_y[26][4];
int		g_point;
char	g_buff[22];

//int		mine_read(char **av);
int		valid(char *str);
void	naxojdenie(char *str, int k);
void	podst(char *str, int k);
char	**karta(int k);

#	endif

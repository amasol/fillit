/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   karta.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 20:25:31 by amasol            #+#    #+#             */
/*   Updated: 2018/02/16 20:25:33 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "fillit.h"

static char		*tochki(char *str, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	return (str);
}

char		 	**karta(int k)
{
	int 	i;
	int 	n;
	char	**karta;

	i = 2;
	n = 0;
	while (i * i < 4 * k)		// 4 - так как у нас не больше 4 символов в терминке
		i++;
	if (!(karta = (char **)malloc(sizeof(char *) * (i + 1)))) // выделение памяти под указатели 
		return (NULL);
	karta[i] = 0;
	while (n < i)
	{
		karta[n] = (char *)malloc(sizeof(char) * (i + 1)); // выделение памти уже конкретно под строку
		n++;
	}
	while (karta[n])
	{
		tochki(karta[n], '.', sizeof(char) * 1);
		n++;
	}
	return (karta);
}



// 	printf("YES ---%d\n", k);

// использовать karta, заполнить '.' и виделить память (sizeof(char) * 1)
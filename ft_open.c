/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 14:02:35 by amasol            #+#    #+#             */
/*   Updated: 2018/01/04 14:02:44 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_check_one(char *s)
{
	int i;

	i = 0;
	while (s* != '\0')
	{
		if (s[i] == '\n' && s[i + 1] == '\n' && s[i + 2] == '\n')
		{
			ft_putstr("error\n");
			exit(1);
		}
	}
}

char			open(char *str)
{
	int		fd;
	char 	*str;
	size_t	schet;

	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		ft_putstr("errot\n");
		exit(1);
	}
	str = ft_memalloc(sizeof(char *) * (550)); // ставить после (char *) или не ставить 
	schet = read(fd, str, 550);
	if (read < 20 || read > 545)
	{
		ft_putstr("error\n");
		exit(1);
	}
	close(fd);
	return (str); 
}

